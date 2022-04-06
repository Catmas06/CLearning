/*
    void *malloc(size_t size);
        开辟成功会返回一个指针，指向对应大小连续可用的空间；开辟失败则返回NULL
            * 最好对malloc的返回值进行一次判空处理，否则容易导致空指针异常
        所开辟的空间在堆区而不是栈区，堆区内的空间不会随着函数返回而释放，因此必须与 free() 搭配使用
        不去free的话，开辟到上限后会出错，无法再开辟新的空间
    free(p);
        仅能释放堆区空间，栈区标准未定义
        仅仅将p所指向的空间释放掉，不改变p本身的值，p依然指向该空间
        为避免再次非法访问，建议添加 p = NULL;
    void *calloc (size_t num, size_t size);
        num 变量的个数 size 变量的大小
        开辟成功后给所有的变量赋0
    void* realloc (void* ptr, size_t size);
        重新开辟空间

    关于动态内存分配的常见错误
        1、对NULL指针的解引用操作
        2、对动态开辟空间的越界访问
        3、使用free()释放非动态开辟空间
        4、使用free()释放动态内存中的一部分
        5、对同一动态空间多次释放
        6、动态开辟空间忘记释放 --> 内存泄漏
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(sizeof(int) * 100);
    if (p == NULL)
    {
        perror("main");
        return 0;
    }
    int i = 0;
    while (i < 100)
    {
        p[i] = i;
        i++;
    }
    for (i = 0; i < 500; i++)
    {
        printf("p[%d] = %d\n", i, p[i]);
    }

    int *ptr = malloc(sizeof(int) * 8);
    ptr[1] = 10;
    printf("%d\n", *(ptr + 1));

    return 0;
}

//--------------------经典错误-------------------

// void GetMemory(char *p)
// {
//     p = (char *)malloc(100);
// }
// #include <string.h>
// void Test(void)
// {
//     char *str = NULL;
//     GetMemory(str);
//     strcpy(str, "hello world");
//     printf(str);
// }

//------------------------------------------------