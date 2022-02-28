#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

void pointTets01() {
	//将字符串首字符的地址赋给ch，是常量字符串，不可修改。ch可修改，*ch不可修改，不一定会开辟整个字符串的空间
	char* ch = "Hello World";
	//将整个字符串赋给arr数组，每次都会在内存中开辟空间以完成赋值
	char arr[] = "Hello World";

	{//两种赋值方式的区别
		char str1[] = "Hello World!";
		char str2[] = "Hello World!";
		 char* str3 = "Hello World!";
		//不会在内存中新开辟空间，而是将上一次创建的常量字符串的首地址赋给str4
		//赋值常量字符串时最好用const修饰
		const char* str4 = "Hello World!";
		if (str1 == str2)
			printf("str1 and str2 are same\n");
		else 
			printf("str1 and str2 are not same\n");
		if (str3 == str4)
			printf("str3 and str4 are same\n");
		else 
			printf("str3 and str4 are not same\n");
		//常量字符串不能更改
		//*str3 = "a";		引发了异常: 写入访问权限冲突。
	}
}