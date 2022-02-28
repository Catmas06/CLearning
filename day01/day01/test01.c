#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main() {

	const int c = 10;
	int i[5] = { 1,2,3,4,5 };

	
	enum Sex {
		MALE,
		FEMALE,
		SECRET = 5
	};

	enum Sex s = MALE;
	enum Sex s2 = SECRET;

	printf("[s] -->%d\n", s);
	printf("[s2]-->%d\n", s2);
	printf("-----------------------------------\n", s2);

	char c1[] = { 'a','b','c' };
	char c2[3] = { 'a','b','c' };
	char c3[] = { 'a','b','c','\0' };
	// char* c4 = { "abc" };
	char c4[4] = { 'a','b','c','\0' };

	printf("sizeof[c1]-->%d\n", sizeof(c1));
	printf("[c1] -->%s\n", c1);

	printf("sizeof[c2]-->%d\n", sizeof(c2));
	printf("[c2] -->%s\n", c2);

	printf("sizeof[c3]-->%d\n", sizeof(c3));
	printf("[c3] -->%s\n", c3);

	printf("sizeof[c4]-->%d\n", sizeof(c4));
	printf("[c4] -->%s\n", c4);
	
	//printf("[c5] -->%s\n", c5);

	printf("÷∏’Î¥Û–°-- %dB", sizeof(int*));

	return 0;
}