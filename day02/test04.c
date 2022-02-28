#include<stdio.h>

//二维数组测试

int arrTest01(int** arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("01--> arr[%d][%d] = %d   ", i, j, *((int*)arr + i * n + j));
		}
		printf("\n");
	}
}

int arrTest02(int arr[2][3], int m,int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("02--> arr[%d][%d] = %d   ", i, j, arr[i][j]);
		}
		printf("\n");
	}
}

int arrTest03(int arr[][3], int m,int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("03--> arr[%d][%d] = %d   ", i, j, arr[i][j]);
		}
		printf("\n");
	}
}

/*
int main() {
	int arr[2][3] = { {4,5,6},{8,9,10} };
	arrTest01(arr, 2, 3);
	arrTest02(arr, 2, 3);
	arrTest03(arr, 2, 3);

	return 0;
}
*/