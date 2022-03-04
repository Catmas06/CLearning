#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
/*
	void qsort (void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*));
	- 需引入头文件 <stdlib.h> 

		1、不挑类型，可排 int、char、struct等类型

	- 结构体比较举例
*/
/*
void qsort(
	void* base,									//待排序数据中第一个对象的地址
	size_t num,									//待排序数据的个数
	size_t size,								//待排序数据中一个元素的大小
	int (*compar)(const void*, const void*)		//比较待排序数据中两个元素的函数
);												//返回值>0 大于；返回值=0 等于；返回值<0 小于
*/

//定义要比较的结构体类型
struct Stu{
	char name[20];
	int age;
};

//比较函数
int cmp_name(const void* p1, const void* p2) {
	//将指针p1强制类型转化为结构体指针，再指向要对比的元素值
	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p1)->name);
}

int main() {
	struct Stu s[3] = {"张三",20,"李四",21,"王五",19};
	qsort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), cmp_name);
	return 0;
}