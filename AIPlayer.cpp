/*
 * AIPlayer.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: eliyahu
 */

#include "AIPlayer.h"

AIPlayer::AIPlayer(char symbol) :
		Players(symbol) {
	this->symbol = symbol;
	if (this->symbol == 'x') {
		this->otherSymbol = 'o';
	} else {
		this->otherSymbol = 'x';
	}
}

int AIPlayer::play(Board &b, int &myScore, int &otherScore) {
	Cell *curCell;
	Cell *bestChoose;
	int curCellScore = -1 * b.getSize() * b.getSize();
	int bestCellScore = -1 * b.getSize() * b.getSize();

	this->generateMoves(b, this->moves);
	if (!this->moves.empty()) {
		while (!this->moves.empty()) {
			curCell = &this->moves.back();
			curCellScore = checkMove(b.makeCopy(), myScore, otherScore,
					*curCell);
			if (curCellScore > bestCellScore) {
				bestCellScore = curCellScore;
				bestChoose = curCell;
			}
			this->moves.pop_back();
		}
		makeMove(*bestChoose, myScore, otherScore, b);
		return 1;
	} else {
		return 0;
	}
}

int AIPlayer::checkMove(Board &b, int &myScore, int &otherScore, Cell cell) {
	vector<Cell> v;
	int myStart = myScore;
	int otherStart = otherScore;
	int worstCase = b.getSize() * b.getSize();
	int curScore = b.getSize() * b.getSize();

	this->makeMove(cell, myScore, otherScore, b);
	Board newBoard(b);
	this->rivalMoves(b, v);

	while (!v.empty()) {
		curScore = curMoveScore(v.back(), myScore, otherScore, newBoard);
		if (curScore < worstCase) {
			worstCase = curScore;
		}
		myScore = myStart;
		otherScore = otherStart;
		v.pop_back();
	}
	return worstCase;
}

int AIPlayer::curMoveScore(Cell cell, int &myScore, int &otherScore, Board &b) {
	this->makeMove(cell, myScore, otherScore, b);
	return myScore - otherScore;
}

void AIPlayer::rivalMoves(Board &b, vector<Cell> &vec) {
	if (this->symbol == 'x') {
		this->symbol = 'o';
	} else {
		this->symbol = 'x';
	}
	this->generateMoves(b, vec);
	if (this->symbol == 'x') {
		this->symbol = 'o';
	} else {
		this->symbol = 'x';
	}
}
