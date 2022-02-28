#include <stdio.h>

/*
//查找二维数组matrix是否有目标元素
int searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize, n = *matrixColSize;
    //k是二维数组的一维展开位置
    int i = 0, j = 0, k = 0;
    int low = 0, high = m * n - 1;
    //枢轴，靠左
    int pivot = (low + high) / 2;
    //二分查找
    while (low <= high) {
        pivot = (low + high) / 2;
        i = pivot / n;
        j = pivot % n;
        if (low <= high && matrix[i][j] == target) return 1;
        //target在枢轴右侧
        else if (low <= high && matrix[i][j] < target) low = pivot + 1;
        else if (low <= high && matrix[i][j] > target) high = pivot - 1;
    }
    return 0;
}

int main() {
    int matrix1[1][1] = { 1 };
    int i = 1;
    int j = searchMatrix(matrix1, 1, &i, 0);
    printf("%d", j);
    return 0;
}


*/