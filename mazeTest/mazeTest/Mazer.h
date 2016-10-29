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
	void moveForward(char direction);		//���ݴ���ķ���ʹ��Ϸ��ɫ�ƶ�һ��
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