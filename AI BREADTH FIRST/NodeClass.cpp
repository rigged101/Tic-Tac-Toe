#include "NodeClass.h"
#include "BoardState.h"



NodeClass::NodeClass()
{
	std::string gameBoard = "         ";
}


NodeClass::~NodeClass()
{
}
// drawing the board to the screen
void NodeClass::drawBoard()
{
	printf(" %c | %c | %c\n", gameBoard[0], gameBoard[1], gameBoard[2]);
	printf("---+---+---\n");
	printf(" %c | %c | %c\n", gameBoard[3], gameBoard[4], gameBoard[5]);
	printf("---+---+---\n");
	printf(" %c | %c | %c\n", gameBoard[6], gameBoard[7], gameBoard[8]);
}
// game board reference for the player
void NodeClass::referenceBoard()
{
	printf(" 0 | 1 | 2\n");
	printf("---+---+---\n");
	printf(" 3 | 4 | 5\n");
	printf("---+---+---\n");
	printf(" 6 | 7 | 8\n");
	std::cout << "\n\n\n";
}

// function to check the possible winning, losing, drawing outcomes, or if the game is still being played
int NodeClass::boardCheck()
{
	if (gameBoard[0] == gameBoard[1] && gameBoard[1] == gameBoard[2] && gameBoard[0] != ' ' && gameBoard[1] != ' ')
	{
		if (gameBoard[0] == 'x')
		{
			
			gameState = Xwins;
			//return m_score + 10;
			return  + 10;

		}
		else 
		{
			gameState = Owins;
			return  - 10;

			
		}
		
	}
	else if (gameBoard[0] == gameBoard[3] && gameBoard[3] == gameBoard[6] && gameBoard[0] != ' '&& gameBoard[3] != ' ')
	{
		if (gameBoard[0] == 'x')
		{
			gameState = Xwins;
			return  + 10;

		}
		else
		{
			
			gameState = Owins;
			return  - 10;
		}
	}
	else if (gameBoard[0] == gameBoard[4] && gameBoard[4] == gameBoard[8] && gameBoard[0] != ' '&& gameBoard[4] != ' ')
	{
		if (gameBoard[0] == 'x')
		{
			gameState = Xwins;
			return  + 10;
		}
		else
		{
			gameState = Owins;
			return  - 10;
		}
	}
	else if (gameBoard[3] == gameBoard[4] && gameBoard[4] == gameBoard[5] && gameBoard[0] != ' '&& gameBoard[4] != ' ')
	{
		if (gameBoard[3] == 'x')
		{
			gameState = Xwins;
			return  + 10;
		}
		else
		{
			gameState = Owins;
			return  - 10;
		}
	}
	else if (gameBoard[6] == gameBoard[7] && gameBoard[7] == gameBoard[8] && gameBoard[0] != ' '&& gameBoard[7] != ' ')
	{
		if (gameBoard[6] == 'x')
		{
			gameState = Xwins;
			return  + 10;
		}
		else
		{
			gameState = Owins;
			return  - 10;
		}
	}
	else if (gameBoard[6] == gameBoard[4] && gameBoard[4] == gameBoard[2] && gameBoard[0] != ' '&& gameBoard[4] != ' ')
	{
		if (gameBoard[6] == 'x')
		{
			gameState = Xwins;
			return  + 10;
		}
		else
		{
			gameState = Owins;
			return  - 10;
		}
	}
	else if (gameBoard[1] == gameBoard[4] && gameBoard[4] == gameBoard[7] && gameBoard[0] != ' '&& gameBoard[4] != ' ')
	{
		if (gameBoard[1] == 'x')
		{
			gameState = Xwins;
			return  + 10;
		}
		else
		{
			gameState = Owins;
			return  - 10;
		}
	}
	else if (gameBoard[2] == gameBoard[5] && gameBoard[5] == gameBoard[8] && gameBoard[0] != ' '&& gameBoard[5] != ' ')
	{
		if (gameBoard[2] == 'x')
		{
			gameState = Xwins;
			return  + 10;
		}
		else
		{
			gameState = Owins;
			return  - 10;
		}
	}
	else if (gameBoard[0] != ' ' && gameBoard[1] != ' ' && gameBoard[2] != ' ' && gameBoard[3] != ' ' && gameBoard[4] != ' ' &&
		gameBoard[5] != ' ' && gameBoard[6] != ' ' && gameBoard[7] != ' ' && gameBoard[8] != ' ')
	{
		gameState = Draw;
		return  + 0;
	}
	else
	{
		gameState = Playing;
		return  - 1;
		

	}
}

