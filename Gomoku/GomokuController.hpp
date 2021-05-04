#pragma once
#undef min

#include <ProgramManager.hpp>
#include "GomokuView.hpp"
#include "GomokuModel.hpp"


#pragma region GokokuGridDesign
//Basic Gomoku Layout:
//-------------------
// │ = 179
// ┤ = 180
// ┐ = 191
// └ = 192
// ┴ = 193
// ┬ = 194
// ├ = 195
// ─ = 196
// ┼ = 197
// ┘ = 217
// ┌ = 218

//x:77 y:39

//Used to design the grid before implementing it.
//┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
//│   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
#pragma endregion


static GomokuModel* gm;
class GomokuController : public Observer {
	GomokuModel& gmLocal;
	static ProgramManager program;
	static GridView gridView;
	static PlayerView playerView;
	static ScoreView scoreView;
	static MoveListView moveListView;

	//Function used to handle keyboard input for GomokuApp.
	static void ProcessKeyEvent(KEY_EVENT_RECORD const&ker) {
		if (ker.bKeyDown) {
#pragma region Player1TextBoxInput
			if (gm->playerViewData.Player1TextBox_isFocused) {
				switch (ker.wVirtualKeyCode) {
				case VK_BACK:
					if (0 < gm->playerViewData.Player1TextBox_CursorPos && gm->playerViewData.Player1TextBox_CursorPos <= gm->playerViewData.Player1TextBox_Text.size()) {
						--gm->playerViewData.Player1TextBox_CursorPos;
						gm->playerViewData.Player1TextBox_Text.erase(gm->playerViewData.Player1TextBox_CursorPos,1);
					}
					break;
				case VK_DELETE:
					if (0 < gm->playerViewData.Player1TextBox_CursorPos && gm->playerViewData.Player1TextBox_CursorPos <= gm->playerViewData.Player1TextBox_Text.size()) {
						gm->playerViewData.Player1TextBox_Text.erase(gm->playerViewData.Player1TextBox_CursorPos, 1);
					}
					break;
				case VK_LEFT:
					if (gm->playerViewData.Player1TextBox_CursorPos > 0)
						--gm->playerViewData.Player1TextBox_CursorPos;
					break;
				case VK_RIGHT:
					if (gm->playerViewData.Player1TextBox_CursorPos < gm->playerViewData.Player1TextBox_Text.size())
						++gm->playerViewData.Player1TextBox_CursorPos;
					break;
				case VK_END:
					gm->playerViewData.Player1TextBox_CursorPos = gm->playerViewData.Player1TextBox_Text.size();
					break;
				case VK_HOME:
					gm->playerViewData.Player1TextBox_CursorPos = 0;
					break;
				case VK_RETURN:
					//do nothing for now
					break;
				default:
					char ch = ker.uChar.AsciiChar;
					if (isprint(ch))
						gm->playerViewData.Player1TextBox_Text.insert(gm->playerViewData.Player1TextBox_CursorPos++ + gm->playerViewData.Player1TextBox_Text.begin(), ch);
				}
				playerView.UpdatePlayer1TextBox();
			}
#pragma endregion
#pragma region Player2TextBoxInput
			else if (gm->playerViewData.Player2TextBox_isFocused) {
				switch (ker.wVirtualKeyCode) {
				case VK_BACK:
					if (0 < gm->playerViewData.Player2TextBox_CursorPos && gm->playerViewData.Player2TextBox_CursorPos <= gm->playerViewData.Player2TextBox_Text.size()) {
						--gm->playerViewData.Player2TextBox_CursorPos;
						gm->playerViewData.Player2TextBox_Text.erase(gm->playerViewData.Player2TextBox_CursorPos, 1);
					}
					break;
				case VK_DELETE:
					if (0 < gm->playerViewData.Player2TextBox_CursorPos && gm->playerViewData.Player2TextBox_CursorPos <= gm->playerViewData.Player2TextBox_Text.size()) {
						gm->playerViewData.Player2TextBox_Text.erase(gm->playerViewData.Player2TextBox_CursorPos, 1);
					}
					break;
				case VK_LEFT:
					if (gm->playerViewData.Player2TextBox_CursorPos > 0)
						--gm->playerViewData.Player2TextBox_CursorPos;
					break;
				case VK_RIGHT:
					if (gm->playerViewData.Player2TextBox_CursorPos < gm->playerViewData.Player2TextBox_Text.size())
						++gm->playerViewData.Player2TextBox_CursorPos;
					break;
				case VK_END:
					gm->playerViewData.Player2TextBox_CursorPos = gm->playerViewData.Player2TextBox_Text.size();
					break;
				case VK_HOME:
					gm->playerViewData.Player2TextBox_CursorPos = 0;
					break;
				case VK_RETURN:
					//do nothing for now
					break;
				default:
					char ch = ker.uChar.AsciiChar;
					if (isprint(ch))
						gm->playerViewData.Player2TextBox_Text.insert(gm->playerViewData.Player2TextBox_CursorPos++ + gm->playerViewData.Player2TextBox_Text.begin(), ch);
				}
				playerView.UpdatePlayer2TextBox();
			}
#pragma endregion
			else {
				DWORD ks = ker.dwControlKeyState;
				if (isgraph(ker.uChar.AsciiChar)) {
					CHAR keyPressed = ker.uChar.AsciiChar;
					if (keyPressed == 'r') {//reset game
						//clear all data in each cell...
						ResetGameCommand rgc(gm);
						rgc.execute();
					}
				}
			}
		}
	}

