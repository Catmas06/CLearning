#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

void pointTest02() {
	int a[5] = { 1,2,3,4,5 };
	{//数组名a是首元素地址，可通过a+n是首元素后n位的地址，再解引用可得第n位数据
		printf("*(a+1) = %d\n", *(a + 1));
		printf("a[1] = %d\n", a[1]);

	}
	int b[] = { 2,3,4,5,6 };
	int c[] = { 5,9,100 };
	//arr是一个指针数组，其中的每个元素都是一个数组指针
	int* arr[3] = { a,b,c };
	
	{//指针数组和数组指针的区别
		int arr[10] = { 1,2,3,4 };
		//parr1先与[10]结合，表明这是个数组。数组内有10个元素，每个元素是int*
		int* parr1[10] = { 0 };
		//parr2先与*结合，表明这是个指针，指向了一个数组。数组内有10个元素，每个元素是int
		int(*parr2)[10] = &arr;	//parr2是一个数组指针，存放了一个数组地址
	}
	{//例2
		double* d[5];
		double*(*pd)[5] = &d;
	}

	{//数组名与&数组名，arr与&arr的值一样，但类型不一样
		int arr[10] = { 0 };
		printf("%p\n", arr);	//是数组首元素的地址
		printf("%p\n", &arr);	//是数组的地址
	}
}

//int main() {
//	int i;
//	int* pi = &i;
//	pointTest02();
//	return 0;
//}