#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void boardDisplay(char board[ROWS][COLS], int row, int col);
void initBoard(char board[ROWS][COLS], int rows, int cols, char ch);
void startGame2();