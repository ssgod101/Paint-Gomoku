/*
File Name: ProgramManager.hpp
Author: Bijan Khajavi
Date Last Modified: Feb 28, 2019
Purpose:
Defines and implements the inner and outer facade to
handle operations related to console input and output.
*/

#include <Windows.h>
#undef min

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

#pragma region XError

/* ErrorDescription */
string ErrorDescription(DWORD dwMessageID) {
	char* msg;
	auto c = FormatMessageA(
		/* flags */			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_MAX_WIDTH_MASK,
		/* source*/			NULL,
		/* message ID */	dwMessageID,
		/* language */		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		/* buffer */		(LPSTR)&msg,
		/* size */			0,
		/* args */			NULL
	);

	string strMsg = (c == 0)
		? "unknown"
		: msg;
	LocalFree(msg);
	return strMsg;
}


/* Console error exception class. */
class XError {
public:
	using id_type = decltype(GetLastError());
	using file_type = char const *;
	using string_type = std::string;
private:
	id_type code_;
	int	line_;
	file_type file_;
public:
	XError(int line, file_type file) : code_(GetLastError()), line_(line), file_(file) {}
	auto code() const -> id_type { return code_; }
	auto line() const -> int { return line_; }
	auto file() const -> file_type { return file_; }

	string_type msg() const {
		ostringstream oss;
		oss << "Error: " << code() << "\n";
		oss << ErrorDescription(code()) << "\n";
		oss << "In: " << file() << "\n";
		oss << "Line: " << line() << "\n";
		return oss.str();
	}
};

/* Console error exception throw helper macro. */
#define THROW_IF_CONSOLE_ERROR(res) if(!res) throw XError(__LINE__,__FILE__)
#define THROW_CONSOLE_ERROR() throw XError(__LINE__,__FILE__)

#pragma endregion

//Colours
//A list of every possible combination of colours for WinAPI.
//Not all values are used and are just there for future reference.
enum ConsoleColor {
	FG_BLACK = 0,
	FG_DARKBLUE = FOREGROUND_BLUE,
	FG_DARKGREEN = FOREGROUND_GREEN,
	FG_DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
	FG_DARKRED = FOREGROUND_RED,
	FG_DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	FG_DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
	FG_DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	FG_GRAY = FOREGROUND_INTENSITY,
	FG_BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
	FG_GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	FG_CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	FG_RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	FG_MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
	FG_YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	FG_WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	BG_BLACK = 0,
	BG_DARKBLUE = BACKGROUND_BLUE,
	BG_DARKGREEN = BACKGROUND_GREEN,
	BG_DARKCYAN = BACKGROUND_GREEN | BACKGROUND_BLUE,
	BG_DARKRED = BACKGROUND_RED,
	BG_DARKMAGENTA = BACKGROUND_RED | BACKGROUND_BLUE,
	BG_DARKYELLOW = BACKGROUND_RED | BACKGROUND_GREEN,
	BG_DARKGRAY = BACKGROUND_INTENSITY,
	BG_GRAY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	BG_BLUE = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
	BG_GREEN = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
	BG_CYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
	BG_RED = BACKGROUND_INTENSITY | BACKGROUND_RED,
	BG_MAGENTA = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
	BG_YELLOW = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
	BG_WHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE
};

//---------------------------------------------------
//Inner facade class that can only be accessed by ProgramManager
class WindowManager {
	//=======================================================
	// Console System
	//=======================================================
#pragma region ConsoleSystem

	// System Data
	HANDLE hConsoleInput, hConsoleOutput;
	CONSOLE_SCREEN_BUFFER_INFO	originalCSBI;
	CONSOLE_CURSOR_INFO			originalCCI;
	vector<CHAR_INFO>			originalBuffer;
	COORD						originalBufferCoord;
	DWORD						originalConsoleMode;
	WORD						currentConsoleWidth = 0;
	vector<char>                originalTitle;
#pragma endregion

	//=======================================================
	// Application
	//=======================================================

	// Window Layout
#pragma region WindowLayout
	WORD WINDOW_WIDTH = 0;
	WORD WINDOW_HEIGHT = 0;
#pragma endregion

#pragma region ApplicationData
	// Application data
	static bool applicationQuitting;
	static DWORD terminationEventIdx;
	static bool done;
#pragma endregion

#pragma region EventHandlers

