#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
/*
	快排1的优化思路
		- 每次开始前，将首元素替换为三数取中值的结果
		- 当数组规模较小时，转化为插入排序(high-low)<7
*/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void numberOfThree(int *arr, int low, int high)
{
	//直接(low+high)/2可能导致 int 溢出
	int mid = low + ((high - low) >> 1);
	if (arr[mid] > arr[high])
	{
		swap(&arr[mid], &arr[high]);
	}
	if (arr[low] > arr[high])
	{
		swap(&arr[low], &arr[high]);
	}
	//最后一步，使 low 处存的值是中值
	if (arr[mid] > arr[low])
	{
		swap(&arr[mid], &arr[low]);
	}
	return;
}

//快排 -划分函数
int partition_3(int *nums, int low, int high)
{
	numberOfThree(nums, low, high);
	int pivot = nums[low];
	while (low < high)
	{
		while (low < high && nums[high] >= pivot)
			high--;
		if (low < high)
		{
			nums[low] = nums[high];
		}
		while (low < high && nums[low] <= pivot)
			low++;
		if (low < high)
		{
			nums[high] = nums[low];
		}
	}
	nums[low] = pivot;
	return low;
}

//插入排序
void insort(int *nums, int low, int high)
{
	for (int i = low + 1; i <= high; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (nums[j - 1] <= nums[j])
				break;
			else
				swap(&nums[j - 1], &nums[j]);
		}
	}
}

void qsort_3(int *nums, int low, int high)
{
	if (low > high)
		return;
	int pivot = partition(nums, low, high);
	if ((pivot - 1 - low) > 7)
	{
		qsort_3(nums, low, pivot - 1);
	}
	else
	{
		insort(nums, low, pivot - 1);
	}
	if ((high - pivot + 1) > 7)
	{
		qsort_3(nums, pivot + 1, high);
	}
	else
	{
		insort(nums, pivot + 1, high);
	}
	return;
}