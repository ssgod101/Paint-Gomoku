#pragma once

#include <Windows.h>
#include "interfaces.hpp"

class PlaceDownCommand;

class PlayerViewData {
public:
	//Draw Data
	string topl = { char(218),char(196),char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(191) };
	string emptyl = { char(179),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(179) };
	string playerViewColo = "                __  __  __  __  __  __                            __  __  __  __  __  __                           ";//Exactly 115
	string playerViewInfo = "              Player 1: _______________    |Update|             Player 2: _______________    |Update|              "; //Must Be exectly 115 characters
	int const StatusBarInfoY = 1;
	int const chooseColorInfoY = 2;
	int const PlayerNameInfoY = 3;
	//Game Info
	string CurrentWinner = "";

	//PlayerPallete
	//Order = Red, Green, Blue, Cyan, Yellow, Magenta
	SHORT Player1PalleteStartx = 17;
	SHORT Player2PalleteStartx = 67;
	SHORT PalleteLength = 22;
	string PlayerPalleteString = "                      ";
	vector<WORD> PalleteColors = {BG_RED,BG_RED,BG_WHITE,BG_WHITE,BG_GREEN,BG_GREEN,BG_WHITE,BG_WHITE,BG_BLUE,BG_BLUE,BG_WHITE,BG_WHITE,BG_CYAN,BG_CYAN,BG_WHITE,BG_WHITE,BG_YELLOW,BG_YELLOW,BG_WHITE,BG_WHITE,BG_MAGENTA,BG_MAGENTA };

	//Player1TextBox Info
	WORD Player1TextBox_STARTx = 25;
	WORD Player1TextBox_STARTy = PlayerNameInfoY;
	WORD Player1TextBox_SIZE = 15;
	bool Player1TextBox_isFocused = false;
	string Player1TextBox_Text;
	string::size_type Player1TextBox_CursorPos = 0;
	decltype(Player1TextBox_CursorPos) Player1TextBox_Aperture = 0;

	//Player2TextBox Info
	WORD Player2TextBox_STARTx = 75;
	WORD Player2TextBox_STARTy = PlayerNameInfoY;
	WORD Player2TextBox_SIZE = 15;
	bool Player2TextBox_isFocused = false;
	string Player2TextBox_Text;
	string::size_type Player2TextBox_CursorPos = 0;
	decltype(Player2TextBox_CursorPos) Player2TextBox_Aperture = 0;

	//Player 1 Update Button Info
	WORD Player1UpdateButton_STARTy = PlayerNameInfoY;
	WORD Player1UpdateButton_STARTx = 44;
	WORD Player1UpdateButton_END = 51;

	//Player 2 Update Button Info
	WORD Player2UpdateButton_STARTy = PlayerNameInfoY;
	WORD Player2UpdateButton_STARTx = 94;
	WORD Player2UpdateButton_END = 101;
};

class ScoreViewData {
public:
	//Draw Data
	string topl = { char(195),char(196),char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196) ,char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(180) };
	string emptyl = { char(179),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),'|',char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(179) };
	string ScoreViewInfo = "                                                                                                                   ";//Exactly 115
	SHORT ScoreViewPlayerPeicesY = 5;
	SHORT ScoreViewPlayerInfoY = 6;
	SHORT ScoreViewPlayerScore = 7;
	//Need to draw design on how ScoreView is displayed.
	//Most likely use variables below.

	//Possible colors: red,green,blue,cyan,yellow,magenta.

	//changes to these variables done through command pattern

	//Player Data
	string Player1Name = "Player 1";
	int Player1NumberOfWins = 0;
	WORD Player1TileColor = BG_RED;
	int Player1PeicesPlaced = 0;

	string Player2Name = "Player 2";
	int Player2NumberOfWins = 0;
	WORD Player2TileColor = BG_BLUE;
	int Player2PeicesPlaced = 0;
};

class MoveListViewData {
public:
	//┌────┐
	//│Undo│
	//└────┘
	string buttonTop = {char(218),char(196),char(196),char(196),char(196),char(191)};
	string buttonMid = {char(179),'U','n','d','o',char(179)};
	string buttonBot = {char(192),char(196),char(196),char(196),char(196),char(217)};
	string emptyl = "                                     ";
	SHORT buttonSize = 6;
	SHORT buttonStartx = 110;
	SHORT MoveListStartX = 78;
	SHORT MoveListMaxX = 115;//size = 37 txtSize = 12 //namesize = 25
	SHORT MoveListMinY = 9;
	SHORT MoveListMaxY = 41;
	SHORT MoveListTopY = 43;
	SHORT MoveListShowLimit = 32;
	vector<PlaceDownCommand> allMoves;
	//vector<PlaceDownCommand> allMovesReversed() {}
	MoveListViewData() { /*allMoves = {};*/ }
};

