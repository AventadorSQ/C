#ifndef __GAME_H__
#define __GAME_H__

#include<Aventador_SQ.h>

#define ROW 3
#define COL 3


void Display(char arr[ROW][COL], int row, int col);//��ӡ����
void InitBoard(char arr[ROW][COL], int row, int col);//��ʼ������
void ComputerMove(char arr[ROW][COL]);
void PlayerMove(char arr[ROW][COL], int row, int col);//�����
char IsWin(char arr[ROW][COL], int row, int col);//�ж���Ӯ

#endif