#define _CRT_SECURE_NO_WARNINGS 1
/*
	改写qsort()
		- 将指针的形参定为void*，在进行运算时将指针视为char*
		- 用冒泡排序模拟
*/
#include<stdio.h>
void quick_sort(void*, int, int, int(*)(const void*, const void*));

void swich(void* a, void* b, int sz) {
	for (int i = 0; i < sz; i++) {
		char temp = *((char*)b + i);
		*((char*)b + i) = *((char*)a + i);
		*((char*)a + i) = temp;
	}
	return;
}

void bubble_sort(void* base, int num, int size, int (*compar)(const void*, const void*)) {
	for (int i = num; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (compar((char*)base + j * size, (char*)base + (j + 1) * size) > 0) {
				swich((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
	return;
}

int cmp_int(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int cmp_char(const void* a, const void* b) {
	return (*(char*)a - *(char*)b);
}

int main() {
	int arr[] = { 5,6,7,5,1,4,6,9,15,3854,12,456,12 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubble_sort(arr, arrSize, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n-----------int test-----------\n");
	char ch[] = "alkjhdfglkjasdfbhhjasgf";
	int chSize = sizeof(ch) / sizeof(ch[0]);
	printf("%s\n",ch);
	bubble_sort(ch, chSize-1, sizeof(ch[0]), cmp_char);
	printf("%s",ch);
	printf("\n----------char test-----------\n");
	int arr2[] = { 5,6,7,5,1,4,6,9,15,3854,12,456,12 };
	arrSize = sizeof(arr2) / sizeof(arr[0]);
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");
	quick_sort(arr2, arrSize, sizeof(arr2[0]), cmp_int);
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n----------quic test-----------\n");
	return 0;
}