//stores the information that is needed for a single cell in the grid.
class GomokuCell {
public:
	//0 = empty
	//1 = player 1
	//2 = player 2
	int cellState = 0;
	COORD location;
	COORD cells[3];
	GomokuCell(SHORT x, SHORT y) {
		location.X = x;
		location.Y = y;
		cells[0] = location;
		cells[1] = location;
		cells[2] = location;
		cells[0].X -= 1;
		cells[2].X += 1;
		cellState = 0;
	}
	GomokuCell() {}
};

// Contains data used to draw the grid, as well as any global variables
// that are used throughout the application. 
class GomokuGridData {
public:
	//false = player 1
	//true = player 2
	GomokuCell gridData[19][19];
	string GetLocationString(int x,int y) {
		return string(1,static_cast<char>('A' + x)) + ":" + to_string(y+1);
	}
	string topl = { char(195),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(194),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(180) };
	string midl = { char(195),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(197),char(196),char(196),char(196),char(180),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(179) };
	string emptyl = { char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(179),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(179) };
	string bottoml = { char(192),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(193),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(196),char(217) };
};

class GomokuModel : public Subject {
public:
	GomokuGridData gomokuGrid;
	PlayerViewData playerViewData;
	ScoreViewData scoreViewData;
	MoveListViewData moveListViewData;
	bool setup = false;
	bool updatePeices = false;
	bool updateTitle = false;
	bool updateTextBox = false;
	bool updateMoveList = false;
	bool showStatusMsg = false;
	//bool statusLock = false;

	//WORD PlayerView_WIDTH = 77;// + MoveListView_WIDTH;
	WORD PlayerView_HEIGHT = 4;//
	WORD PlayerView_STARTy = 0;//

	WORD ScoreView_HEIGHT = 4;//
	//WORD ScoreView_WIDTH = PlayerView_WIDTH;
	WORD ScoreView_STARTy = PlayerView_HEIGHT + PlayerView_STARTy;//

	WORD GridView_WIDTH = 77;
	WORD GridView_HEIGHT = 39;
	WORD GridView_STARTy = ScoreView_STARTy + ScoreView_HEIGHT;

	WORD MoveListView_WIDTH = 40;
	WORD MoveListView_HEIGHT = GridView_HEIGHT;
	WORD MoveListView_STARTx = GridView_WIDTH;
	WORD MoveListView_STARTy = MoveListView_STARTy;

	WORD const WINDOW_WIDTH = GridView_WIDTH + MoveListView_WIDTH; // = (number of columns * 4) + 1
	WORD const WINDOW_HEIGHT = GridView_STARTy + GridView_HEIGHT;// + PlayerView_HEIGHT + ScoreView_HEIGHT; // = (number of rows * 2) + 1

	string WINDOW_TITLE = "Bijan Khajavi's Gomoku";
	string statusMsg = "";
	string WinnerText = "";
	bool playerTurn = false;
	bool gameOver = false;
	void ResetGame() {
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				gomokuGrid.gridData[i][j].cellState = 0;
			}
		}
		moveListViewData.allMoves.clear();
		//WINDOW_TITLE = "Gomoku - Player 1's Turn";
		playerTurn = false;
		gameOver = false;
		updateMoveList = true;
		updatePeices = true;
		showStatusMsg = true;
		//statusLock = false;
		statusMsg = "";
		WinnerText = "";
		//updateTitle = true;
		notify();
	}
	void AddCommand(PlaceDownCommand* cmd) {
		moveListViewData.allMoves.push_back(*cmd);
		updateMoveList = true;
		notify();
	}
	void RemoveLastCommand() {
		if(moveListViewData.allMoves.size() > 0){ moveListViewData.allMoves.pop_back(); }
		updateMoveList = true;
		notify();
	}
	void UpdateScore(string name, int player, int val) {
		if (player == 1) {
			if (name != "") {
				scoreViewData.Player1Name = name;
				scoreViewData.Player1NumberOfWins = 0;
				scoreViewData.Player1PeicesPlaced = 0;
				playerViewData.Player1TextBox_Text = "";
				updateTextBox = true;
				updateMoveList = true;
			}
			if (val > 0) { scoreViewData.Player1NumberOfWins += val; }
			else { scoreViewData.Player1NumberOfWins = 0; }
		}
		else {
			if (name != "") {
				scoreViewData.Player2Name = name;
				scoreViewData.Player2NumberOfWins = 0;
				scoreViewData.Player2PeicesPlaced = 0;
				playerViewData.Player2TextBox_Text = "";
				updateTextBox = true;
				updateMoveList = true;
			}
			if (val > 0) { scoreViewData.Player2NumberOfWins += val; }
			else { scoreViewData.Player2NumberOfWins = 0; }
		}
		notify();
	}
	void UpdateColor(int player, WORD color) {
		if (player == 1) {
			scoreViewData.Player1TileColor = color;
		}
		else {
			scoreViewData.Player2TileColor = color;
		}
		updateMoveList = true;
		updatePeices = true;
		notify();
	}
	void AddPeice(int state,int x,int y, PlaceDownCommand* command){
		if (gomokuGrid.gridData[y][x].cellState != state && state > 0) {
			moveListViewData.allMoves.push_back(*command);
			gomokuGrid.gridData[y][x].cellState = state;
			if (state == 1) { ++scoreViewData.Player1PeicesPlaced; playerTurn = true; }
			if (state == 2) { ++scoreViewData.Player2PeicesPlaced; playerTurn = false; }
			updatePeices = true;
			updateMoveList = true;
			notify();
		}
	}
	void RemoveLastPeice(int x,int y) {
		if (moveListViewData.allMoves.size() > 0) {
			gomokuGrid.gridData[y][x].cellState = 0;
			moveListViewData.allMoves.pop_back();
			if (playerTurn) { scoreViewData.Player1PeicesPlaced--; }
			else { scoreViewData.Player2PeicesPlaced--; }
			updateMoveList = true;
			updatePeices = true;
			playerTurn = !playerTurn;
			notify();
		}
	}
	void SetStatus(string status, bool winner) {
		if (winner) {WinnerText = status;}
		statusMsg = status;
		showStatusMsg = true;
		notify();
	}
	void SetTitle(string title) {
		WINDOW_TITLE = title;
		updateTitle = true;
		notify();
	}
	void run() {
		setup = true;
		notify();
	}
	GomokuModel* GetInstance() { return this; }
	GomokuModel() {}
	~GomokuModel() {}
};

