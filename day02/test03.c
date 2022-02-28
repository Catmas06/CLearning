#include <stdio.h>

//一维数组的调用	两种传参方式相同，都需要在函数外部计算数组大小

/*
//传参 int*
void arrTest01(int* arr1,int arrSize) {
	printf("int* size = %d\n", sizeof(*arr1));
	printf("int* *arr = %d\n", arr1[2]);
	printf("int* &arr = %p\n", &arr1);
	arr1[1] = 0;
}

//传参int[10]
void arrTest02(int arr2[10],int arrSize) {
	printf("int[10] size = %d\n", sizeof(arr2)); 
	printf("int[10] arr[2] = %d\n", arr2[2]);
	printf("int[10] &arr = %p\n", &arr2);
	arr2[2] = 0;
}
*/

//测试
/*
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("arr[5] = %d\n", arr[10]);
	arrTest01(arr, 10);
	arrTest02(arr, 10);
	int i = 0;
	while (i < 10) {
		printf("arr[i] = %d\n", arr[i]);
		i++;
	}
	return 0;
}
*/