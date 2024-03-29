#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//指针数组和数组指针的区别

//二维数组这样传参 p是一个指针,指向一个数组。数组有五个元素，每个元素类型为int
//p本身是一个地址，可以视为一个数组首元素的地址，可以通过p[0]来访问原二维数组的第一行
void test(int(*p)[5]) {
	printf("test-->p[0]=%d\n", p[0][0]);
}

//用char打印int
void test2(int* p) {
	char* cp = p;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", *(cp + i * 5 + j));
		}
		puts("\n");
	}
}

//总结区别
int main() {
	//整型数组
	int arr[5];

	//整型指针的数组，是一个数组，数组可存放10个元素，每个元素类型为int*
	int* parr1[10];

	//数组指针，该指针能够指向一个数组。数组10个元素，每个元素的类型为int
	int(*parr2)[10];

	//parr3是一个数组，可存放10个元素。每个元素类型为 int(*)[5]
	//即每个元素类型是一个数组指针，每个元素能指向一个数组。数组5个元素，每个元素类型为int
	int(*parr3[10])[5];

	int arr1[3][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	test(arr1);
	test2(arr1);

	//函数指针 - 存放函数地址的指针
	//&函数名，取到的就是函数的地址
	void(*fp)(int(*)[5]) = &test;		//(*fp)表明这是一个指针，()表明指向一个函数，()内为被指向函数的形参，void表明被指向的函数返回值
	void(*fp2)() = &test;				//()内的形参似乎可省略
	printf("函数地址：%p\n", fp);
	printf("函数地址：%p\n", &test);		// 数组名 != &数组名
	printf("函数地址：%p\n", test);		// 函数名  = &函数名
	fp(arr1);

	return 0;
}