#include <stdio.h>
#include <string.h>
#include <assert.h>
/*
    内存复制（可能无法处理内存重叠的情况）
    void * memcpy ( void * destination, const void * source, size_t num );
    内存移动（可以处理内存重叠的情况）
    void * memmove ( void * destination, const void * source, size_t num );
    内存比较，与strcmp()类似，当 ptr1 > ptr2 时返回正数
    int memcmp ( const void * ptr1, const void * ptr2, size_t num );
    内存赋值，将从ptr向后num个内存空间全部赋值value，可初始化数组
    void * memset ( void * ptr, int value, size_t num );
*/

void *my_memmove(void *dest, const void *src, size_t size)
{
    assert(dest && src);
    int i = 0;
    //从前向后复制
    if (src > dest)
    {
        char *p = (char *)dest;
        while (size--)
        {
            *(char *)p = *(char *)src;
            p++;
            (char *)src++;
        }
    }
    //从后向前复制
    else
    {
        while (size--)
        {
            *((char *)dest + size) = *((char *)src + size);
        }
    }
    return dest;
}

int main()
{
    int nums1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int nums2[5] = {11, 12, 13, 14, 15};
    // memmove(nums1 + 2, nums1, 20);
    my_memmove(nums1, nums1 + 2, 20);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", nums1[i]);
    }
    return 0;
}