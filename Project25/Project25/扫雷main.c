#include"扫雷头文件.h"

int count = 0;
void Game()
{
	//初始化游戏
	char ArrLeiMap[ROW][COL];
	char ArrShowMap[ROW][COL];
	srand((unsigned int)time(NULL));
	InitQiPan(ArrLeiMap, ROW, COL);//初始化雷盘
	InitShowPan(ArrShowMap, ROW, COL);//初始化用户界面盘
	PrintShow(ArrShowMap, ROW, COL);//打印展示的界面棋盘
	while (1)
	{
		Scanf(ArrShowMap, ArrLeiMap, ROW, COL, &count);//玩家猜游戏
		IsWin(ArrShowMap, ArrLeiMap, ROW, COL, &count);//判断输赢
		PrintShow(ArrShowMap, ROW, COL);//打印更新的界面棋盘
	}
}
int main()
{
	int Select = 0;//选择开关
	//播放游戏音乐
	MyPlaySound();

	//扫雷初始界面
	Select=Menu(&Select);

	//选择是否开始游戏
	IsPlay(&Select);
	//开始游戏
	//Game();
	//判断输赢
	//结束游戏
	system("pause");
	return 0;
}