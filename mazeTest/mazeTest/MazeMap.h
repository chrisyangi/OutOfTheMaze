#ifndef MAZEMAP_H
#define MAZEMAP_H
#include <Windows.h>
#define WALL 1
#define ROAD 0
class MazeMap
{
public:
	MazeMap(char wall, char road);
	~MazeMap();
	bool setMaze(int *maze, int row, int col);   // set the maze
	void printMaze();							 // print maze 
	int** getMaze();	         // get maze point
	void setExitPosition(COORD coor);
	COORD getExitPosition();    // set the exit position coordinate!
private:
	char m_cWall;				   // Wall
	char m_cRoad;				   // Road
	int** m_pMaze;		 		   // the point to the maze
	int m_iMazeRow;		 		   // the Row of the maze
	int m_iMazeCol;				   // the Column of the maze
	COORD m_coordExitPosition;     // the exit position coordinate
};

#endif MAZEMAP_H