#ifndef __GAME_H__
#define __GAME_H__

#include<Aventador_SQ.h>

#define ROW 3
#define COL 3


void Display(char arr[ROW][COL], int row, int col);//¥Ú”°∆Â≈Ã
void InitBoard(char arr[ROW][COL], int row, int col);//≥ı ºªØ∆Â≈Ã
void ComputerMove(char arr[ROW][COL]);
void PlayerMove(char arr[ROW][COL], int row, int col);//ÕÊº“◊ﬂ
char IsWin(char arr[ROW][COL], int row, int col);//≈–∂œ ‰”Æ

#endif