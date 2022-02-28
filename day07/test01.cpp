#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
/*
-1		- 1111 1111 1111 1111 1111 1111 1111 1111
-2		- 1111 1111 1111 1111 1111 1111 1111 1110
-3		- 1111 1111 1111 1111 1111 1111 1111 1101
-4		- 1111 1111 1111 1111 1111 1111 1111 1100

&
-1		- 1111 1111 1111 1111 1111 1111 1111 1111
-2		- 1111 1111 1111 1111 1111 1111 1111 1110
=		- 1111 1111 1111 1111 1111 1111 1111 1110

&
-2		- 1111 1111 1111 1111 1111 1111 1111 1110
-3		- 1111 1111 1111 1111 1111 1111 1111 1101
=		- 1111 1111 1111 1111 1111 1111 1111 1100

-32768	- 1000 0000 0000 0000 0000 0000 0000 0000
32767	- 0111 1111 1111 1111 1111 1111 1111 1111
*/

//按奇偶位拆分整数
void part(int src) {
	//一个int有32位，假设开始为奇数位，末尾为偶数位
	int n;
	//输出奇数位
	printf("奇数位： ");
	for (n = 30; n >= 0; n -= 2) {
		printf("%d ", (src >> n) & 1);
	}
	printf("\n");
	printf("偶数位：");
	for (n = 31; n >= 1; n -= 2) {
		printf("%d ", (src >> n) & 1);
	}
	printf("\n");
}

//不创建临时变量，交换两个整数
int my_switch (int* a,int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main() {
	int i = -2147483648;
	int j = i - 1;
	int k = 0xffff;
	printf(" i = %d \n", i);
	printf(" j = %d \n", j);
	printf(" k = %d \n", k);
	scanf("%d %d", &i, &j);
	k = i ^ j;
	int count = 0;
	while (k) {
		k = k & (k - 1);
		count++;
	}
	printf("不同的有%d位\n输入想要拆分奇偶位的数字\n", count);
	scanf("%d", &k);
	part(k);
}