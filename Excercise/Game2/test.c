#include "game2.h"

//测试
int main() {
	int input;
	do {
		printf("**************************************\n");
		printf("*********    0、退出游戏   ***********\n");
		printf("*********    1、开始游戏   ***********\n");
		printf("**************************************\n");
		//getchar();
		scanf("%d", &input);
		switch (input) {
		case 1:
			srand((unsigned int)time(NULL));
			startGame2();
			break;
		case 0:
			printf("游戏已退出！\n");
			break;
		default:
			printf("输入不合法，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}