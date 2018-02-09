#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "BoardState.h"
class BoardState;

class NodeClass
{
	// enum for current states of the game
	enum state {
		Playing, Draw, Xwins, Owins

	};
	

private:

	

public:

	// declaring the game board
	std::string gameBoard = "         ";
	
	// initialising the game state
	state gameState;

	// declaring the functions
	int boardCheck();
	void drawBoard();
	void referenceBoard();



	NodeClass();
	~NodeClass();
};

