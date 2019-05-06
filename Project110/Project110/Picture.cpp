/*
  制作相册项目
  项目流程：
  1、加载资源
  2、画按钮
  3、提示图片
  4、用户交互（点击按钮事件）
*/

//C语言标准头文件
//图形库头文件: graphics.h
//数学函数: math.h
//播放音乐:mmsystem.h
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

//*****************************************************
//3.画按钮
//x,y 按钮位置。postion 是左右方向按钮
void DrawButton(int x, int y, char postion);
//4.用户操作鼠标
void UserMoveMouse();
//5.处理鼠标是否在按钮上
void ClickButton(int x, int y, char postion);
//6.显示小图片边框以方便知道切换到哪一个
void DrawRect(int flag);
//******************************************************


//**************************************
//背景：需要一个变量
//N张大图片：数组长度为N变量
//N张小图片：数组长度为N变量
//**************************************

//存放背景
IMAGE backImg;
//存放四张大图片
IMAGE BigPicture[6];
//存放四张小图片
IMAGE SmallPicture[6];
//记录翻看图片的页码
int SmallNum = 0;

//**************************************
//封装函数初始化数据：初始化变量
//加载资源
//loadResource()
//**************************************
//1.加载资源
void loadResource()
{

	//加载音乐
	mciSendString("open 1.mp3 alias music", 0, 0, 0);
	mciSendString("play music repeat", 0, 0, 0);

	loadimage(&backImg, "background.jpg");
	//批量加载：通过文件名称格式
	for (int i = 0; i < 6; i++)
	{
		char FileName[1024] = "";
		sprintf(FileName, "%d.jpg", i);
		loadimage(BigPicture + i, FileName, 250, 350);
		loadimage(SmallPicture + i, FileName, 100, 130);
	}
}

//**************************************
//初始化界面
//画界面
//DrawMap();
//**************************************
//2.画界面
void DrawMap()
{
	//画背景
	putimage(0, 0, &backImg);
	//画小图
	putimage(90, 160, SmallPicture + 0);
	putimage(90, 310, SmallPicture + 1);

	//画大图
	/*putimage(345, 310, BigPicture + 0);*/
	putimage(350, 105, BigPicture + 0);

	//3.画按钮
	//x,y 按钮位置。postion 是左右方向按钮
	DrawButton(170, 130, 'r');
	DrawButton(110, 130, 'l');

	//文字：宣言
	//设置文字颜色
	settextcolor(LIGHTRED);
	//设置字体和大小
	settextstyle(25, 0, "STXINGKA.TTF");
	//去掉文字背景，设置文字背景为透明
	setbkmode(TRANSPARENT);
	//设置宣言
	outtextxy(365, 50, "与宝宝一起走过的日子");
}

//**************************************
//处理用户交互
//鼠标操作
//UserMoveMouse();
//**************************************
//4.用户操作鼠标
void UserMoveMouse()
{
	int flag = 1;
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
			//鼠标移动
		case WM_MOUSEMOVE:
			//鼠标是否在按钮上：判断鼠标是不是在圆里面
			if (sqrt((double)(m.x - 170)*(m.x - 170) + (m.y - 130)*(m.x - 130)) < 22)
			{
				ClickButton(170, 130, 'r');
			}
			else if (sqrt((double)(m.x - 110)*(m.x - 110) + (m.y - 130)*(m.x - 123)) < 22)
			{
				ClickButton(110, 130, 'l');
			}
			else //当鼠标不在按钮上
			{
				DrawButton(170, 130, 'r');
				DrawButton(110, 130, 'l');
			}
			break;
			//鼠标按下
		case WM_LBUTTONDOWN:
			if (sqrt((double)(m.x - 170)*(m.x - 170) + (m.y - 130)*(m.x - 130)) < 22)
			{
				DrawRect(flag);
				//图片全部放完循环
				if (SmallNum == 6)
				{
					//显示前两张小图片
					putimage(90, 160, SmallPicture + 0);
					putimage(90, 310, SmallPicture + 1);
					SmallNum = 0;
				}
				if (SmallNum == 2)
				{
					putimage(90, 160, SmallPicture + 2);
					putimage(90, 310, SmallPicture + 3);
				}
				if (SmallNum == 4)
				{
					putimage(90, 160, SmallPicture + 4);
					putimage(90, 310, SmallPicture + 5);
				}
				putimage(350, 105, BigPicture + SmallNum);
				SmallNum++;
			}
			else if (sqrt((double)(m.x - 110)*(m.x - 110) + (m.y - 130)*(m.x - 123)) < 22)
			{
				DrawRect(flag);
				//图片全部放完循环
				if (SmallNum == -1)
				{
					//显示前两张小图片
					putimage(90, 160, SmallPicture + 5);
					putimage(90, 310, SmallPicture + 4);
					SmallNum = 5;
				}
				if (SmallNum == 3)
				{
					putimage(90, 160, SmallPicture + 3);
					putimage(90, 310, SmallPicture + 2);
				}
				if (SmallNum == 1)
				{
					putimage(90, 160, SmallPicture + 1);
					putimage(90, 310, SmallPicture + 0);
				}
				putimage(350, 105, BigPicture + SmallNum);
				SmallNum--;
			}
			flag++;
			if (flag > 2)
			{
				flag = 1;
			}
			break;
		}
	}
}

