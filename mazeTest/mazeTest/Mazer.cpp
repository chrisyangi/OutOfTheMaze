#include "Mazer.h"
#include <Windows.h>
#include <iostream>
using namespace std;

Mazer::Mazer(char mazer)      //initialization mazer . step = 0 ;
{
	m_cMazer = mazer;
	m_iStep = 0;
}

void Mazer::moveForward(char direction)	   // move mazer ;
{
	DWORD charsWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);		//set the output handle ;
	FillConsoleOutputCharacter(handle, ' ', 1, m_cMazerCurrentLocation, &charsWritten);

	switch (direction)
	{
	case 'U':
		m_cMazerCurrentLocation.Y -= 1;
		break;
	case 'D':
		m_cMazerCurrentLocation.Y += 1;
		break;
	case 'L':
		m_cMazerCurrentLocation.X -= 1;
		break;
	case 'R':
		m_cMazerCurrentLocation.X += 1;
	default:
		break;
	}
	FillConsoleOutputCharacterA(handle, m_cMazer, 1, m_cMazerCurrentLocation, &charsWritten);
	m_cMazerFace = direction;

}

void Mazer::setPosition(int x, int y)	  // set the starting point;
{
	DWORD charsWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	m_cMazerCurrentLocation.X = x;
	m_cMazerCurrentLocation.Y = y;
	FillConsoleOutputCharacter(handle, m_cMazer, 1, m_cMazerCurrentLocation, &charsWritten);
}

void Mazer::setDirection(char direction)
{
	m_cMazerFace = direction;
}

void Mazer::setMap(MazeMap *map)
{
	m_pMap = map;
}

int Mazer::getSteps()
{
	return m_iStep;
}

/*
		Walk up . Y-1 ,X don`t change;
		m_pMap->getMaze() <==> m_pMaze;
		m_pMaze[][] == 1(WALL) -> false;
		m_pMaze[][] == 0(ROAD) -> true;
*/
bool Mazer::walkUp()
{
	if (m_pMap->getMaze()[m_cMazerCurrentLocation.Y - 1][m_cMazerCurrentLocation.X]) 
	{
		return false;
	}
	else {
		moveForward('U');
		return true;
	}
}

bool Mazer::walkDown()
{
	if (m_pMap->getMaze()[m_cMazerCurrentLocation.Y + 1][m_cMazerCurrentLocation.X])
	{
		return false;
	}
	else {
		moveForward('D');
		return true;
	}
}

bool Mazer::walkLeft()
{
	if (m_pMap->getMaze()[m_cMazerCurrentLocation.Y ][m_cMazerCurrentLocation.X - 1])
	{
		return false;
	}
	else {
		moveForward('L');
		return true;
	}
}

bool Mazer::walkRight()
{
	if (m_pMap->getMaze()[m_cMazerCurrentLocation.Y ][m_cMazerCurrentLocation.X + 1])
	{
		return false;
	}
	else {
		moveForward('R');
		return true;
	}
}

/*
	depend on right position is WALL or Road ;  

*/
void Mazer::start()
{
	while (true)
	{
		switch (m_cMazerFace)
		{
		case 'U':
			walkRight() || walkUp() || walkLeft() || walkDown();
			break;
		case 'D':
			walkLeft() || walkDown() || walkRight() || walkUp();
			break;
		case 'R':
			walkDown() || walkRight() || walkUp() || walkLeft();
			break;
		case 'L':
			walkUp() || walkLeft() || walkDown() || walkRight();
			break;
		default:
			break;
		}
		m_iStep++;
		//判断游戏角色的当前位置是否是迷宫出口位置，如果到达出口，游戏结束
		if (m_cMazerCurrentLocation.X == m_pMap->getExitPosition().X
			&& m_cMazerCurrentLocation.Y == m_pMap->getExitPosition().Y)
		{
			break;
		}
		Sleep(100);
	}
}