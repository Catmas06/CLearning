#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
	回调函数

*/

int add(const int a, const int b);
int sub(const int a, const int b);
int mul(const int a, const int b);
int div(const int a, const int b);

void calc(int(*p)(int, int)) {
	int a, b;
	printf("请输入两个操作数：\n");
	scanf("%d %d", &a, &b);
	printf("%d\n", p(a, b));
}

int calculate02() {
	printf("--------------------------------\n");
	printf("---------  计算器程序  ----------\n");
	printf("---------  1    加法   ---------\n");
	printf("---------  2    减法   ---------\n");
	printf("---------  3    乘法   ---------\n");
	printf("---------  4    除法   ---------\n");
	printf("---------  0    退出   ---------\n");
	printf("--------------------------------\n");
	int inp;
	do {
		printf("请选择运算规则\n");
		scanf("%d", &inp);
		switch (inp) {
		case 0:
			printf("程序已退出");
			return 0;
		case 1:
			calc(add);
			break;
		case 2:
			calc(sub);
			break;
		case 3:
			calc(mul);
			break;
		case 4:
			calc(div);
			break;
		default:
			puts("输入有误，请重新输入\n");
		}
	} while (inp);
}