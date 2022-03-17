#include <stdio.h>
#include <string.h>
/*
    结构体内存对齐
        - 结构体的第一个成员，在内存中偏移量为0的地址开始存储
        - 余下成员都放在对齐数的整数倍的地址中
            - 取【默认对齐数】和【该成员大小】的【较小值】为【对齐数】
            - vs默认对齐数为8 ， linux平台下无默认对齐数
        - 结构体的总大小是结构体最大对齐数的整数倍
*/

//学生结构
struct students
{
    int age;
    char name[20];
    int degree;
} s1, s2; //这里表示新建了两个变量结构体变量 s1、s2

//链表结点
typedef struct LNode
{
    int data;
    struct LNode *next;
} * Lnodes;

int main()
{
    struct students s3 = {20, "胡天娇", 100};
    s1.age = 20;
    strcpy(s1.name, "章三");
    s1.degree = 50;
    printf("%s %d %d\n", s1.name, s1.age, s1.degree);
    printf("%s %d %d\n", s3.name, s3.age, s3.degree);
    return 0;
}