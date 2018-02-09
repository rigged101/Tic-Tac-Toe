#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "NodeClass.h"
class NodeClass;

class BoardState
{
	// struct to store the index and the score of the current move
	struct Move {
		Move() {};

		Move(int _score) { score = _score; };

		int index;
		int score;

	};

	// enum for current states of the game
	enum state {
		Playing, Draw, Xwins, Owins

	};

private:
	


public:


	BoardState();
	~BoardState();
	// intialising the current state to check later on
	state currentState;
	// initialising the current move
	Move currMove;

	// initialising the root tree
	std::shared_ptr<NodeClass> rootTree;
	
	// since the player starts first, when minimax is run it will 
	//take the paramater of player 'o' as the player 'x' has already moved
	
	std::string player = "o";
	
	// initialising the minimax function
	Move miniMax(std::shared_ptr<NodeClass> _rootNode, std::string player);








};

