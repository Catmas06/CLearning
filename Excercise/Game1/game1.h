#define _CRT_SECURE_NO_WARNINGS 1
//关于游戏的函数声明、符号声明
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define col 10
#define row 10

//打印棋盘界面
void print_p(char chessboard[row][col]);

//初始化棋盘
void initChessboard(char chessboard[row][col]);

//判断胜负
void isWin(char chessboard[row][col]);

//游戏本体
void game1Start();