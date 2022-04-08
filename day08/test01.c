#define _CRT_SECURE_NO_WARNINGS 1
/*
	
*/

#include<stdio.h>
#include<string.h>

/*
						-1是int型，存入char型时发生截断
	char -1				1111 1111 1111 1111 1111 1111 1111 1111 -> 1111 1111
	signed char -1		1111 1111
						unsigned char进行整型提升时，高位一律补0
	unsigned char -1	1111 1111 -> 0000 0000 0000 0000 0000 0000 1111 1111

	char -128			1000 0000 0000 0000 0000 0000 1000 0000	-原码
						1111 1111 1111 1111 1111 1111 1000 0000 -> 1000 0000

	int -20				1000 0000 0000 0000 0000 0000 0001 0100	-原码
						1111 1111 1111 1111 1111 1111 1110 1100	-补码
	unsignede int 10	0000 0000 0000 0000 0000 0000 0000 1010	-补码
	add					1111 1111 1111 1111 1111 1111 1111 0110 -补码


	补充：	C语言规定：int 是signed int; short 是 signed short; unsigned + signed = unsigned;
					C语言并未规定char的类型，由编译器决定

			- 使用 %d 打印时，类型为 signed int，需要将内存中的二进制补码翻译为原码再打印
			- 使用 %u 打印时，类型为 unsigned int，直接将内存中的二进制认为原码进行打印
*/
	
//判断当前是大端存储还是小端存储
//0-大端存储 1-小端存储
int check_duan(void) {
	int a = 1;
	char* p = (char*)&a;
	return p[0];
	/*
	if (p[0]) {
		printf("当前是小端存储\n");
		return 1;
	}
	else {
		printf("当前是大端存储\n");
		return 0;
	}
	*/
}

int main() {
	check_duan(); 	
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	//打印时会进行整型提升
	printf("a=%d,b=%d,c=%d\n", a, b, c);

	a = -128;
	if (a == -128) {
		printf("char a -128 -->%d\n", a);
	}

	char ch[1000];
	a = 0;
	for (int i = 0; i < 1000;i++) {
		ch[i] = -1 - a;
		a++;
	}
	printf("字符组长度为%zu\n", strlen(ch));
	printf("char a=127+1 =%d\n", a);

	a = 255;
	b = -513;	//有符号char 1111 1111
	c = 511;	//无符号char 1111 1111
	printf("(unsigned char)b = %u\n unsigned char c = %u\n",(unsigned char)b,c);
	if (b != c) {	//先转化为int，再进行判断，虽然机器数相等，含义不同，转化为int后也不相同
		printf("(signed char)b!=(unsigned char)c\n");
	}
	c = -513;
	a++;
	return 0;
}