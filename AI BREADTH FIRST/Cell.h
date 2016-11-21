#pragma once

class Cell
{
public:

	int getArrayCellPositionX();
	int getArrayCellPositionY();

	void setCellXPosition(int xPos);
	int getCellXPosition();
	
	void setCellYPosition(int yPos);
	int getCellYPosition();

	void setCellWidth(int width);
	int getCellWidth();

	void setCellHeight(int height);
	int getCellHeight();

	void setWallNode();
	int getWallNode();
	int getNodeValue();
	void setGoalNode();
	int getGoalNode();
	void setStartNode();
	int getStartNode();


	void setOpenNode();
	void setCheckedNode();


	

	

	void setParentPosition(int x, int y);
	int getParentPositionX();
	int getParentPositionY();
	void drawPath();
	void setPath();
	void drawCheckedCell();




	
	Cell(int _x, int _y, int _height, int _width, int _nodeVal);

	~Cell();

private:
	int ArrayCellPosX, ArrayCellPosY;
	int nodeVal;
	int wallNode;
	int goalNode;
	int startNode;
	int checkedNode;
	int CellXpos;
	int CellYpos;
	int CellWidth;
	int CellHeight;
	int parent_x, parent_y;



};

