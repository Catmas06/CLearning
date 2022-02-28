#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//求字符串长度，不允许创建临时变量
int my_strlen(char* str) {
	if (*str == '\0') {
		return 0;
	}
	else{
		//str是一个地址，加1指向下一个字符的地址
		//不能使用str++，后置自增，传入值不变
		return my_strlen(str + 1)+1;
	}
}

//求n的阶乘，不考虑溢出
int factorial(int n) {
	if (n == 0) return 1;
	else return n * factorial(n - 1);
}

//求第n个斐波那契数 1 1 2 3 5 8 13 21
//	* 效率非常低，会有大量重复计算
int fib(int n) {
	if (n < 1) return 0;
	else if (n > 2) return fib(n - 1) + fib(n - 2);
	else return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("fac ==> %d\n", factorial(n));
	printf("fib ==> %d\n", fib(n));
	printf("fiC ==> %d\n", fibCycle(n));
}