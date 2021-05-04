#pragma once

#include<functional>

class GomokuView
{
public:
	GomokuView() {}
	~GomokuView() {}
};

class GridView : public GomokuView {
public:
	function<void()> SetupGrid;
	function<void()> UpdateCells;
	function<void()> UpdateTitle;
	GridView() {}
	GridView(function<void()> sg,function<void()> uc,function<void()> ut) {
		SetupGrid = sg;
		UpdateCells = uc;
		UpdateTitle = ut;
	}
};

class PlayerView : public GomokuView {
public:
	function<void(int val)> UpdateCursorInfo;
	function<void(COORD loc)> UpdateCursorPosition;
	function<void()> UpdatePlayer1TextBox;
	function<void()> UpdatePlayer2TextBox;
	function<void(string txt)> UpdateStatus;
	PlayerView() {}
	PlayerView(function<void(int val)> uci, function<void(COORD loc)> ucp, function<void()> up1tb, function<void()> up2tb,function<void(string txt)> us) {
		UpdateCursorInfo = uci;
		UpdateCursorPosition = ucp;
		UpdatePlayer1TextBox = up1tb;
		UpdatePlayer2TextBox = up2tb;
		UpdateStatus = us;
	}
};

class ScoreView : public GomokuView {
public:
	function<void()> UpdateScoreView;
	ScoreView() {}
	ScoreView(function<void()> usv) {
		UpdateScoreView = usv;
	}
};

class MoveListView : public GomokuView {
public:
	function<void()> UpdateMoveList;
	MoveListView() {}
	MoveListView(function<void()> uml) {
		UpdateMoveList = uml;
	}
};
