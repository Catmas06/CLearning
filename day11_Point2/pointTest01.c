#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
	函数指针数组的应用
	以及指向函数指针数组的指针
*/

int add(const int a, const int b) {
	return a + b;
}
int sub(const int a, const int b) {
	return a - b;
}
int mul(const int a, const int b) {
	return a * b;
}
int div(const int a, const int b) {
	return a / b;
}

void test01() {
	//pfArr就是一个函数指针数组
	// pfArr[5] 表明是个数组 int (* )(const int,const int) 表示的数组内存储的元素类型
	int (*pfArr[5])(const int, const int) = { 0,add,sub,mul,div };
	// (*p2)表明p2是个指针，(*p2)[5]表明p2指向了一个数组，剩下的 int(*)(~,~)表明数组内元素类型是函数指针
	int(*(*p2)[5])(const int, const int) = &pfArr;
}

int calculate01() {
	printf("--------------------------------\n");
	printf("---------  计算器程序  ----------\n");
	printf("---------  1    加法   ---------\n");
	printf("---------  2    减法   ---------\n");
	printf("---------  3    乘法   ---------\n");
	printf("---------  4    除法   ---------\n");
	printf("---------  0    退出   ---------\n");
	printf("--------------------------------\n");
	int inp, a, b;
	//pfArr是一个数组，数组内每个元素类型是一个函数指针
	int (*pfArr[5])(const int, const int) = { 0,add,sub,mul,div };
	do {
		printf("请选择运算规则\n");
		scanf("%d", &inp);
		if (inp == 0) {
			printf("程序已退出\n");
			return 0;
		}
		else if (inp < 0 || inp>4) {
			printf("输入错误，请重新输入\n");
			continue;
		}
		else {
			printf("请输入两个操作数：\n");
			scanf("%d %d", &a, &b);
			printf("%d\n", pfArr[inp](a, b));
		}
	} while (inp);
}

int main() {
	//calculate01();
	calculate02();
	return 0;
}