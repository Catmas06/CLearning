#define _CRT_SECURE_NO_WARNINGS 1

//复杂的函数指针及其简化
void pointTest04() {

	//调用位于内存中0处的函数
	(*(void(*)())0)();
	//	(void(*)())0		将int类型0强制类型转换为一个函数指针，该函数的形参和返回值都为空
	//	*(void(*)())0		对这个函数指针解引用，即得到位于0x00000000地址处的函数
	//	(*(void(*)())0)()	调用该函数，形参为空

	//声明一个返回值为函数指针类型的函数
	void (*signal(int, void(*)(int)))(int);
	//	signal(int,void(*)(int))	声明一个函数，其形参一个为int类型，一个为函数指针void(*)(int)类型
	//	void(*(~))(int)				声明该函数的返回值，是一个函数指针

	//使用 typedef - 对类型重定义
	typedef void(*pfun_t)(int);		//将 void(*)(int) 类型重命名为 pfun_t
	pfun_t signal2(int, pfun_t);
}