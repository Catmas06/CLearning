#include "game1.h"
/*
测试游戏逻辑

*/

int flag = 1;

//打印棋盘界面
void print_p(char chessboard[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("| %c ", chessboard[i][j]);
		}
		printf("|\n");
		for (int j = 0; j < col; j++)
		{
			printf("|---");
		}
		printf("|\n");
	}
}

//初始化棋盘
void initChessboard(char chessboard[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			chessboard[i][j] = ' ';
		}
	}
}

//落子
void chessDown(char chessboard[row][col], int x, int y, char ch)
{
	chessboard[x - 1][y - 1] = ch;
	print_p(chessboard);
}

//判胜负
// flag三种状态： 0，胜出 1，继续 -1，平局
void isWin(char chessboard[row][col])
{
	//是否胜出
	int count, i, j;

	//是否行相连胜出
	for (i = 0; i < row; i++)
	{
		count = 1;
		j = 0;
		while (j < col - 1)
		{
			if (chessboard[i][j] == chessboard[i][j + 1] && chessboard[i][j] != ' ')
			{
				count++;
			}
			j++;
		}
		if (count == col)
		{
			flag = 0;
			return;
		}
	}

	//是否列相连胜出
	for (j = 0; j < col; j++)
	{
		count = 1;
		i = 0;
		while (i < row - 1)
		{
			if (chessboard[i][j] == chessboard[i + 1][j] && chessboard[i][j] != ' ')
			{
				count++;
			}
			i++;
		}
		if (count == row)
		{
			flag = 0;
			return;
		}
	}

	//是否对角相连胜出
	count = 1;
	for (i = 0; i < row - 1; i++)
	{
		if (chessboard[i][i] == chessboard[i + 1][i + 1] && chessboard[i][i] != ' ')
			count++;
	}
	if (count == row)
	{
		flag = 0;
		return;
	}

	count = 1;
	i = 0;
	j = col - 1;
	while (i < row - 1 && j > 0)
	{
		if (chessboard[i][j] == chessboard[i + 1][j - 1] && chessboard[i][j] != ' ')
			count++;
		i++;
		j--;
	}
	if (count == row)
	{
		flag = 0;
		return;
	}

	//是否平局
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (chessboard[i][j] == ' ')
				return;
		}
	}
	flag = -1;
	return;
}

//开始游戏
void game1Start()
{
	flag = 1;
	char chessboard[row][col];

	//初始化棋盘
	initChessboard(chessboard);
	int x, y;

	//打印棋盘
	print_p(chessboard);
	//玩家走
	printf("请输入坐标：         【示例：x,y】\n");
	while (flag == 1)
	{
		printf("\n玩家走：");
		while (flag == 1)
		{
			getchar();
			scanf("%d,%d", &x, &y);
			if (x > 0 && x <= row && y > 0 && y <= col && chessboard[x - 1][y - 1] == ' ')
			{
				chessboard[x - 1][y - 1] = '#';
				print_p(chessboard);
				break;
			}
			else
				printf("输入坐标不合法，请重新输入：\n");
		}

		//判断玩家是否胜利或平局
		isWin(chessboard);
		if (flag == 0)
		{
			printf("玩家胜出！\n");
			return;
		}
		else if (flag == -1)
		{
			printf("平局！\n");
			return;
		}

		//电脑走
		printf("\n电脑走：");
		fflush(stdout);
		sleep(1);
		printf("-");
		fflush(stdout);
		sleep(1);
		printf("-");
		fflush(stdout);
		sleep(1);
		printf("-");
		fflush(stdout);
		sleep(1);
		printf("-");
		fflush(stdout);
		sleep(1);
		printf(">\n");
		while (flag == 1)
		{
			x = rand() % row;
			y = rand() % col;
			if (chessboard[x][y] == ' ')
			{
				chessboard[x][y] = '*';
				print_p(chessboard);
				break;
			}
		}

		//判断电脑是否胜利或平局
		isWin(chessboard);
		if (flag == 0)
		{
			printf("电脑胜出！\n");
			return;
		}
		else if (flag == -1)
		{
			printf("平局！\n");
			return;
		}
	}
}