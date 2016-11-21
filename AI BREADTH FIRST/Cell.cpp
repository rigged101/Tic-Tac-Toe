#include <iostream>
#include "Cell.h"
#include <allegro5\allegro_primitives.h>


Cell::Cell(int _x, int _y, int _width, int _height, int _nodeVal)
{
	CellXpos = _x;
	CellYpos = _y;
	CellHeight = _height;
	CellWidth = _width;
	nodeVal = _nodeVal;

}

Cell::~Cell()
{

}

int Cell::getNodeValue()
{

	return nodeVal;

}

void Cell::setWallNode()
{

	al_draw_filled_rectangle(getCellXPosition(), getCellYPosition(), getCellWidth() + getCellXPosition(), getCellHeight() + getCellYPosition(), al_map_rgb(128, 128, 128));
	al_flip_display();
	nodeVal = 4;

	wallNode = nodeVal;

}
void Cell::setStartNode()
{

	al_draw_filled_rectangle(getCellXPosition(), getCellYPosition(), getCellWidth() + getCellXPosition(), getCellHeight() + getCellYPosition(), al_map_rgb(0, 255, 0));
	al_flip_display();
	nodeVal = 2;

	startNode = nodeVal;
}
void Cell::setGoalNode()
{

	al_draw_filled_rectangle(getCellXPosition(), getCellYPosition(), getCellWidth() + getCellXPosition(), getCellHeight() + getCellYPosition(), al_map_rgb(255, 0, 0));
	al_flip_display();
	nodeVal = 3;

	goalNode = nodeVal;

}
void Cell::setCheckedNode()
{
	nodeVal = 1;


	

}
void Cell::setOpenNode()
{
	al_draw_rectangle(getCellXPosition(), getCellYPosition(), getCellWidth() + getCellXPosition(), getCellHeight() + getCellYPosition(), al_map_rgb(0, 0, 0), 5);
	al_draw_filled_rectangle(getCellXPosition(), getCellYPosition(), getCellWidth() + getCellXPosition(), getCellHeight() + getCellYPosition(), al_map_rgb(255, 255, 255));
	al_flip_display();
	nodeVal = 0;


}

void Cell::setParentPosition(int x, int y)
{
	parent_x = x;
	parent_y = y;
}
int Cell::getParentPositionX()
{
	return parent_x;
}
int Cell::getParentPositionY()
{
	return parent_y;
}

void Cell::drawPath()
{
	al_draw_rectangle(getCellXPosition(), getCellYPosition(), getCellWidth() + getCellXPosition(), getCellHeight() + getCellYPosition(), al_map_rgb(0, 0, 0), 5);
	al_draw_filled_rectangle(getCellXPosition(), getCellYPosition(), getCellWidth() + getCellXPosition(), getCellHeight() + getCellYPosition(), al_map_rgb(220, 85, 160));
	al_flip_display();
}
void Cell::setPath()
{
	nodeVal = 5;
}







void Cell::drawCheckedCell()
{
	al_draw_rectangle(getCellXPosition(), getCellYPosition(), getCellWidth() + getCellXPosition(), getCellHeight() + getCellYPosition(), al_map_rgb(0, 0, 0), 5);
	al_draw_filled_rectangle(getCellXPosition(), getCellYPosition(), getCellWidth() + getCellXPosition(), getCellHeight() + getCellYPosition(), al_map_rgb(128, 255, 128));

	al_flip_display();
}



int Cell::getStartNode()
{	
	return startNode;
}
int Cell::getWallNode()
{
	return wallNode;
}
int Cell::getGoalNode()
{
	return goalNode;
}



void Cell::setCellXPosition(int xPos)
{
	CellXpos = xPos;
}


int Cell::getCellXPosition()
{
	return CellXpos;
}

void Cell::setCellYPosition(int yPos)
{
	CellYpos = yPos;
}
int Cell::getCellYPosition()
{
	return CellYpos;
}

void Cell::setCellWidth(int width)
{
	CellWidth = width;
}

int Cell::getCellWidth()
{
	return CellWidth;
}

void Cell::setCellHeight(int height)
{
	CellHeight = height;
}
int Cell::getCellHeight()
{
	return CellHeight;
}


int Cell::getArrayCellPositionX()
{
	ArrayCellPosX = CellXpos / CellWidth;

	return ArrayCellPosX;

}

int Cell::getArrayCellPositionY()
{
	ArrayCellPosY = CellYpos / CellHeight;

	return ArrayCellPosY;

}





