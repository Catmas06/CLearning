#define _CRT_SECURE_NO_WARNINGS 1
#include<float.h>
#include<stdio.h>

int main() {
	float f = -0.0f;
	// 1.1
	// 0011 1111 1100 0000 0000 0000 0000 0000
	// 3f c0 00 00 
	float f2 = 1.5f;
	// 0000 0000 0100 0000 0000 0000 0000 0000
	// 00 40 00 00
	float f3 = (float)0x00400000;	//0x...本身是一个int型常量，并不是单纯二进制位
	int n = 0xbfc00000;
	printf("0xbfc00000 = %f\n",*(float*)&n);	//%f打印时，只显示小数点后六位
	printf("f3 = %f\n",f3);	//%f打印时，地址解释为浮点型
	return 0;
}