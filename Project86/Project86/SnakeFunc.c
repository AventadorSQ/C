#include"Snake.h"

//1.打印开始游戏界面
void FirstPage()
{
	printf("\n\n\n\n\n");
	printf("\t\t\t 《欢迎进入贪吃蛇游戏》\n\n");
	printf("\t\t\t  《按空格键开始游戏》\n\n");
	printf("\t\t\t《w a s d 控制蛇的方向》\n\n");
}

//2.播放音乐
void MyPlaySound()
{
	PlaySound("庄心妍 - 断了乱了.wav", NULL, SND_FILENAME | SND_ASYNC);
}