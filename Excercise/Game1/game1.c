//游戏本体
#include "game1.h"

int main()
{
	int sel = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("********************************************\n");
		printf("*************  是否开始游戏    ***************\n");
		printf("*************    1     是    ***************\n");
		printf("*************    0     否    ***************\n");
		printf("********************************************\n");
		printf("请输入：\n");
		scanf("%d", &sel);
		switch (sel)
		{
		case 0:
			printf("游戏已关闭！\n");
			return 0;
		case 1:
			printf("开始三子棋游戏\n");
			game1Start();
			break;
		default:
			printf("输入非法，请重新输入\n");
		}
	} while (sel);
}