	//Function used to handle mouse input for GomokuApp.
	static void MouseEventProc(MOUSE_EVENT_RECORD const&mer) {
		if (mer.dwEventFlags == 0) {
			DWORD mask = mer.dwButtonState;
			COORD clickLocation = mer.dwMousePosition;
#pragma region PlayerTextBoxMouseInput
			bool Player1TextBoxClicked = clickLocation.Y == gm->playerViewData.Player1TextBox_STARTy && clickLocation.X >= gm->playerViewData.Player1TextBox_STARTx && clickLocation.X < gm->playerViewData.Player1TextBox_STARTx + gm->playerViewData.Player1TextBox_SIZE;
			bool Player2TextBoxClicked = clickLocation.Y == gm->playerViewData.Player2TextBox_STARTy && clickLocation.X >= gm->playerViewData.Player2TextBox_STARTx && clickLocation.X < gm->playerViewData.Player2TextBox_STARTx + gm->playerViewData.Player2TextBox_SIZE;
			if (Player1TextBoxClicked) {
				playerView.UpdateCursorInfo(1);
				gm->playerViewData.Player1TextBox_CursorPos = min(clickLocation.X - gm->playerViewData.Player1TextBox_STARTx + gm->playerViewData.Player1TextBox_Aperture, gm->playerViewData.Player1TextBox_Text.size());
				COORD loc = { SHORT(gm->playerViewData.Player1TextBox_CursorPos - gm->playerViewData.Player1TextBox_Aperture + gm->playerViewData.Player1TextBox_STARTx),SHORT(gm->playerViewData.Player1TextBox_STARTy) };
				playerView.UpdateCursorPosition(loc);
			}
			else if (Player2TextBoxClicked) {
				playerView.UpdateCursorInfo(1);
				gm->playerViewData.Player2TextBox_CursorPos = min(clickLocation.X - gm->playerViewData.Player2TextBox_STARTx + gm->playerViewData.Player2TextBox_Aperture, gm->playerViewData.Player2TextBox_Text.size());
				COORD loc = { SHORT(gm->playerViewData.Player2TextBox_CursorPos - gm->playerViewData.Player2TextBox_Aperture + gm->playerViewData.Player2TextBox_STARTx),SHORT(gm->playerViewData.Player2TextBox_STARTy) };
				playerView.UpdateCursorPosition(loc);
			}
			else if (!Player1TextBoxClicked && !Player2TextBoxClicked && (gm->playerViewData.Player1TextBox_isFocused || gm->playerViewData.Player2TextBox_isFocused)) {
				playerView.UpdateCursorInfo(0);
			}
			gm->playerViewData.Player1TextBox_isFocused = Player1TextBoxClicked;
			gm->playerViewData.Player2TextBox_isFocused = Player2TextBoxClicked;
#pragma endregion
#pragma region UpdateNameButtonHandler
			bool Player1UpdateButtonClicked = clickLocation.Y == gm->playerViewData.Player1UpdateButton_STARTy && clickLocation.X >= gm->playerViewData.Player1UpdateButton_STARTx && clickLocation.X <= gm->playerViewData.Player1UpdateButton_END && (mask&FROM_LEFT_1ST_BUTTON_PRESSED);
			bool Player2UpdateButtonClicked = clickLocation.Y == gm->playerViewData.Player2UpdateButton_STARTy && clickLocation.X >= gm->playerViewData.Player2UpdateButton_STARTx && clickLocation.X <= gm->playerViewData.Player2UpdateButton_END && (mask&FROM_LEFT_1ST_BUTTON_PRESSED);
			if (Player1UpdateButtonClicked) {
				if (gm->playerViewData.Player1TextBox_Text.size() <= 0) {
					SetStatusCommand ssc(gm, "Cannot set Player 1's name to empty value!",false);
					ssc.execute();
				}
				else if (gm->playerViewData.Player1TextBox_Text.size() > 25) {
					SetStatusCommand ssc(gm, "Player 1's name is too long!", false);
					ssc.execute();
				}
				else {
					UpdateScoreCommand usc(gm, gm->playerViewData.Player1TextBox_Text, 1, -1);
					usc.execute();
				}
			}
			else if (Player2UpdateButtonClicked) {
				if (gm->playerViewData.Player2TextBox_Text.size() <= 0) {
					SetStatusCommand ssc(gm, "Cannot set Player 2's name to empty value!", false);
					ssc.execute();
				}
				else if (gm->playerViewData.Player2TextBox_Text.size() > 25) {
					SetStatusCommand ssc(gm, "Player 2's name is too long!", false);
					ssc.execute();
				}
				else {
					UpdateScoreCommand usc(gm, gm->playerViewData.Player2TextBox_Text, 2, -1);
					usc.execute();
				}
			}
#pragma endregion;
#pragma region PalleteClick
			bool Player1PalleteClicked = clickLocation.Y == gm->playerViewData.chooseColorInfoY && clickLocation.X >= gm->playerViewData.Player1PalleteStartx && clickLocation.X <= gm->playerViewData.Player1PalleteStartx + gm->playerViewData.PalleteLength && (mask&FROM_LEFT_1ST_BUTTON_PRESSED);
			bool Player2PalleteClicked = clickLocation.Y == gm->playerViewData.chooseColorInfoY && clickLocation.X >= gm->playerViewData.Player2PalleteStartx && clickLocation.X <= gm->playerViewData.Player2PalleteStartx + gm->playerViewData.PalleteLength && (mask&FROM_LEFT_1ST_BUTTON_PRESSED);
			if (Player1PalleteClicked) {
				WORD selectedColor = 0;
				if (clickLocation.X == 17 || clickLocation.X == 18) { selectedColor = BG_RED; }
				else if (clickLocation.X == 21 || clickLocation.X == 22) { selectedColor = BG_GREEN; }
				else if (clickLocation.X == 25 || clickLocation.X == 26) { selectedColor = BG_BLUE; }
				else if (clickLocation.X == 29 || clickLocation.X == 30) { selectedColor = BG_CYAN; }
				else if (clickLocation.X == 33 || clickLocation.X == 34) { selectedColor = BG_YELLOW; }
				else if (clickLocation.X == 37 || clickLocation.X == 38) { selectedColor = BG_MAGENTA; }
				if (selectedColor == gm->scoreViewData.Player2TileColor) {
					SetStatusCommand ssc(gm, gm->scoreViewData.Player2Name + " has already chosen that color!",false);
					ssc.execute();
					selectedColor = 0;
				}
				if (selectedColor > 0) {
					UpdateColorCommand ucc(gm, 1, selectedColor);
					ucc.execute();
				}
			}
			else if (Player2PalleteClicked) {
				WORD selectedColor = 0;
				if (clickLocation.X == 67 || clickLocation.X == 68) { selectedColor = BG_RED; }
				else if (clickLocation.X == 71 || clickLocation.X == 72) { selectedColor = BG_GREEN; }
				else if (clickLocation.X == 75 || clickLocation.X == 76) { selectedColor = BG_BLUE; }
				else if (clickLocation.X == 79 || clickLocation.X == 80) { selectedColor = BG_CYAN; }
				else if (clickLocation.X == 83 || clickLocation.X == 84) { selectedColor = BG_YELLOW; }
				else if (clickLocation.X == 87 || clickLocation.X == 88) { selectedColor = BG_MAGENTA; }
				if (selectedColor == gm->scoreViewData.Player1TileColor) {
					SetStatusCommand ssc(gm, gm->scoreViewData.Player1Name + " has already chosen that color!",false);
					ssc.execute();
					selectedColor = 0;
				}
				if (selectedColor > 0) {
					UpdateColorCommand ucc(gm, 2, selectedColor);
					ucc.execute();
				}
			}
#pragma endregion
#pragma region GridViewClick
			if (gm->gameOver) { return; }
			if ((clickLocation.Y >= 8 && clickLocation.X <= 77) && (mask&FROM_LEFT_1ST_BUTTON_PRESSED)) {
				GomokuCell *c = nullptr;
				bool foundCell = false;
				SHORT startingY = 0, startingX = 0;
				//checks all the cells in the grid to see if the user clicked
				//on one of the locations of those cells.
				for (SHORT i = 0; i < 19; ++i) {//rows
					if (foundCell) { break; }
					for (SHORT j = 0; j < 19; ++j) {//columns
						if (foundCell) { break; }
						c = &gm->gomokuGrid.gridData[i][j];
						startingY = i;
						startingX = j;
						for (COORD l : c->cells) {
							if (l.X == clickLocation.X && l.Y == clickLocation.Y) {
								foundCell = true;
								break;
							}
						}
					}
				}
				//Only runs if a corresponding cell matched player click.
				if (foundCell && c != nullptr) {

					if (c->cellState == 0) {
						int checkState = 0;
						if (!gm->playerTurn) {
							PlaceDownCommand pdc(gm, 1, startingX, startingY);
							pdc.execute();
							//AddToListCommand atlc(gm,pdc);
							//atlc.execute();
							checkState = 1;
							/*program.paintAt(' ', FG_WHITE | BG_RED, c->location.X, c->location.Y);
							c->cellState = 1;*/
						}
						else {
							PlaceDownCommand pdc(gm, 2, startingX, startingY);
							pdc.execute();
							//AddToListCommand atlc(gm, pdc);
							//atlc.execute();
							checkState = 2;
							/*program.paintAt(' ', FG_WHITE | BG_BLACK, c->location.X, c->location.Y);
							c->cellState = 2;*/
						}

						if (CheckWinner(checkState, startingX, startingY)) {
							UpdateScoreCommand usc(gm,"",checkState,1);
							usc.execute();
							//gm->statusLock = true;
							SetStatusCommand ssc(gm,"Player " + to_string(checkState) + " wins!    Press 'r' to reset game.",true);
							ssc.execute();
							/*ChangeTitleCommand ctc(gm, "Gomoku - Player " + to_string(checkState) + " wins!");
							ctc.execute();*/
							/*string message = "Player " + to_string(checkState) + " wins!\n\nPress 'r' to reset game.";
							program.displayNotification(message, "Winner!", MB_OK | MB_ICONINFORMATION);*/
							gm->gameOver = true;
							return;
						}

						if (!gm->playerTurn) {
							/*ChangeTitleCommand ctc(gm, "Gomoku - Player 2's Turn");
							ctc.execute();*/
							//program.setTitle("Gomoku - Player 2's Turn"); 
						}
						else {
							/*ChangeTitleCommand ctc(gm, "Gomoku - Player 1's Turn");
							ctc.execute();*/
							//program.setTitle("Gomoku - Player 1's Turn");
						}
					}
				}
			}
#pragma endregion
#pragma region UndoButtonClick
			bool UndoButtonClicked = clickLocation.Y >= gm->moveListViewData.MoveListTopY && clickLocation.Y <= gm->moveListViewData.MoveListTopY + 2 && clickLocation.X >= gm->moveListViewData.buttonStartx && clickLocation.X < gm->moveListViewData.buttonStartx + gm->moveListViewData.buttonSize && (mask&FROM_LEFT_1ST_BUTTON_PRESSED);
			if (UndoButtonClicked) {
				if (gm->moveListViewData.allMoves.size() > 0) {
					gm->moveListViewData.allMoves.back().undo();
				}
			}
#pragma endregion
		}
	}
#pragma region UtilityFunctions
	// Any function that is static means that it is used by the functions used
	// to handle input (ProcessKeyEvent and MouseEventProc), since a function
	// must be static in order to send it as a function pointer.