	//function pointers to be called when an event occurs.
	function<void(KEY_EVENT_RECORD const&)> keyEvent;
	function<void(MOUSE_EVENT_RECORD const&)> mouseEvent;

	// Control Event Handler
	static BOOL CtrlHandler(DWORD ctrlType) {
		if (ctrlType <= CTRL_CLOSE_EVENT) {
			done = true;
			terminationEventIdx = ctrlType;
			applicationQuitting = true;
			return TRUE;
		}

		return FALSE;
	}

#pragma endregion // EventHandlers

private:
	friend class ProgramManager;
	void displayNotification(string message,string title,WORD flags) {
		MessageBoxA(NULL,message.c_str(),title.c_str(),flags);
	}
	void saveTitle() {
		originalTitle.resize(64 * 1024);
		originalTitle.resize(size_t(GetConsoleTitleA(originalTitle.data(), (DWORD)originalTitle.size())) + 1);
		originalTitle.shrink_to_fit();
	}
	void setTitle(string title) {
		SetConsoleTitleA(title.c_str());
	}
	void saveConsoleState() {
		// Get the old window/buffer size
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &originalCSBI));

		// Save the desktop
		originalBuffer.resize(size_t(originalCSBI.dwSize.X)*originalCSBI.dwSize.Y);
		originalBufferCoord = COORD{ 0 };
		SMALL_RECT bufferRect{ 0 };
		bufferRect.Right = originalCSBI.dwSize.X - 1;
		bufferRect.Bottom = originalCSBI.dwSize.Y - 1;
		THROW_IF_CONSOLE_ERROR(ReadConsoleOutputA(hConsoleOutput, originalBuffer.data(), originalCSBI.dwSize, originalBufferCoord, &bufferRect));

		// Save the cursor
		THROW_IF_CONSOLE_ERROR(GetConsoleCursorInfo(hConsoleOutput, &originalCCI));

		THROW_IF_CONSOLE_ERROR(GetConsoleMode(hConsoleInput, &originalConsoleMode));
	}
	//Accepts both keyboard and mouse input so that it can be reused with any future application.
	bool setupConsoleMode() {
		DWORD consoleMode = ENABLE_WINDOW_INPUT | ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT;
		consoleMode |= ENABLE_EXTENDED_FLAGS;
		if (!SetConsoleMode(hConsoleInput, consoleMode)) {
			cerr << "\nERROR: could not set console mode.\n";
			return false;
		}
		return true;
	}
	int restoreWindow() {
		// Restore the original settings/size
		SMALL_RECT sr{ 0 };
		THROW_IF_CONSOLE_ERROR(SetConsoleWindowInfo(hConsoleOutput, TRUE, &sr));
		THROW_IF_CONSOLE_ERROR(SetConsoleScreenBufferSize(hConsoleOutput, originalCSBI.dwSize));
		THROW_IF_CONSOLE_ERROR(SetConsoleWindowInfo(hConsoleOutput, TRUE, &originalCSBI.srWindow));


		// Restore the desktop contents
		SMALL_RECT bufferRect{ 0 };
		bufferRect.Right = originalCSBI.dwSize.X - 1;
		bufferRect.Bottom = originalCSBI.dwSize.Y - 1;
		THROW_IF_CONSOLE_ERROR(WriteConsoleOutputA(hConsoleOutput, originalBuffer.data(), originalCSBI.dwSize, originalBufferCoord, &bufferRect));
		SetConsoleTitleA(originalTitle.data());

		// Restore the cursor
		THROW_IF_CONSOLE_ERROR(SetConsoleCursorInfo(hConsoleOutput, &originalCCI));
		THROW_IF_CONSOLE_ERROR(SetConsoleCursorPosition(hConsoleOutput, originalCSBI.dwCursorPosition));

		// Restore console mode
		if (!SetConsoleMode(hConsoleInput, originalConsoleMode)) {
			cerr << "\nERROR: could not restore original console mode.\n";
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
	void resizeWindowToBuffer(SHORT x, SHORT y) {
		WINDOW_WIDTH = x;
		WINDOW_HEIGHT = y;

		SMALL_RECT sr{ 0 };
		THROW_IF_CONSOLE_ERROR(SetConsoleWindowInfo(hConsoleOutput, TRUE, &sr));

		COORD bufferSize;
		bufferSize.X = WINDOW_WIDTH;
		bufferSize.Y = WINDOW_HEIGHT;
		THROW_IF_CONSOLE_ERROR(SetConsoleScreenBufferSize(hConsoleOutput, bufferSize));

		CONSOLE_SCREEN_BUFFER_INFO sbi;
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &sbi));

		sr.Top = sr.Left = 0;
		WINDOW_WIDTH = std::min((SHORT)WINDOW_WIDTH, sbi.dwMaximumWindowSize.X);
		WINDOW_HEIGHT = std::min((SHORT)WINDOW_HEIGHT, sbi.dwMaximumWindowSize.Y);
		sr.Right = WINDOW_WIDTH - 1;
		sr.Bottom = WINDOW_HEIGHT - 1;

		THROW_IF_CONSOLE_ERROR(SetConsoleWindowInfo(hConsoleOutput, TRUE, &sr));
		currentConsoleWidth = sr.Right - sr.Left + 1;
	}
	void setCursorVisibility(bool visible) {
		auto newCCI = originalCCI;
		if (visible) { newCCI.bVisible = TRUE; }
		else { newCCI.bVisible = FALSE; }
		THROW_IF_CONSOLE_ERROR(SetConsoleCursorInfo(hConsoleOutput, &newCCI));
	}

	//Handles input for any application that uses this library.
	//Only needs 2 function pointers to be sent from the application to handle keyboard and mouse input respectively.
	//The function pointers are received from the outer facade (ProgramManager).
	void waitForInput() {
		vector<INPUT_RECORD> inBuffer(128);
		while (!done) {
			DWORD numEvents;
			if (!ReadConsoleInput(hConsoleInput, inBuffer.data(), (DWORD)inBuffer.size(), &numEvents)) {
				cerr << "Failed to read console input\n";
				break;
			}

			for (size_t iEvent = 0; iEvent < numEvents; ++iEvent) {
				switch (inBuffer[iEvent].EventType) {
				case KEY_EVENT:
					keyEvent(inBuffer[iEvent].Event.KeyEvent);
					break;
				case MOUSE_EVENT:
					mouseEvent(inBuffer[iEvent].Event.MouseEvent);
					break;
				}
			}
		}
	}

	//Writes to a single buffer.
	void paintSingleBuffer(char character, WORD color, SHORT x, SHORT y) {
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &csbi));

		COORD loc;
		loc.X = x;
		loc.Y = y;
		DWORD nCharsWritten;
		THROW_IF_CONSOLE_ERROR(WriteConsoleOutputCharacterA(hConsoleOutput, &character, 1, loc, &nCharsWritten));
		THROW_IF_CONSOLE_ERROR(WriteConsoleOutputAttribute(hConsoleOutput, &color, 1, loc, &nCharsWritten));
	}

	void paintLine(string& s, vector<WORD> const& attributes, SHORT x, SHORT y) {
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &csbi));

		COORD loc;
		loc.X = x;
		loc.Y = y;
		DWORD nCharsWritten;
		DWORD nToWrite = DWORD(min(s.size(), std::size_t(currentConsoleWidth - x)));
		THROW_IF_CONSOLE_ERROR(WriteConsoleOutputCharacterA(hConsoleOutput, s.c_str(), nToWrite, loc, &nCharsWritten));
		THROW_IF_CONSOLE_ERROR(WriteConsoleOutputAttribute(hConsoleOutput, attributes.data(), nToWrite, loc, &nCharsWritten));
	}

	//Fills the entire screen with a char and a color.
	void fillEntireScreen(char character, WORD color) {
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &csbi));

		DWORD charsWritten;
		DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
		COORD cursorHomeCoord{ 0, 0 };
		THROW_IF_CONSOLE_ERROR(FillConsoleOutputCharacterA(hConsoleOutput, character, consoleSize, cursorHomeCoord, &charsWritten));
		THROW_IF_CONSOLE_ERROR(FillConsoleOutputAttribute(hConsoleOutput, color, consoleSize, cursorHomeCoord, &charsWritten));
	}

	void fillBox(char character, WORD color, SHORT xSize,SHORT xStart, SHORT ySize,SHORT yStart) {
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &csbi));

		DWORD consoleSize = xSize * ySize;
		COORD cursorHomeCoord = COORD{xStart,yStart};
		DWORD charsWritten;
		THROW_IF_CONSOLE_ERROR(FillConsoleOutputCharacterA(hConsoleOutput,' ',consoleSize,cursorHomeCoord,&charsWritten));
		THROW_IF_CONSOLE_ERROR(FillConsoleOutputAttribute(hConsoleOutput,color,consoleSize,cursorHomeCoord,&charsWritten));
	}
	void UpdateCursorInfo(DWORD num,DWORD val) {
		BOOL value;
		if (val == 1) { value = TRUE; }
		else { value = FALSE; }
		CONSOLE_CURSOR_INFO cci{ num, value };
		THROW_IF_CONSOLE_ERROR(SetConsoleCursorInfo(hConsoleOutput, &cci));
	}
	void UpdateCursorPosition(COORD loc) {
		THROW_IF_CONSOLE_ERROR(SetConsoleCursorPosition(hConsoleOutput, loc));
	}
	bool setupControlHandler() {
		// Install a control handler to trap ^C
		if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE)) {
			cout << "Terminate program with Ctrl-C\n";
			return true;
		}
		else {
			cerr << "ERROR: failed to install control handler." << endl;
			return false;//EXIT_FAILURE;
		}
	}
	WindowManager() {
		hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		applicationQuitting = false;
		terminationEventIdx = -1;
		done = false;
	}
	~WindowManager() {}
};