class ResetGameCommand : public Command {
	GomokuModel* gm_;
public:
	ResetGameCommand(GomokuModel* gm) :gm_(gm) {}
	void execute() override {
		gm_->ResetGame();
	}
	~ResetGameCommand() {}
	string Action() override {
		return "Started a new game!";
	}
};

class PlaceDownCommand : public Command {
	GomokuModel* gm_;
public:
	int originalState;
	int state;
	int xLocation;
	int yLocation;
	PlaceDownCommand(GomokuModel* gm, int state, int x, int y) :gm_(gm), state(state), xLocation(x), yLocation(y) {
		originalState = gm_->gomokuGrid.gridData[y][x].cellState;
	}
	void execute() override {
		gm_->AddPeice(state,xLocation,yLocation,this);
		//gm_->SetState(state, xLocation, yLocation);
	}
	void undo() override {
		gm_->RemoveLastPeice(xLocation,yLocation);
		//gm_->SetState(originalState, xLocation, yLocation);
	}
	string Action() override {
		//if (gm_ != nullptr) {
			string loc = gm_->gomokuGrid.GetLocationString(xLocation,yLocation);
			string name = state == 1 ? gm_->scoreViewData.Player1Name : gm_->scoreViewData.Player2Name;
			return name + " placed " + loc;
		//}
		return "";
	}
	~PlaceDownCommand() { /*gm_ = nullptr; */}
};

//class AddToListCommand : public Command {
//	GomokuModel* gm_;
//	PlaceDownCommand& command;
//public:
//	AddToListCommand(GomokuModel* gm,PlaceDownCommand& cmd):gm_(gm),command(cmd) {}
//	void execute() override {
//		gm_->AddCommand(&command);
//	}
//	string Action() override { return ""; }
//};
//
//class RemoveFromListCommand : public Command {
//	GomokuModel* gm_;
//public:
//	RemoveFromListCommand(GomokuModel* gm) :gm_(gm) {}
//	void execute() override {
//		gm_->RemoveLastCommand();
//	}
//	string Action() override { return ""; }
//};

class ChangeTitleCommand : public Command {
	GomokuModel* gm_;
	string title;
public:
	ChangeTitleCommand(GomokuModel* gm, string t) :gm_(gm), title(t) {}
	void execute() override {
		gm_->SetTitle(title);
	}
	string Action() override {
		return "Changed title to "+title;
	}
};

class UpdateScoreCommand : public Command {
	GomokuModel* gm_;
	string NewName;
	int player;
	int value;
public:
	UpdateScoreCommand(GomokuModel* gm, string name, int p, int v) :gm_(gm), player(p), value(v), NewName(name) {}
	void execute() override {
		gm_->UpdateScore(NewName, player, value);
	}
	string Action() override {
		return "";
	}
};

class UpdateColorCommand : public Command {
	GomokuModel* gm_;
	int player;
	WORD color;
public:
	UpdateColorCommand(GomokuModel* gm, int p, WORD c) :gm_(gm), player(p), color(c) {}
	void execute() override {
		gm_->UpdateColor(player, color);
	}
	string Action() override {
		return "";
	}
};

class SetStatusCommand : public Command {
	GomokuModel* gm_;
	string text;
	bool isWinner;
public:
	SetStatusCommand(GomokuModel* gm,string txt,bool win):gm_(gm),text(txt),isWinner(win) {}
	void execute() override {
		gm_->SetStatus(text,isWinner);
	}
	string Action() override {
		return "";
	}
};