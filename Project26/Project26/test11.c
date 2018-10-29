//**************************************************************
//1.
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//**************************************************************
//#include<Aventador_SQ.h>
//
//void MingCi()
//{
//	int arr[5] = { 0 };
//	//if (((arr[0] == 3) + (arr[1] == 2) == 1) + ((arr[1] == 2) + (arr[4] == 4) == 1) + ((arr[2] == 1) + (arr[3] == 2) == 1) + ((arr[2] == 3) + (arr[3] == 3) == 1) +
//	//	((arr[4] == 4) + (arr[0] == 1) == 1) == 5)
//	//{
//	//	printf("A=%d,B=%d,C=%d,D=%d,E=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);
//	//}
//	for(arr[0] = 1; arr[0] <= 5; arr[0]++)
//		for (arr[1] = 1; arr[1] <= 5; arr[1]++)
//			for (arr[2] = 1; arr[2] <= 5; arr[2]++)
//				for (arr[3] = 1; arr[3] <= 5; arr[3]++)
//					for (arr[4] = 1; arr[4] <= 5; arr[4]++)
//					{
//						if (((arr[0] == 3) + (arr[1] == 2) == 1) + ((arr[1] == 2) + (arr[4] == 4) == 1) + ((arr[2] == 1) + (arr[3] == 2) == 1) + ((arr[2] == 3) + (arr[3] == 3) == 1) +
//							((arr[4] == 4) + (arr[0] == 1) == 1) == 5)
//						{
//							if (arr[0] * arr[1] * arr[2] * arr[3] * arr[4] == 120)
//							{
//								printf("A=%d,B=%d,C=%d,D=%d,E=%d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
//							}
//						}
//					}
//}
//int main()
//{
//	MingCi();
//	system("pause");
//	return 0;
//}
//**************************************************************
//2.
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//**************************************************************
//**************************************************************
//3.在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
///*************************************************************

//#include<Aventador_SQ.h>
//
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("%d %d %d\n", a, b, c);
//	system("pause");
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
//扫雷游戏
#define ROW 9
#define COL 9
#define MINE_COUNT  10 
char mine_map[ROW + 2][COL + 2];
// ow_map, 使用'*', 表示未打开的方块，对打开方块，就是用具体
char show_map[ROW + 2][COL + 2];
int Menu()
{
	int choice = 0;
	printf("1.开始游戏\n");
	printf("2.退出游戏\n");
	printf("请输入您的选择：\n");
	scanf("%d", &choice);
	return choice;
}
//使用二维数组来表示扫雷的地图
//第一个二维数组来表示扫雷扫雷的地图的雷阵
//第二个二维数组来表示用户看到的地图
//扫雷的地图大小是9*9，但是我们把这个二维数组定义成11*11
//此时，我们的地图的有效范围[1,ROW]和[1,COL]
//对于mine_map,使用'0'表示不是地雷，使用'1'表示是地雷
//char mine_map[ROW + 2][COL + 2];
//// ow_map, 使用'*', 表示未打开的方块，对打开方块，就是用具体
//char show_map[ROW + 2][COL + 2];

void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2]) {
	//1.初始化地图(mine_map,show_map),布置雷阵
	//对于mine_map,先把有的元素都设置成'0'
	memset(mine_map, '0', (ROW + 2)*(COL + 2));
	//对于show_mine，先把所有的元素设置成'*'
	memset(show_map, '0', (ROW + 2)*(COL + 2));

//2.随机布置雷阵
srand((unsigned int)time(NULL));//随机种子
int mine_count = MINE_COUNT;
while (mine_count > 0) {
	//在这个循环中随机设置地雷，每次设置完成一个，就--mine_count
	int row = rand() % 9 + 1;
	int col = rand() % 9 + 1;
	if (mine_map[row][col] == '0') {
		mine_map[row][col] = '1';
		--mine_count;
	}
  }
}
void DisplayMap(char map[ROW + 2][COL + 2]) {
	//打印第一行的内容，四个空格+每一列的坐标
	printf("    ");
	for (int col = 1; col <= COL; ++col) {
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 1; col <= COL; ++col) {
		printf("———");
	}
	printf("\n");
	//打印具体的地图
	//打印第二行，地图的上边框
	//按行打印地图中的具体内容
	for (int row = 1; row <= ROW; ++row) {
		//先打印出行号
		//1=>01    10=>10
		printf("%02d| ", row);
		for (int col = 1; col <= COL; ++col) {
			printf("%c ", map[row][col]);
		}
	}
	//for (int col = 1; col <= COL; ++col) {
	//	printf("%c ", map[row][col]);
	//}
	printf("\n");
}
//需要统计row,col位置的元素周围有几个雷，并且把结果更新到show_map中

void Game()
{
	//1.初始化地图(mine_map,show_map),布置雷阵
	//2.先打印 show_map
	//DisplayMap( map[ROW + 2][COL + 2]) {
	DisplayMap( show_map);
	{
		while (1)
		{
			//3.提示用户进行输入坐标[1,ROW][1,COL]
			int row = 0;
			int col = 0;
			printf("请输入要翻开的方块坐标（row,col):");
			scanf("%d %d", &row, &col);
			//4.对用户输入的合法性进行判断，如果不合理，提示用户重新输入
			if (row <= 0 || row > ROW || col<0 || col>COL)
			{
				printf("你的输入吧合法！请重新输入！\n");//你怎么这么秀呢？2018.10.29 Aventador_SQ
				continue;
			}

		}
	}


	//5.判定玩家当前是否踩雷，如果踩雷，游戏结束，并且打印雷阵
	if (mine_map) {
		//6.如果没有踩雷，判定一下玩家是否胜利，还要注意胜利的条件
		int not_mine_count = 0;
		++not_mine_count;
		if (not_mine_count == ROW * COL - MINE_COUNT) {
			printf("扫雷成功！\n");
			DisplayMap(mine_map);
			/*break;*/
		}
	}
}
//7.如果游戏没有胜利，就需要统计当前的位置周围有几个雷，并把结果更新到show_map中
void UpdateShowMap(char map[ROW + 2][COL + 2],
	char mine_map[ROW + 2][COL + 2], int row, int col) {
	int mine_count = 0;
	if (mine_map[row - 1][col - 1] == '1') {
		++mine_count;
	}

}

void start()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 0) {
			printf("退出游戏!\n");
			break;
		}
      		Game();
	}
}
