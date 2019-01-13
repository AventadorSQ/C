#include"Snake.h"

int main()
{
	//1.打印开始游戏界面
	FirstPage();

	//2.播放音乐
	MyPlaySound();

	//3.空格键开始游戏
	SpaceKey();

	//4.停止播放音乐
	StopMusic();

	//5.清空界面
	CLear();

	//6.打印边框
	while (1)
	{
		CLear();
		PrintBackground();
	}

	system("pause");
	return 0;
}