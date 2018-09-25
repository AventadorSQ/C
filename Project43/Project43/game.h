#ifndef __GAME_H__
#define __GAME_H__

#include<Aventador_SQ.h>

#define ROW 10
#define COL 10//10*10�ķ���

#define ROWS 5
#define COLS 5//������

void Display(char arr[ROW][COL], int row, int col);//��ӡ����
void InitBoard(char arr[ROW][COL], int row, int col);//��ʼ������
void ComputerMove(char arr[ROW][COL]);
void PlayerMove(char arr[ROW][COL], int row, int col);//�����
char IsWin(char arr[ROW][COL], int row, int col);//�ж���Ӯ

#endif