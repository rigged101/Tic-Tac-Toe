#include "BoardState.h"



BoardState::BoardState()
{
	// creating a shared pointer for later use within the program
	NodeClass temp;

	rootTree = std::make_shared<NodeClass>(temp);
	
	
}


BoardState::~BoardState()
{

}

BoardState::Move BoardState::miniMax(std::shared_ptr<NodeClass> _rootNode, std::string _player)
{
	
	// initialising index variable
	int index;
	// declaring m_score variable as the variable to check for the current state of the board to return a value i.e score
	int m_score = _rootNode->boardCheck();
	Move best_move;

	// the base case
	if (m_score != -1)
	{

		return Move(m_score);
	}
	
	
	// if its player 'x' turn
	if (_player == "x")
	{
		// sets the maximum score for 'x'
		int min_score = -1000;

		for (int i = 0; i < 9; i++)
		{
			



			// checks if there is an available space to go to
			if (_rootNode->gameBoard.at(i) == ' ')
			{

				// places 'x' if there is
				_rootNode->gameBoard.at(i) = 'x';

			
				// recursion of the minimax function
				 best_move = miniMax(_rootNode, _player = "o");
				 // checks if the maximum score for player x is lover than the best move from player 'o' if it is
				 // then it makes the best move for 'x' equal the worst move for 'o'
				if (min_score < best_move.score)
				{
					min_score = best_move.score;
					index = i;

				}

				// makes the current space empty
				_rootNode->gameBoard.at(i) = ' ';

				

			}
			

		}
		// passes the information of the best move for x into best_move struct
		best_move.index = index;
		best_move.score = min_score;
		// returns best_move
		return best_move;
	}
	
	// same as for player 'x' just reversed
	else if (_player == "o")
	{
		int max_score = +1000;

		for (int i = 0; i < 9; i++)
		{


			


			if (_rootNode->gameBoard.at(i) == ' ')
			{

				_rootNode->gameBoard.at(i) = 'o';


				best_move = miniMax(_rootNode, _player = "x");
				if (max_score > best_move.score)
				{

					max_score = best_move.score;
					index = i;

				}

				_rootNode->gameBoard.at(i) = ' ';



			}
			

		}
		best_move.index = index;
		best_move.score = max_score;

		return best_move;
	}


}


