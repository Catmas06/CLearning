
/*
    1、将数组从中间 pivot处 一分为二
    2、判断 pivot左或右完全有序
    3、若target落在有序区间，直接得值。（二分查找）
    4、否则，将无序区间继续一分为二
*/

//判断是否升序
int isSeq(int* nums, int low, int high) {
    if (low > high) return 0;                   //pivot左边无元素
    else if (nums[low] <= nums[high]) return 1; //== pivot左仅有一个元素
    else return 0;
}

//判断target是否在区间中
int isIn(int* nums, int low, int high, int target) {
    if (target >= nums[low] && target <= nums[high]) return 1;
    else return 0;
}

//二分查找
int biSearch(int* nums, int low, int high, int target) {
    int pivot = (low + high) / 2;
    while (low < high) {
        pivot = (low + high) / 2;
        if (nums[pivot] == target) return pivot;
        else if (target < nums[pivot]) high = pivot - 1;
        else if (target > nums[pivot]) low = pivot + 1;
    }
    if (nums[low] == target) return low;
    else return -1;
}

int search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;
    while (low < high) {
        int pivot = (low + high) / 2;
        //递归出口
        if (nums[pivot] == target) return pivot;
        int tIsIn = 0;
        //判断左边是否升序
        int leftIsSeq = isSeq(nums, low, pivot - 1);
        if (leftIsSeq) {
            //左边有序
            tIsIn = isIn(nums, low, pivot - 1, target);
            if (tIsIn) return biSearch(nums, low, pivot - 1, target);
            else low = pivot + 1;
        }
        else {
            //右边有序
            tIsIn = isIn(nums, pivot + 1, high, target);
            if (tIsIn) return biSearch(nums, pivot + 1, high, target);
            else high = pivot - 1;
        }
    }
    if (nums[low] == target) return low;
    else return -1;
}

int main() {
    int nums[7] = { 4,5,6,7,0,1,2 };
    int numsSize = 7;
    printf("%d\n", search(nums, numsSize, 5));
}
