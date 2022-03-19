#define _CRT_SECURE_NO_WARNINGS 1
/*
	使用递归的方式，每次将开头元素的值作为枢轴
		- 栈调用层次较深
		- 对于基本有序的升序数组，退化为冒泡排序
		- 每次low与high变换时，总有一个指向了空值（值已使用或去除）
		- 每轮最后 low 一定等于 high
*/

//快排 -划分函数
int partition_1(int* nums, int low, int high) {
	int pivot = nums[low];
	while (low < high) {
		while (low < high && nums[high] >= pivot)
			high--;
		if (low < high) {
			nums[low] = nums[high];
		}
		while (low < high && nums[low] <= pivot)
			low++;
		if (low < high) {
			nums[high] = nums[low];
		}
	}
	nums[low] = pivot;
	return low;
}

//快排 -主体
void qsort_1(int* nums, int low, int high) {
	if (low > high) return;
	int pivot = partition(nums, low, high);
	qsort_1(nums, low, pivot - 1);
	qsort_1(nums, pivot + 1, high);
	return;
}
