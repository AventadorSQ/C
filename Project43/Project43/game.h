#ifndef __GAME_H__
#define __GAME_H__

#include<Aventador_SQ.h>

#define ROW 10
#define COL 10//10*10的方格

#define ROWS 5
#define COLS 5//五子棋

void Display(char arr[ROW][COL], int row, int col);//打印棋盘
void InitBoard(char arr[ROW][COL], int row, int col);//初始化棋盘
void ComputerMove(char arr[ROW][COL]);
void PlayerMove(char arr[ROW][COL], int row, int col);//玩家走
char IsWin(char arr[ROW][COL], int row, int col);//判断输赢

#endif