#include <stdio.h>

//关于传值调用与传址调用
// 传值
void swap1( int a,int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("swap1 -- a = [%d],b = [%d]\n", a, b);
}
// 传址
void swap2( int *a,int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	printf("swap2 -- a = [%d],b = [%d]\n", *a, *b);
}

//测试
/*
int main() {

	int a = 1, b = 2;
	swap1(a, b);
	printf("main1 -- a = [%d],b = [%d]\n", a, b);
	swap2(&a, &b);
	printf("main2 -- a = [%d],b = [%d]\n", a, b);

	return 0;
}
*/