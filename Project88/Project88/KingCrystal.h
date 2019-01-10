#pragma once

#include<Aventador_SQ.h>
#include<mmsystem.h>
#include<conio.h>

#pragma comment(lib,"winmm.lib")

//1.打印菜单
void menu(int* count);

//2.清空上层输出
void Clean();

//3.方式1抽奖
int probability(int* count);

//4.方式2抽奖
int probability_1(int* count);

//5.充值函数
int VoucherCenter();

//6.播放音乐
void MyPlaySound();

//7.中断音乐
void ZhongDuanSound();

