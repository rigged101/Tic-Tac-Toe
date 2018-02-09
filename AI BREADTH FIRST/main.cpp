#include <iostream>

#include "BoardState.h"
#include "NodeClass.h"
#include <string>
#include <memory>




// all possible states to check the game state
enum States {Playing, Draw, Xwins, Owins};
// enum for switching game menu
enum Menu {Play, Exit};

int main()
{
	//initialising the tic tac toe board
	BoardState boardTest;
	// used for choosing the position of 'x' or 'o'
	int index;
	// game loop
	bool gameLoop = true;
	// loop checking if the move is legal
	bool isAllowed = true;

	Menu gameMenu = Play;


	//main game loop
	while (gameLoop = true)
	{
		// game switch
		switch (gameMenu)
		{
		case Play:
			// checks for winning
			boardTest.rootTree->boardCheck();
			if (boardTest.rootTree->gameState == Playing)
			{
				//prints out reference board of positions of the board
				boardTest.rootTree->referenceBoard();

				// takes player input
				int x;
				std::cin >> x;
				// checks if there is an available move for player
				if (boardTest.rootTree->gameBoard.at(x) == ' ')
				{
					boardTest.rootTree->gameBoard[x] = 'x';
					boardTest.rootTree->drawBoard();
					isAllowed = true;

				}
				// if move is unavailable for player
				else if (boardTest.rootTree->gameBoard.at(x) != ' ')
				{

					isAllowed = false;
					std::cout << "\n\n Space Occupied, try again!";
					system("pause");

				}

				// if the player move was legal, and the AI is allowed to move
				if (isAllowed == true)
				{
					// for loop to check if the game can be ended in the next move
					for (int i = 0; i < 9; i++)
					{
						// checks if there is a possible space to move to
						if (boardTest.rootTree->gameBoard.at(i) == ' ')
						{
							// places a temporary 'o' to check if that would win the game
							// if it wins the game it will place it
							boardTest.rootTree->gameBoard.at(i) = 'o';
							if (boardTest.rootTree->boardCheck() == -10)
							{
								
								boardTest.rootTree->drawBoard();
								std::cout << "\n\n Computer 'o' has won";
								system("pause");
								gameMenu = Exit;
							}
							// if it doesnt win it will clear it and step through the minimax algorithm
							boardTest.rootTree->gameBoard.at(i) = ' ';
						}
					}
					system("pause");
					
					// runs the minimax algorithm to check for the next best move
					boardTest.currMove = boardTest.miniMax(boardTest.rootTree, "o");
					
					// takes the index from the minimax function and places it within the board
					index = boardTest.currMove.index;
					boardTest.rootTree->gameBoard.at(index) = 'o';
					
					system("cls");
					boardTest.rootTree->drawBoard();
					std::cout << "\n\n";
				}






			}
			// if the game is a draw
			else if (boardTest.rootTree->gameState == Draw)
			{
				std::cout << "\n\n the game has come to a draw!!";
				gameMenu = Exit;
			}
			// if 'o' wins
			else if (boardTest.rootTree->gameState == Owins)
			{
				std::cout << "\n\n 'o' has won the game!!";
				gameMenu = Exit;
			}
			// if 'x' wins
			else if (boardTest.rootTree->gameState == Xwins)
			{
				std::cout << "\n\n 'x' has won the game!!";
				gameMenu = Exit;
			}


		

			break;
		case Exit:
			// takes player input wether to exit or play again
			int i;
			std::cout << "Press 1 to exit, or 2 to play again";
			std::cin >> i;
			// if player exits
			if (i == 1)
			{
				std::cout << "Thank you for playing";
				return 0;
			}
			// if player wants to play again
			else if (i == 2)
			{
				boardTest.rootTree->gameBoard = "         ";
				gameMenu = Play;
				system("cls");
				
			}
			// failsafe
			else
			{
				std::cout << "\n\nPlease press the correct key to play again!";
				system("pause");
				system("cls");
			}


			break;

		}
	


	}


	


	return 0;
}