//---------------------------------------------------
//Outer facade class that is exposed to the application.
class ProgramManager
{
	WindowManager window;
	static ProgramManager *Pgrmngr;
public:
	//General and default settings that the application should not have to worry about.
	bool setupConsole(string title, WORD x, WORD y) {
		bool noErrors = true;
		window.saveTitle();
		window.setTitle(title);
		window.saveConsoleState();
		window.resizeWindowToBuffer(x, y);
		if (!window.setupControlHandler()) { noErrors = false; }
		if (!window.setupConsoleMode()) { noErrors = false; }
		window.setCursorVisibility(false);
		return noErrors;
	}
	//MessageBox with a simpler interface.
	void displayNotification(string message, string title, WORD flags) {
		window.displayNotification(message,title,flags);
	}
	void setTitle(string title) {
		window.setTitle(title);
	}
	void paintAt(char character, WORD color, SHORT x, SHORT y) {
		window.paintSingleBuffer(character, color, x, y);
	}
	void paintLine(string s, vector<WORD> attributes, SHORT x, SHORT y) {
		window.paintLine(s,attributes,x,y);
	}
	void paintLine(string s, WORD color, SHORT x, SHORT y) {
		window.paintLine(s, vector<WORD>(s.size(), color), x, y);
	}
	void paintAll(char character, WORD color) {
		window.fillEntireScreen(character, color);
	}
	void paintArea(char character,WORD color,SHORT xSz,SHORT xSt,SHORT ySz,SHORT ySt) {
		window.fillBox(character,color,xSz,xSt,ySz,ySt);
	}
	void editCursorInfo(int num, int val) {
		window.UpdateCursorInfo(num,val);
	}
	void editCursorPosition(COORD loc) {
		window.UpdateCursorPosition(loc);
	}
	//sends the function pointers to the inner facade from the application,
	//then calls the function in the inner class to handle them.
	void waitForInput(function<void(KEY_EVENT_RECORD const&)> k, function<void(MOUSE_EVENT_RECORD const&)> m) {
		window.keyEvent = k;
		window.mouseEvent = m;
		window.waitForInput();
	}
	ProgramManager() {
		if (Pgrmngr) {
			throw std::logic_error("Error: ProgramManager already initialized!");
		}
		Pgrmngr = this;
	}
	~ProgramManager() {
		window.restoreWindow();
	}
};

bool WindowManager::applicationQuitting = false;
DWORD WindowManager::terminationEventIdx = -1;
bool WindowManager::done = false;
ProgramManager* ProgramManager::Pgrmngr = nullptr;

