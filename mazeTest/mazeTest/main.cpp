#include "MazeMap.h"
#include "Mazer.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
2016/10/29
���Թ���
Complete��
�պ�ѧ��Щ���������ƣ�
By Chris  
����ԭ���ӣ�http://eksea.com/2015/12/26/cpptraining001/ 
  ��лԭ���ߣ�����
 ��

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
	//���õ�ͼ�����еĵ�ͼ
	mm->setMaze(&map[0][0], 11, 11);
	//���õ�ͼ�ĳ���
	mm->setExitPosition(exitPosition);
	mm->printMaze();

	Mazer *mzer = new Mazer('o');
	mzer->setPosition(10, 1);
	mzer->setDirection('D');
	mzer->setMap(mm);
	mzer->start();
	cout << "һ������" << mzer->getSteps() << "��" << endl;

	delete mzer;
	mzer = NULL;

	delete mm;
	mm = NULL;

	system("pause");
	return 0;
}
