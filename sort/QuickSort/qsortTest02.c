#define _CRT_SECURE_NO_WARNINGS 1
/*
	递归方式2，每次将开头元素的值作为枢轴
		- 每轮首元素(下标为low)不动，排序区间为[low+1,high]
		- 令pivot = low+1，用来记录遍历结束后左右区间的分界线（指向右区间首元素）
		- 用i从头至尾遍历
		- 若 arr[i]>pivot , 交换 arr[pivot] 与 arr[i]，并将 pivot++
		- 一轮便利结束后，将 arr[low] 与 arr[pivot-1] 交换
		- 此时，arr[pivot-1]存储了有序值
		- 下一轮再开始时，分别对pivot左右两个区间进行处理
*/