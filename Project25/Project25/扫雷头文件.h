#pragma once

#include<Aventador_SQ.h>
#include<mmsystem.h>
#include<conio.h>

#pragma comment(lib,"winmm.lib")

#define ROW 10
#define COL 10


void MyPlaySound();//��������
int Menu(int* Select);//��ӡ�˵�
void IsPlay(int* Select);//�ж��Ƿ�ʼ��Ϸ
void Game();//��ʼ��Ϸ
void InitQiPan(char ArrLeiMap[ROW][COL]);//��ʼ������
void InitShowPan(char ArrShowMap[ROW][COL], int row, int col);//��ʼ���û�������
void PrintShow(char ArrShowMap[ROW][COL], char ArrLeiMap[ROW][COL], int row, int col);//��ӡչʾ�Ľ�������/����
void Scanf(char ArrShowMap[ROW][COL], char ArrLeiMap[ROW][COL], int* ScanfRow, int* ScanfCol,int* count);//��Ҳ���Ϸ
void IsWin(char ArrShowMap[ROW][COL],char ArrLeiMap[ROW][COL], int* ScanfRow, int* ScanfCol,int* count);//�ж���Ӯ
