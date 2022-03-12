#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

/*
	- 赋值函数有返回值，其返回值即所赋的值。
		x = y =10;	其中(y = 10)的返回值是【10】

	- strcpy()库函数
		char * strcpy ( char * destination, const char * source );
		会将结尾的'\0'一起拷贝过来
		报名<string.h>

	- 给 char* 赋初始值时，剩余元素全部赋值'\0'，'\0'的ASCII码值为0

	- assert(bool) 宏 断言
		void assert (int expression);
		判断()内条件，为真继续，为假则报错
		包名<assert.h>

	- strcat()字符串追加
		必须保证被追加的字符数组有足够的空间
		从目标字符串的'\0'处开始覆盖，到源字符串的'\0'处停止

	- strcmp()字符串比较
		int strcmp ( const char * str1, const char * str2 );

	- strncpy()、strncat()、strncmp()	指定操作的个数
		关于strncpy()
			- 当src的长度小于指定长度，后面全部赋值'\0'
		关于strncat()
			- 当src长度小于指定长度，仅追加src实际长度
			- 若指定长度大于src长度，追加完成后末尾补充'\0'

	- strstr() 在一个字符串中找另一个字符串，返回第一次出现的地址
		const char * strstr ( const char * str1, const char * str2 );
		char * strstr ( char * str1, const char * str2 );

	- strtok() 切割字符串
		char * strtok ( char * str, const char * delimiters );
		- strtok()内部有记录上次切割位置的标志，当传入的str为NULL时，从上次切割位置开始寻找切割点
*/

//模拟实现strcpy函数
void my_strcpy(char* dest, const char* src) {		//将src的值放入dest内
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

//模拟实现strcat()
void my_strcat(char* dest, const char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest) {
		dest++;
	}
	while (*dest++ = *src++) {
		;
	}
	return;
}

//模拟实现strstr()
char* my_strstr(const char* dest,const char* src) {	//const *dest dest内存放的数据不能改，但本身可改
	if (src == NULL)
		return dest;
	//dest不能为NULL
	assert(dest);
	char* temp = dest;
	char* p = src;
	while (*dest != 0) {
		temp = dest;
		p = src;
		//temp与p都不为NULL
		while (*temp && *p && *temp == *p) {
			temp++;
			p++;
		}
		if (*p == 0)
			return dest;
		dest++;
	}
	return NULL;
}

int main() {
	const char s1[20] = { "hello" };
	char s2[20] = { "**********" };
	{//strcpy()
		printf("s2.len=%d\n", my_strlen(s2));
		strcpy(s2, s1);
		printf("%s\n", s2);
		strcpy(s2, "world");
		printf("%s\n", s2);
		//char* s2 = "world";	s2这样写是一个常量字符串，不可修改，会报 “写入权限异常”
		char s2[] = "world";
		strcpy(s2, s1);
		printf("%s\n", s2);
	}
	{//strlen()
		int n = 10;
		int const* const p = &n;
		printf("s1.len=%d\n", my_strlen(s1));
		printf("s2.len=%d\n", my_strlen(s2));
	}
	{//strcat()
		char s3[] = " world";
		my_strcat(s1, s3);
		printf("%s\n", s1);
	}
	{//strstr()
		printf("--------------strstr()---------------\n");
		char* ch = "lo";
		char* ret = NULL;
		ret = strstr(s1, ch);
		printf("%s\n", ret);
		ret = my_strstr(s1, ch);
		printf("%s\n", ret);
	}
	{//strtok()
		printf("--------------strtok()---------------\n");
		char ch[20] = "salasi@google.com";
		char temp[20];
		strcpy(temp, ch);
		char* p = "@.";
		char* ret;
		//代码简化
		for (ret = strtok(temp, p); ret != NULL; ret = strtok(NULL, p)) {
			printf("%s\n", ret);
		}
		{//逻辑简化
			strcpy(temp, ch);
			ret = strtok(temp, p);
			printf("%s\n", ret);
			ret = strtok(NULL, p);
			printf("%s\n", ret);
			ret = strtok(NULL, p);
			printf("%s\n", ret);
		}
	}
	return (0);
}
