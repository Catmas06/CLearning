#include<stdio.h>
//结构体的创建与使用

//成绩
struct point {
	int math;
	int physic;
};

//学生
struct Stu {
	int age;
	int degree;
	char name[11];	//C语言中一个汉字占用2个字节，最后还要加上结尾的 '\0'
	char id[9];
	//结构体可以嵌套定义
	struct point poi;
}s1;	//s1是全局变量

//每次调用print1，都需要重新开辟空间存放Stu的复制体；不可改变原变量的值
void print1(struct Stu s) {
	printf("%s %s %d %d %d %d\n", s.id, s.name, s.age, s.degree, s.poi.math, s.poi.physic);
}

//每次调用仅需要复制一个指针变量，内存利用更高效；可以改变原变量的值
void print2(struct Stu* s) {
	printf("%s %s %d %d %d %d\n", s->id, s->name, s->age, s->degree, s->poi.math, s->poi.physic);
}

int main() {
	//嵌套结构体的初始化 { { }  }
	//s2、s3是局部变量
	struct Stu s2 = { 19,3,"张三","650100241",{8,9} };
	struct Stu s3;
	struct Stu* sp = &s2;

	print1(s2);
	print2(sp);

	//printf("%s\n", s2.name);
	//printf("%d\n", s2.poi.math);
	//printf("%s\n", sp->name);

	return 0;
}
