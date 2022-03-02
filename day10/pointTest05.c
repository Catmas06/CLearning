#define _CRT_SECURE_NO_WARNINGS 1

//函数指针数组

int add(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}

int pointTest05() {
	int(*pf1)(int, int) = add;
	int(*pf2)(int, int) = add;
	//函数指针数组可以存放同类型的函数指针
	//pfArr就是函数指针数组
	int (*pfArr[2])(int, int) = { pf1,sub };
	return 0;
}