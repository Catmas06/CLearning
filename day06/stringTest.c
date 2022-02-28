#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//#include <string.h>
#include <assert.h>

/*
	- 赋值函数有返回值，其返回值即所赋的值。
		x = y =10;	其中(y = 10)的返回值是【10】

	- strcpy( )库函数
		char * strcpy ( char * destination, const char * source );
		会将结尾的'\0'一起拷贝过来
		报名<string.h>

	- 给 char* 赋初始值时，剩余元素全部赋值'\0'，'\0'的ASCII码值为0

	- assert(bool) 宏 断言
		void assert (int expression);
		判断()内条件，为真继续，为假则报错
		包名<assert.h>
*/

//模拟实现strcpy函数
void strcpy(char* dest,const char* src) {		//将src的值放入dest内
	assert(src != NULL);
	assert(dest != NULL);
	while (*dest++ = *src++) {
	}
}

/*
void strcpy(char* dest, char* src) {
	int i = 0;
	while (dest[i] = src[i++]) {
		;
	}
}
*/

//模拟实现strlen
//size_t 宏 unsigned int
size_t my_strlen(char* src) {
	//指针不能为空
	assert(src);
	size_t count = 0;
	while (*src++) {
		count++;
	}
	return count;
}

int main() {
	char s1[] = { "hello" };
	char s2[20] = { "**********" };
	printf("s2.len=%d\n", my_strlen(s2));
	strcpy(s2, s1);
	printf("%s\n", s2);
	int m, n = 10;
	int const* const p = &n;
	printf("s1.len=%d\n", my_strlen(s1));
	printf("s2.len=%d\n", my_strlen(s2));
	return (0);
}