	//Used to check the number of peices that are next to each other in a
	//particular direction.
	static int CheckDirection(int checkState, int currentX, int currentY, int moveX, int moveY) {
		int directionValue = 0;
		while (true) {
			currentY = currentY + moveY;
			currentX = currentX + moveX;
			if (currentY < 19 && currentY >= 0 && currentX < 19 && currentX >= 0) {
				if (gm->gomokuGrid.gridData[currentY][currentX].cellState == checkState) {
					++directionValue;
				}
				else { break; }
			}
			else { break; }
		}
		return directionValue;
	}

	//Uses the above function to add the corresponding directions and
	//checking if any of them are 5 more to declare if there is a winner or
	//not.
	static bool CheckWinner(int playerTurn, int startingX, int startingY) {
		//north: y = -1, south: y = 1, west: x = -1, east: x = 1
		int vertical = 1 + CheckDirection(playerTurn, startingX, startingY, 0, -1) + CheckDirection(playerTurn, startingX, startingY, 0, 1);
		int horizontal = 1 + CheckDirection(playerTurn, startingX, startingY, -1, 0) + CheckDirection(playerTurn, startingX, startingY, 1, 0);
		int diagonalDown = 1 + CheckDirection(playerTurn, startingX, startingY, -1, -1) + CheckDirection(playerTurn, startingX, startingY, 1, 1);
		int diagonalUp = 1 + CheckDirection(playerTurn, startingX, startingY, 1, -1) + CheckDirection(playerTurn, startingX, startingY, -1, 1);

		if (vertical >= 5 || horizontal >= 5 || diagonalDown >= 5 || diagonalUp >= 5) {
			return true;
		}
		return false;
	}
	static string GenerateEmptySpace(int size) {
		return string(size,' ');
	}
#pragma endregion
#pragma region ViewFunctions
	//GridView
	static void DrawGrid() {
		if (!program.setupConsole(gm->WINDOW_TITLE, gm->WINDOW_WIDTH, gm->WINDOW_HEIGHT)) {
			return;
		}
		program.paintAll(' ', BG_WHITE);
		//Initializes all GridCells with their respective values.
		for (SHORT i = 0; i < 19; ++i) {
			for (SHORT j = 0; j < 19; ++j) {
				SHORT x = (4 * j) + 2;
				SHORT y = (2 * i) + 9;
				gm->gomokuGrid.gridData[i][j] = GomokuCell(x, y);
			}
		}
		//9,11,13,15,17 = y
		//2,6,10,14,18 = x
		//Keep as reference until not needed since was used in project 2
		//Seperate function to print columns of a row.
		//void printLine(SHORT y,char line[]) {
		//	for (SHORT i = 0; i < WINDOW_WIDTH; ++i) {
		//		program.paintAt(line[i], FG_BLACK | BG_WHITE, i, y);
		//	}
		//}

		//Draws the grid
		//for (SHORT i = gm->GridView_STARTy; i < gm->GridView_HEIGHT; ++i) {
		//	if (i == gm->GridView_STARTy) { program.paintLine(gm->gomokuGrid.topl, BG_WHITE, 0, i); /*printLine(i, gomokuGrid.topl);*/ }
		//	else if (i == gm->GridView_HEIGHT - 1) { program.paintLine(gm->gomokuGrid.bottoml,BG_WHITE,0,i); /*printLine(i, gomokuGrid.bottoml);*/ }
		//	else if (i % 2 == 0) { program.paintLine(gm->gomokuGrid.midl,BG_WHITE,0,i); /*printLine(i, gomokuGrid.midl);*/ }
		//	else { program.paintLine(gm->gomokuGrid.emptyl,BG_WHITE,0,i); /*printLine(i, gomokuGrid.emptyl);*/ }
		//}
		//program.displayNotification(to_string(gm->playerViewData.topl.length()), "topl length", MB_OK | MB_ICONINFORMATION);
		//program.displayNotification(to_string(gm->playerViewData.playerViewInfo.length()), "info length", MB_OK | MB_ICONINFORMATION);
		int gridTracker = 0;
		for (SHORT i = 0; i < gm->WINDOW_HEIGHT; ++i) {
			if (i == 0) { program.paintLine(gm->playerViewData.topl, BG_WHITE, 0, i); }
			else if (i > 0 && i < 4) { program.paintLine(gm->playerViewData.emptyl, BG_WHITE, 0, i); }
			else if (i > 4 && i < 8) { program.paintLine(gm->scoreViewData.emptyl,BG_WHITE,0,i); }
			else if (i == 4) { program.paintLine(gm->scoreViewData.topl, BG_WHITE, 0, i); }
			else if (i > 7) {
				if (gridTracker == 0) {
					program.paintLine(gm->gomokuGrid.topl, BG_WHITE, 0, i);
				}
				else if (i == gm->WINDOW_HEIGHT - 1) {
					program.paintLine(gm->gomokuGrid.bottoml, BG_WHITE, 0, i);
				}
				else if (gridTracker % 2 == 0) {
					program.paintLine(gm->gomokuGrid.midl, BG_WHITE, 0, i);
				}
				else {
					program.paintLine(gm->gomokuGrid.emptyl, BG_WHITE, 0, i);
				}
				++gridTracker;
			}
			//data display components
			if (i == gm->playerViewData.PlayerNameInfoY) {
				program.paintLine(gm->playerViewData.playerViewInfo, BG_WHITE, 1, i);
				program.paintLine("               ", BG_GRAY | FG_BLACK, 25, i);
				program.paintLine("               ", BG_GRAY | FG_BLACK, 75, i);
				program.paintLine("|Update|",BG_CYAN|FG_BLACK,44,i);
				program.paintLine("|Update|", BG_CYAN | FG_BLACK, 94, i);
			}
			if (i == gm->playerViewData.chooseColorInfoY) {
				program.paintLine(gm->playerViewData.PlayerPalleteString, gm->playerViewData.PalleteColors, gm->playerViewData.Player1PalleteStartx, i);
				program.paintLine(gm->playerViewData.PlayerPalleteString, gm->playerViewData.PalleteColors, gm->playerViewData.Player2PalleteStartx, i);
			}
			if (i >= 43 && i <= 45) {
				switch (i) {
				case 43: program.paintLine(gm->moveListViewData.buttonTop,BG_WHITE,gm->moveListViewData.buttonStartx,i);
					break;
				case 44: program.paintLine(gm->moveListViewData.buttonMid, BG_WHITE, gm->moveListViewData.buttonStartx, i);
					break;
				case 45: program.paintLine(gm->moveListViewData.buttonBot, BG_WHITE, gm->moveListViewData.buttonStartx, i);
					break;
				}
			}
		}

		/*for (SHORT i = 0; i < gm->WINDOW_HEIGHT; ++i) {
			program.paintArea('I', FG_BLACK | BG_WHITE, gm->WINDOW_WIDTH, 0, 1, i);
		}*/

		//verification that all cell positions are accounted for.
		/*for (SHORT i = 0; i < 19; ++i) {
			for (SHORT j = 0; j < 19; ++j) {
				program.paintAt(' ', BG_BLACK, gm->gomokuGrid.gridData[i][j].location.X, gm->gomokuGrid.gridData[i][j].location.Y);
			}
		}*/
		scoreView.UpdateScoreView();
		program.waitForInput(&ProcessKeyEvent, &MouseEventProc);
	}
	static void UpdateCells() {
		for (SHORT i = 0; i < 19; ++i) {
			for (SHORT j = 0; j < 19; ++j) {
				WORD cellColor;
				if (gm->gomokuGrid.gridData[i][j].cellState == 1) { cellColor = gm->scoreViewData.Player1TileColor; }
				else if (gm->gomokuGrid.gridData[i][j].cellState == 2) { cellColor = gm->scoreViewData.Player2TileColor; }
				else { cellColor = BG_WHITE; } //cellState is 0 / empty
				program.paintAt(' ', cellColor, gm->gomokuGrid.gridData[i][j].location.X, gm->gomokuGrid.gridData[i][j].location.Y);
			}
		}
	}
	static void UpdateTitle() {
		program.setTitle(gm->WINDOW_TITLE);
	}
	static void UpdateCursorInfo(int val) {
		program.editCursorInfo(10,val);
	}
	static void UpdateCursorPosition(COORD loc) {
		program.editCursorPosition(loc);
	}
	static void UpdatePlayer1TextBox() {
		//show the string in the control
		auto practicalSize = gm->playerViewData.Player1TextBox_Text.size() + 1;
		while (gm->playerViewData.Player1TextBox_CursorPos < gm->playerViewData.Player1TextBox_Aperture) {
			--gm->playerViewData.Player1TextBox_Aperture;
		}
		while (gm->playerViewData.Player1TextBox_CursorPos - gm->playerViewData.Player1TextBox_Aperture >= gm->playerViewData.Player1TextBox_SIZE) {
			++gm->playerViewData.Player1TextBox_Aperture;
		}
		while (practicalSize - gm->playerViewData.Player1TextBox_Aperture < gm->playerViewData.Player1TextBox_SIZE && practicalSize > gm->playerViewData.Player1TextBox_SIZE) {
			--gm->playerViewData.Player1TextBox_Aperture;
		}
		auto s = gm->playerViewData.Player1TextBox_Text.substr(gm->playerViewData.Player1TextBox_Aperture, gm->playerViewData.Player1TextBox_SIZE);
		s += string(gm->playerViewData.Player1TextBox_SIZE - s.size(), ' ');

		program.paintLine(s, BG_GRAY | FG_BLACK, gm->playerViewData.Player1TextBox_STARTx, gm->playerViewData.Player1TextBox_STARTy);

		COORD cursorLoc = COORD{ SHORT(gm->playerViewData.Player1TextBox_STARTx),SHORT(gm->playerViewData.Player1TextBox_STARTy) };
		cursorLoc.X += SHORT(gm->playerViewData.Player1TextBox_CursorPos - gm->playerViewData.Player1TextBox_Aperture);
		program.editCursorPosition(cursorLoc);
	}
	static void UpdatePlayer2TextBox() {
		//show the string in the control
		auto practicalSize = gm->playerViewData.Player2TextBox_Text.size() + 1;
		while (gm->playerViewData.Player2TextBox_CursorPos < gm->playerViewData.Player2TextBox_Aperture) {
			--gm->playerViewData.Player2TextBox_Aperture;
		}
		while (gm->playerViewData.Player2TextBox_CursorPos - gm->playerViewData.Player2TextBox_Aperture >= gm->playerViewData.Player2TextBox_SIZE) {
			++gm->playerViewData.Player2TextBox_Aperture;
		}
		while (practicalSize - gm->playerViewData.Player2TextBox_Aperture < gm->playerViewData.Player2TextBox_SIZE && practicalSize > gm->playerViewData.Player2TextBox_SIZE) {
			--gm->playerViewData.Player2TextBox_Aperture;
		}
		auto s = gm->playerViewData.Player2TextBox_Text.substr(gm->playerViewData.Player2TextBox_Aperture, gm->playerViewData.Player2TextBox_SIZE);
		s += string(gm->playerViewData.Player2TextBox_SIZE - s.size(), ' ');

		program.paintLine(s, BG_GRAY | FG_BLACK, gm->playerViewData.Player2TextBox_STARTx, gm->playerViewData.Player2TextBox_STARTy);

		COORD cursorLoc = COORD{ SHORT(gm->playerViewData.Player2TextBox_STARTx),SHORT(gm->playerViewData.Player2TextBox_STARTy) };
		cursorLoc.X += SHORT(gm->playerViewData.Player2TextBox_CursorPos - gm->playerViewData.Player2TextBox_Aperture);
		program.editCursorPosition(cursorLoc);
	}
	static void UpdateScoreView() {
		program.paintLine(gm->scoreViewData.emptyl, BG_WHITE, 0, 5);
		program.paintLine(gm->scoreViewData.emptyl, BG_WHITE, 0, 6);
		program.paintLine(gm->scoreViewData.emptyl, BG_WHITE, 0, 7);
		//Player Peices
		string Player1PeicesPlayed = "Number of peices played: " + to_string(gm->scoreViewData.Player1PeicesPlaced);
		string Player2PeicesPlayed = "Number of peices played: " + to_string(gm->scoreViewData.Player2PeicesPlaced);
		SHORT Player1PeicesPlayedSize = SHORT(Player1PeicesPlayed.size());
		SHORT Player2PeicesPlayedSize = SHORT(Player2PeicesPlayed.size());
		SHORT Player1PeicesStart = 29 - SHORT(floor(Player1PeicesPlayedSize / 2));
		SHORT Player2PeicesStart = 87 - SHORT(floor(Player2PeicesPlayedSize / 2));
		program.paintLine(Player1PeicesPlayed, BG_WHITE, Player1PeicesStart, gm->scoreViewData.ScoreViewPlayerPeicesY);
		program.paintLine(Player2PeicesPlayed, BG_WHITE, Player2PeicesStart, gm->scoreViewData.ScoreViewPlayerPeicesY);

		//Player Names
		SHORT Player1size = SHORT(gm->scoreViewData.Player1Name.size());
		SHORT Player2size = SHORT(gm->scoreViewData.Player1Name.size());
		//character length cannot be more than 57 characters + 1 between each
		int const maxLength = 115;
		SHORT Player1LocationStart = 29 - SHORT(floor(Player1size/2));
		SHORT Player2LocationStart = 87 - SHORT(floor(Player2size/2));
		WORD Player1Color = gm->playerTurn ? BG_WHITE : gm->scoreViewData.Player1TileColor;
		WORD Player2Color = gm->playerTurn ? gm->scoreViewData.Player2TileColor : BG_WHITE;
		program.paintLine(gm->scoreViewData.Player1Name,Player1Color,Player1LocationStart,gm->scoreViewData.ScoreViewPlayerInfoY);
		program.paintLine(gm->scoreViewData.Player2Name,Player2Color,Player2LocationStart, gm->scoreViewData.ScoreViewPlayerInfoY);
		
		//Player Score
		SHORT Player1ScoreLocation = Player1LocationStart + SHORT(floor(gm->scoreViewData.Player1Name.size() / 2));
		SHORT Player2ScoreLocation = Player2LocationStart + SHORT(floor(gm->scoreViewData.Player2Name.size() / 2));
		program.paintLine(to_string(gm->scoreViewData.Player1NumberOfWins),BG_WHITE,Player1ScoreLocation,gm->scoreViewData.ScoreViewPlayerScore);
		program.paintLine(to_string(gm->scoreViewData.Player2NumberOfWins), BG_WHITE, Player2ScoreLocation, gm->scoreViewData.ScoreViewPlayerScore);
	}
	static void UpdateStatus(string text) {
		program.paintLine(gm->playerViewData.emptyl,BG_WHITE,0,gm->playerViewData.StatusBarInfoY);
		if (text.size() > 0) {
			SHORT statusSize = SHORT(text.size());
			//middle is 58
			SHORT statusLocationStart = 58 - SHORT(floor(statusSize/2));
			program.paintLine(text,BG_WHITE,statusLocationStart,gm->playerViewData.StatusBarInfoY);
		}
	}
	static void UpdateMoveList() {
		//WARNING: slow to update when populated
		if (gm->moveListViewData.allMoves.size() > 0) {
			//const auto it = crbegin(gm->moveListViewData.allMoves);
			SHORT v = SHORT(gm->moveListViewData.allMoves.size() - 1);
			SHORT MinY = gm->moveListViewData.MoveListMinY;
			SHORT MaxY = gm->moveListViewData.MoveListMaxY;
			SHORT Limit = gm->moveListViewData.MoveListShowLimit;
			SHORT StartX = gm->moveListViewData.MoveListStartX;
			for (SHORT i = MinY; i <= MaxY; ++i) {
				if (v + Limit >= Limit) {
					string text = gm->moveListViewData.allMoves[v].Action();
					WORD color = gm->moveListViewData.allMoves[v].state == 1 ? gm->scoreViewData.Player1TileColor : gm->scoreViewData.Player2TileColor;
					program.paintLine(text + GenerateEmptySpace(36 - int(text.size())),color, StartX, i);
					--v;
				}
				else {
					program.paintLine(GenerateEmptySpace(38), BG_WHITE, StartX, i);
					break;
				}
			}
		}
		else {
			SHORT StartX = gm->moveListViewData.MoveListStartX;
			SHORT MinY = gm->moveListViewData.MoveListMinY;
			SHORT MaxY = gm->moveListViewData.MoveListMaxY;
			for (SHORT i = MinY; i <= MaxY; ++i) {
				program.paintLine(GenerateEmptySpace(38), BG_WHITE, StartX, i);
			}
		}
	}
#pragma endregion;
public:
	GomokuController(GomokuModel& gmI) :gmLocal(gmI) {
		gm = gmLocal.GetInstance();
		gridView = GridView(&DrawGrid, &UpdateCells, &UpdateTitle);
		playerView = PlayerView(&UpdateCursorInfo,&UpdateCursorPosition,&UpdatePlayer1TextBox, &UpdatePlayer2TextBox,&UpdateStatus);
		scoreView = ScoreView(&UpdateScoreView);
		moveListView = MoveListView(&UpdateMoveList);
	}

