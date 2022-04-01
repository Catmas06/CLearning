#include "game2.h"

//打印棋盘
void boardDisplay(char board[ROWS][COLS], int row, int col) {
	printf(" --------扫雷-------\n");
	int i = 0;
	while (i <= row) {
		printf(" %d", i);
		i++;
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf(" %d", i);
		for (int j = 1; j <= col; j++) {
			if (board[i][j] == 0 + '0') printf("  ");
			else printf(" %c", board[i][j]);
		}
		printf("\n");
	}
	printf(" --------扫雷-------\n");
}

//初始化扫雷棋盘
void initBoard(char board[ROWS][COLS], int rows, int cols, char ch) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = ch;
		}
	}
	//boardDisplay(board,ROW,COL);
}

//放雷
void putBoom(char board[ROWS][COLS], int row,int col,int num) {
	srand((unsigned int)time(NULL));
	int i,j;
	while (num > 0) {
		i = rand() % row + 1;
		j = rand() % col + 1;
		if (board[i][j] == 0 + '0') {
			board[i][j] = 1+ '0';
			num--;
		}
	}
	//boardDisplay(board, ROW, COL);
}

//判断是否踩雷，返回周围雷数量
int isWin(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y) {
	if (board[x][y] == 1 + '0')
		return -1;
	else if (show[x][y] != '*')
		return -2;
	else {
		return	
			board[x - 1][y - 1] - '0' +
			board[x - 1][y] - '0' +
			board[x - 1][y + 1] - '0' +
			board[x][y - 1] - '0' +
			board[x][y + 1] - '0' +
			board[x + 1][y - 1] - '0' +
			board[x + 1][y] - '0' +
			board[x + 1][y + 1] - '0';
	}
}

void startGame2() {
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	initBoard(mine, ROWS, COLS, '0');
	initBoard(show, ROWS, COLS, '*');
	int num = 0;
	while (1) {
		getchar();
		printf("请选择雷的数量（1-80）：");
		scanf("%d", &num);
		if (num > 0 && num < ROW * COL) break;
		else printf("数量非法，请重新输入\n");
	}
	putBoom(mine, ROW, COL, num);
	boardDisplay(show, ROW, COL);   
	//坐标合法取值 1-9
	int x,y,ret;
	while (1) {
		getchar();
		printf("请输入本次排查坐标：");
		scanf("%d,%d", &x, &y);
		//作弊
		if (x == -2147483647) {
			boardDisplay(mine,ROW,COL);
		}
		//输入是否合法
		if (x > 0 && x <= ROW && y > 0 && y <= COL) {
			//判断是否有雷
			ret = isWin(mine, show, ROW, COL, x, y);
			//有雷，游戏结束，打印雷盘 无雷，游戏继续，打印表盘
			switch (ret) {
			case -1:
				printf("很遗憾，被炸身亡！\n请再接再厉\n");
				boardDisplay(mine, ROW, COL);
				return;
			case -2:
				printf("这个坐标已经扫过了，再输入别的试试吧 :)\n");
				break;
			default:
				show[x][y] = ret + '0';
				boardDisplay(show, ROW, COL);
				num++;
				if (num == ROW * COL) {
					printf("恭喜你，扫雷成功！\n");
					boardDisplay(mine, ROW, COL);
					return;
				}
				break;

			}
		}
		else printf("坐标输入不合法，请重新输入！\n");
	}
}