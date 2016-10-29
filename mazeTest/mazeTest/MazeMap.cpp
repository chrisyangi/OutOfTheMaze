#include "MazeMap.h"
#include <iostream>
using namespace std;



MazeMap::MazeMap(char wall , char road)
{
	m_cWall = wall;
	m_cRoad = road;
	m_pMaze = NULL;
}

MazeMap::~MazeMap()
{
	for (int i = 0; i < m_iMazeRow; i++)
	{
		delete[] m_pMaze[i];
		m_pMaze[i] = NULL;
	}
	delete[]  m_pMaze;
	
}

bool MazeMap::setMaze(int *maze, int row, int col)
{
	if (row <= 0 || col <= 0)
	{
		return false;
	}
	m_iMazeRow = row;
	m_iMazeCol = col;
	m_pMaze = new int*[m_iMazeCol * m_iMazeRow];
	for (int i = 0; i < m_iMazeRow; i++)
	{
		//将指针数组中的指针指向长度为m_iMapCol的int数组
		m_pMaze[i] = new int[m_iMazeCol];
	}
	int* temp = maze;
	for (int i = 0; i < m_iMazeRow; ++i)
	{
		for (int j = 0; j < m_iMazeCol; ++j)
		{
			m_pMaze[i][j] = *temp;
			temp++;
		}
	}
}

void MazeMap::printMaze()
{
	for (int i = 0; i < m_iMazeRow; ++i)
	{
		for (int j = 0; j < m_iMazeCol; ++j)
		{
			if (m_pMaze[i][j] == 1)
			{
				cout << m_cWall;
			}
			else
			{
				cout << m_cRoad;
			}
		}
		cout << endl;
	}
}

int** MazeMap::getMaze()
{
	return m_pMaze;
}

void MazeMap::setExitPosition(COORD coor)
{
	m_coordExitPosition = coor;
}

COORD MazeMap::getExitPosition()
{
	return m_coordExitPosition;
}