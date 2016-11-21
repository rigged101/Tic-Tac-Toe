#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_ttf.h>
#include <vector>
#include <list>
#include <cmath>
#include <queue>
#include <memory>
#include <time.h>
#include <deque>
#include "Cell.h"

// all of the functions are declared
void breadthFirstSearch(std::vector<std::vector<std::shared_ptr<Cell>>> CellArray, ALLEGRO_EVENT ev);
void drawGrid(std::vector<std::vector<std::shared_ptr<Cell>>> &CellArray);
void resetGrid(std::vector<std::vector<std::shared_ptr<Cell>>> &CellArray);
int amountOfCells = 33; // global variable for the amount of cells
std::queue <std::shared_ptr<Cell>> PATH; // global variable used so that it could be access in main and in the best first search

int main()
{
	// all of the allegro initialisation
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY * display;

	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_MOUSE_STATE mouseState;


	display = al_create_display(1280, 960);
	al_install_mouse();
	al_install_keyboard();
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	//invitialises the CellArray Vector
	std::vector<std::vector<std::shared_ptr<Cell>>> CellArray;


	//calls the draw grid function
	drawGrid(CellArray);

	int x, y;
	// initialises allegro mouse events

	while (true)
	{

		ALLEGRO_EVENT ev;

		al_wait_for_event(event_queue, &ev);
		al_get_keyboard_state(&keyState);
		al_get_mouse_state(&mouseState);

		//  x and y variables adjusted to the screen size.
		x = ev.mouse.x / 40;
		y = ev.mouse.y / 30;

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{


			if (mouseState.buttons & 1) // wall
			{
				// sets the wall node value at the x and y positions
				CellArray[y][x]->setWallNode();


			}


			if (mouseState.buttons & 2) //goal
			{
				// sets the goal node value at the x and y positions
				CellArray[y][x]->setGoalNode();


				

			}


			if (mouseState.buttons & 4) // start
			{
				// sets the start node value at the x and y positions
				CellArray[y][x]->setStartNode();
				// ACtivates the best first path finding algorithm on click
				breadthFirstSearch(CellArray, ev);



			}




		}
		// if key 'r' is pressed the whole grid is going to be reset.
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{

			if (al_key_down(&keyState, ALLEGRO_KEY_R))
			{

				resetGrid(CellArray);
			}
		}
		al_flip_display();



	}



	std::cin.get();

	return 0;
}

// draw grid function that draws the grid
void drawGrid(std::vector<std::vector<std::shared_ptr<Cell>>> &CellArray)
{

	int width = 40;
	int height = 30;



	// specifies the sice of the vector, by creating a vector full of null pointers
	for (int i = 0; i < amountOfCells; i++)
	{
		std::vector<std::shared_ptr<Cell>>row;
		for (int j = 0; j < amountOfCells; j++)
		{

			row.push_back(nullptr);



		}
		CellArray.push_back(row);

	}


	// fills the vector with the dimensions and a node value for each cell within the grid
	for (int i = 0; i < amountOfCells; i++)
	{
		for (int j = 0; j < amountOfCells; j++)
		{
			CellArray[i][j] = std::make_shared<Cell>(j * width, i * height, width, height, 0);
		}
	}


	// draw the actual grid

	for (int i = 0; i < amountOfCells; i++)
	{
		for (int j = 0; j < amountOfCells; j++)

		{


			al_draw_rectangle(CellArray[i][j]->getCellXPosition(), CellArray[i][j]->getCellYPosition(), CellArray[i][j]->getCellWidth() + CellArray[i][j]->getCellXPosition(), CellArray[i][j]->getCellHeight() + CellArray[i][j]->getCellYPosition(), al_map_rgb(0, 0, 0), 5);
			al_draw_filled_rectangle(CellArray[i][j]->getCellXPosition(), CellArray[i][j]->getCellYPosition(), CellArray[i][j]->getCellWidth() + CellArray[i][j]->getCellXPosition(), CellArray[i][j]->getCellHeight() + CellArray[i][j]->getCellYPosition(), al_map_rgb(255, 255, 255));


		}
		al_flip_display();

	}
}
// grid reset function
void resetGrid(std::vector<std::vector<std::shared_ptr<Cell>>> &CellArray)
{



	for (int i = 0; i < amountOfCells; i++)
	{
		for (int j = 0; j < amountOfCells; j++)
		{
			CellArray[i][j]->setOpenNode();
		}
	}






}



