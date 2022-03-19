#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void bubbleSort(int* arr, int arrSize) {
	//当一趟排序不发生元素交换，则arr已有序
	int flag;
	do {
		flag = 0;
		//控制趟数
		for (int i = 0; i < arrSize - 1; i++) {
			//每趟结束都将最大值放入末尾
			for (int j = 0; j < arrSize - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					flag = 1;
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	} while (flag);
}

int main() {
	int arr[] = { 5,6,7,5,1,4,6,9,15,3854,12,456,12 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubbleSort(arr, arrSize);
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}