	void update() override {
		//gm = gmLocal.GetInstance();
		if (gm->setup) {
			gm->setup = false;
			gridView.SetupGrid();
		}
		if (gm->updatePeices) {
			gm->updatePeices = false;
			gridView.UpdateCells();
		}
		if (gm->updateTextBox) {
			gm->updateTextBox = false;
			if (gm->playerViewData.Player1TextBox_Text.size() == 0) {
				playerView.UpdatePlayer1TextBox();
			}
			if (gm->playerViewData.Player2TextBox_Text.size() == 0) {
				playerView.UpdatePlayer2TextBox();
			}
		}
		if (gm->updateTitle) {
			gm->updateTitle = false;
			gridView.UpdateTitle();
		}
		if (gm->showStatusMsg) {gm->showStatusMsg = false;}
		else if(gm->WinnerText.size() > 0){gm->statusMsg = gm->WinnerText;}
		else {gm->statusMsg = "";}
		if (gm->updateMoveList) {
			gm->updateMoveList = false;
			playerView.UpdateStatus("Updating Move List View. Please wait...");
			moveListView.UpdateMoveList();
		}
		playerView.UpdateStatus(gm->statusMsg);
		scoreView.UpdateScoreView();
	}
	~GomokuController() { delete gm; }
};

ProgramManager GomokuController::program;
GridView GomokuController::gridView;
PlayerView GomokuController::playerView;
ScoreView GomokuController::scoreView;
MoveListView GomokuController::moveListView;