void breadthFirstSearch(std::vector<std::vector<std::shared_ptr<Cell>>> CellArray, ALLEGRO_EVENT ev)
{
	// BFS SEARCH
	// Open = 0, Closed = 1, Start = 2, Goal = 3, wall = 4, parent = 5;
	int x = ev.mouse.x / 40;
	int y = ev.mouse.y / 30;



	
	
	if (CellArray[y][x]->getStartNode() == CellArray[y][x]->getNodeValue())
	{


	
		std::queue <std::shared_ptr<Cell>> BFS; //creates the queue for the algorithm
		std::queue <std::shared_ptr<Cell>> PATH; //creates a queue for the path
		BFS.push(CellArray[y][x]);
		CellArray[y][x]->setParentPosition(x, y);
		int temp_x, temp_y;
		



		while (!BFS.empty())// when the list is not empty start the search
		{
			// re assigning the x and y values of the position of the cell at the front of the queue
			temp_x = BFS.front()->getArrayCellPositionX();
			temp_y = BFS.front()->getArrayCellPositionY();




			if (CellArray[temp_y][temp_x]->getNodeValue() == CellArray[temp_y][temp_x]->getGoalNode())// checks if current node has reached the end
			{

				int x, y;
				x = temp_x;
				y = temp_y;


				while (!BFS.empty())
				{

					while (CellArray[y][x]->getNodeValue() != 2)// check if the current  cell is equal to the start cell
					{
						// pushes the parent cell of the child cell into the queue and repeats the process until the start node is found
						PATH.push(CellArray[CellArray[y][x]->getParentPositionY()][CellArray[y][x]->getParentPositionX()]);
						x = CellArray[y][x]->getParentPositionX();
						y = CellArray[y][x]->getParentPositionY();
					}
					size_t pathSize = PATH.size();

					for (size_t i = 0; i < pathSize; i++)// for loop that draws the path back
					{
						if (!PATH.empty())
						{
							if (PATH.front()->getNodeValue() == 2)
							{
								PATH.pop();
							}
							else
							{
								PATH.front()->drawPath();
								PATH.pop();
							}
						}
					}

					BFS.pop(); // cleares the queue
				}
			}
			else if (true)
			{

				for (size_t i = 0; i < 4; i++)// for loop triggered N, E, S, W directions
				{
					switch (i)
					{
					case 0: // north
							// bounding check, to make sure the vector doesnt go out of range
						if (CellArray[temp_y ][temp_x]->getArrayCellPositionY() > 0 && CellArray[temp_y ][temp_x]->getArrayCellPositionY() < amountOfCells - 1  
							&& CellArray[temp_y ][temp_x]->getArrayCellPositionX() > 0 && CellArray[temp_y][temp_x]->getArrayCellPositionX() < amountOfCells - 1  )
						{

							// checks to see if the current node as hit a wall, a closed node, or the start node
							if (CellArray[temp_y - 1][temp_x]->getNodeValue() != 1 && CellArray[temp_y - 1][temp_x]->getNodeValue() != 4 && CellArray[temp_y - 1][temp_x]->getNodeValue() != 2)
							{
								if (CellArray[temp_y - 1][temp_x]->getNodeValue() == CellArray[temp_y - 1][temp_x]->getGoalNode())// checks if the goal has been found
								{
									CellArray[temp_y - 1][temp_x]->setParentPosition(temp_x, temp_y);
									BFS.push(CellArray[temp_y - 1][temp_x]);
									false;

								}
								else
								{

									CellArray[temp_y - 1][temp_x]->setParentPosition(temp_x, temp_y); // sets the parent position of the current cell
									BFS.push(CellArray[temp_y - 1][temp_x]); // places the new cell into the qeue
									CellArray[temp_y - 1][temp_x]->setCheckedNode(); // sets the next node to checked
									CellArray[temp_y - 1][temp_x]->drawCheckedCell(); // draws the actual node
									


								}


							}
							break;
						}



						break;
					case 2: //south

						if (CellArray[temp_y + 1 ][temp_x]->getArrayCellPositionY() > 0 && CellArray[temp_y + 1][temp_x]->getArrayCellPositionY() < amountOfCells - 1
							&& CellArray[temp_y ][temp_x]->getArrayCellPositionX() > 0 && CellArray[temp_y ][temp_x]->getArrayCellPositionX() < amountOfCells - 1 )
						{


							if (CellArray[temp_y + 1][temp_x]->getNodeValue() != 1 && CellArray[temp_y + 1][temp_x]->getNodeValue() != 4 && CellArray[temp_y + 1][temp_x]->getNodeValue() != 2)
							{
								if (CellArray[temp_y + 1][temp_x]->getNodeValue() == CellArray[temp_y + 1][temp_x]->getGoalNode())
								{
									CellArray[temp_y + 1][temp_x]->setParentPosition(temp_x, temp_y);
									BFS.push(CellArray[temp_y + 1][temp_x]);
									false;

								}
								else
								{

									CellArray[temp_y + 1][temp_x]->setParentPosition(temp_x, temp_y);
									BFS.push(CellArray[temp_y + 1][temp_x]);
									CellArray[temp_y + 1][temp_x]->setCheckedNode();
									CellArray[temp_y + 1][temp_x]->drawCheckedCell();

								}

							}
							break;
						}


						break;
					case 1: // west
						if (CellArray[temp_y][temp_x]->getArrayCellPositionY() > 0 && CellArray[temp_y][temp_x ]->getArrayCellPositionY() < amountOfCells - 1  
							&& CellArray[temp_y][temp_x ]->getArrayCellPositionX() > 0 && CellArray[temp_y][temp_x ]->getArrayCellPositionX() < amountOfCells - 1 )
						{

							if (CellArray[temp_y][temp_x - 1]->getNodeValue() != 1 && CellArray[temp_y][temp_x - 1]->getNodeValue() != 4 && CellArray[temp_y][temp_x - 1]->getNodeValue() != 2)
							{
								if (CellArray[temp_y][temp_x - 1]->getNodeValue() == CellArray[temp_y][temp_x - 1]->getGoalNode())
								{
									CellArray[temp_y][temp_x - 1]->setParentPosition(temp_x, temp_y);
									BFS.push(CellArray[temp_y][temp_x - 1]);
									false;

								}
								else
								{

									CellArray[temp_y][temp_x - 1]->setParentPosition(temp_x, temp_y);
									BFS.push(CellArray[temp_y][temp_x - 1]);
									CellArray[temp_y][temp_x - 1]->setCheckedNode();
									CellArray[temp_y][temp_x - 1]->drawCheckedCell();


								}


							}
							break;
						}


						break;
					case 3: //east

						if (CellArray[temp_y][temp_x ]->getArrayCellPositionY() > 0 && CellArray[temp_y][temp_x ]->getArrayCellPositionY() < amountOfCells - 1  
							&& CellArray[temp_y][temp_x + 1]->getArrayCellPositionX() > 0 && CellArray[temp_y][temp_x + 1]->getArrayCellPositionX() < amountOfCells - 1 )
						{

							if (CellArray[temp_y][temp_x + 1]->getNodeValue() != 1 && CellArray[temp_y][temp_x + 1]->getNodeValue() != 4 && CellArray[temp_y][temp_x + 1]->getNodeValue() != 2)
							{
								if (CellArray[temp_y][temp_x + 1]->getNodeValue() == CellArray[temp_y][temp_x + 1]->getGoalNode())
								{
									CellArray[temp_y][temp_x + 1]->setParentPosition(temp_x, temp_y);
									BFS.push(CellArray[temp_y][temp_x + 1]);
									false;

								}
								else
								{

									CellArray[temp_y][temp_x + 1]->setParentPosition(temp_x, temp_y);
									BFS.push(CellArray[temp_y][temp_x + 1]);
									CellArray[temp_y][temp_x + 1]->setCheckedNode();
									CellArray[temp_y][temp_x + 1]->drawCheckedCell();

								}

							}
							break;
						}



						break;
					}


				}

				
				BFS.pop();

			}



		}


	}
}