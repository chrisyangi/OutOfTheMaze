#include "MazeMap.h"
#include "Mazer.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
2016/10/29
走迷宫！
Complete！
日后学成些许再来完善！
By Chris  
（附原链接：http://eksea.com/2015/12/26/cpptraining001/ 
  感谢原作者！！！
 ）

*/

int main()
{
	int map[11][11] = {
		{ WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL },
		{ WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD },
		{ WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL },
		{ WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL },
		{ WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, WALL },
		{ WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL },
		{ WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, WALL },
		{ WALL, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL },
		{ WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, ROAD, WALL },
		{ ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL },
		{ WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL }
	};

	MazeMap* mm = new MazeMap('N', ' ');

	COORD exitPosition;
	exitPosition.X = 0;
	exitPosition.Y = 9;
	//设置地图对象中的地图
	mm->setMaze(&map[0][0], 11, 11);
	//设置地图的出口
	mm->setExitPosition(exitPosition);
	mm->printMaze();

	Mazer *mzer = new Mazer('o');
	mzer->setPosition(10, 1);
	mzer->setDirection('D');
	mzer->setMap(mm);
	mzer->start();
	cout << "一共走了" << mzer->getSteps() << "步" << endl;

	delete mzer;
	mzer = NULL;

	delete mm;
	mm = NULL;

	system("pause");
	return 0;
}
