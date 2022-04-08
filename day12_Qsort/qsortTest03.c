#define _CRT_SECURE_NO_WARNINGS 1
/*
	改写qsort函数
		- 使用快排算法
		- 因qsort()的形参没有low，high，而是指针的形式，为了贴近int类型的快排算法，用了一个interface来递归传递low,high
	
*/

//声明 test02中已定义的交换函数
void swich(void* a, void* b, int sz);

//划分函数 每次将区间第一个元素放在排序后的位置上
int partition(void* arr, int size, int low, int high, int(*compare)(const void*, const void*)) {
	int pivot = low;
	while (low < high) {
		while (low < high && compare((char*)arr + size * high, (char*)arr+size*pivot) >= 0)
			high--;
		if (low >= high) break;
		swich((char*)arr + size * high, (char*)arr + size * pivot, size);
		pivot = high;
		while (low < high && compare((char*)arr + size * pivot, (char*)arr + size * low) >= 0)
			low++;
		if (low >= high) break;
		swich((char*)arr + size * pivot, (char*)arr + size * low, size);
		pivot = low;
	}
	return low;
}

//函数递归入口，由上层传入排序区间并递归调用自身
void quick_sort_interface(void* base, int low, int high, int size, int arrSize, int(*compare)(const void*, const void*)) {
	if (low >= high) return;
	else {
		int pivot = partition(base, size, low, high,compare);
		quick_sort_interface(base, low, pivot - 1, size, arrSize,compare);
		quick_sort_interface(base, pivot + 1, high, size, arrSize,compare);
	}
}

//函数入口，由上层调用
void quick_sort(void* base, int arrSize, int size, int(*compare)(const void*, const void*)) {
	quick_sort_interface(base, 0, arrSize - 1, size, arrSize,compare);
	return;
}