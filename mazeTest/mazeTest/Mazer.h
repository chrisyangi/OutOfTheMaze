#include <Windows.h>
#include "MazeMap.h"
class Mazer
{
public:
	Mazer(char mazer);
	bool walkUp();
	bool walkDown();
	bool walkLeft();
	bool walkRight();
	void setPosition(int x , int y);
	void setDirection(char direction);
	void moveForward(char direction);		//根据传入的方向使游戏角色移动一步
	void setMap(MazeMap *map);
	void start();
	int getSteps();
private:
	char m_cMazer;
	char m_cMazerFace;
	COORD m_cMazerCurrentLocation;
	int m_iStep;
	MazeMap* m_pMap;
};