#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<mmsystem.h>
#include<conio.h>

#pragma comment(lib,"winmm.lib")

//1.打印开始游戏界面
void FirstPage();

//2.播放音乐
void MyPlaySound();

//3.空格键开始游戏并停止播放音乐
void SpaceKey();

//4.停止播放音乐
void StopMusic();

//5.清空界面
void CLear();

//6.打印背景边框
void PrintBackground();

//7.设置蛇的随机位置
void SetSnakeRandPos();