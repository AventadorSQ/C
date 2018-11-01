#pragma once

#include<Aventador_SQ.h>
#include<mmsystem.h>
#include<conio.h>

#pragma comment(lib,"winmm.lib")

#define ROW 10
#define COL 10


void MyPlaySound();//播放音乐
int Menu(int* Select);//打印菜单
void IsPlay(int* Select);//判断是否开始游戏
void Game();//开始游戏
void InitQiPan(char ArrLeiMap[ROW][COL]);//初始化雷盘
void InitShowPan(char ArrShowMap[ROW][COL], int row, int col);//初始化用户界面盘
void PrintShow(char ArrShowMap[ROW][COL], char ArrLeiMap[ROW][COL], int row, int col);//打印展示的界面棋盘/雷盘
void Scanf(char ArrShowMap[ROW][COL], char ArrLeiMap[ROW][COL], int* ScanfRow, int* ScanfCol,int* count);//玩家猜游戏
void IsWin(char ArrShowMap[ROW][COL],char ArrLeiMap[ROW][COL], int* ScanfRow, int* ScanfCol,int* count);//判断输赢