//**************************************
//鼠标停留在按钮上，以及鼠标离开按钮的处理
//处理用户交互
//ClickButton();
//**************************************
//5.处理鼠标是否在按钮上
void ClickButton(int x,int y,char postion)
{
	//设置填充颜色
	setfillcolor(BLUE);
	//以xy为坐标画一个22半径的圆
	solidcircle(x, y, 22);
	//设置线的颜色灰色
	setlinecolor(LIGHTRED);
	//设置线的格式
	setlinestyle(PS_SOLID, 4, 0);
	if (postion == 'l')
	{
		circle(x, y, 16);
		line(x - 10, y, x + 10, y);
		line(x - 4, y - 4, x - 10, y);
		line(x - 4, y + 4, x - 10, y);
	}
	else if (postion == 'r')
	{
		circle(x, y, 16);
		line(x - 10, y, x + 10, y);
		line(x + 4, y - 4, x + 10, y);
		line(x + 4, y + 4, x + 10, y);
	}
}

//**************************************
//画矩形
//小图片的矩形
//DrawRect();
//**************************************
//6.显示小图片边框以方便知道切换到哪一个
void DrawRect(int flag)
{
	if (flag == 1)
	{
		setlinecolor(LIGHTRED);
		//画小图
		//putimage(90, 160, SmallPicture + 0);
		//putimage(90, 310, SmallPicture + 1);
		//边框的位置大小
		rectangle(85, 155, 90 + 100 + 5, 130 + 160 + 5);
		setlinecolor(WHITE);
		rectangle(85, 305, 90 + 100 + 5, 130 + 310 + 5);
	}
	else if (flag == 2)
	{
		setlinecolor(LIGHTRED);
		//画小图
		//putimage(90, 160, SmallPicture + 0);
		//putimage(90, 310, SmallPicture + 1);
		//边框的位置大小
		rectangle(85, 305, 90 + 100 + 5, 130 + 310 + 5);
		setlinecolor(WHITE);
		rectangle(85, 155, 90 + 100 + 5, 130 + 160 + 5);
	}
}

//**************************************
//按钮处理
//画按钮
//DrawButton();
//**************************************
//3.画按钮
//x,y 按钮位置。postion 是左右方向按钮
void DrawButton(int x,int y,char postion)  
{
	//设置填充颜色
	setfillcolor(BLUE);
	//以xy为坐标画一个22半径的圆
	solidcircle(x, y, 22);
	//设置线的颜色白色
	setlinecolor(WHITE);
	//设置线的格式
	setlinestyle(PS_SOLID, 4, 0);
	if (postion == 'l')
	{
		circle(x, y, 16);
		line(x - 10, y, x + 10, y);
		line(x - 4, y - 4, x - 10, y);
		line(x - 4, y + 4, x - 10, y);
	}
	else if (postion == 'r')
	{
		circle(x, y, 16);
		line(x - 10, y, x + 10, y);
		line(x + 4, y - 4, x + 10, y);
		line(x + 4, y + 4, x + 10, y);
	}
}

int main()
{
	//设置窗口大小
	initgraph(932, 538);
	//声明IMAGE变量去存储图片
	//1.加载资源
	loadResource();

	//2.画界面
	DrawMap();

	//4.用户操作鼠标
	UserMoveMouse();


	system("pause");
	return 0;
}
//IMAGE img;
////加载图片
////loadimage(&img, "background.jpg"); 

////以缩放的形式加载图片
//loadimage(&img, "background.jpg", 932, 538);
////显示图片
//putimage(0, 0, &img);