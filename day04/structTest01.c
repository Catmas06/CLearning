#include <stdio.h>
#include <string.h>
/*
    结构体内存对齐
        - 结构体的第一个成员，在内存中偏移量为0的地址开始存储
        - 余下成员都放在对齐数的整数倍的地址中
            - 取【默认对齐数】和【该成员大小】的【较小值】为【对齐数】
            - vs默认对齐数为8 ， linux平台下无默认对齐数
        - 结构体的总大小是结构体最大对齐数的整数倍
        - #pragma pack() 可以更改当前对齐数
        - 不同的对齐数与不同的变量生命顺序都会影响最终的结构体大小
        - offsetof(type,member) --> stddef.h
            - 库函数，返回当前变量在结构体类型中的偏移量
*/

//学生结构
struct students01
{
    int age;
    char name[15];
    int degree;
    char tel[15];
} s1, s2; //这里表示新建了两个变量结构体变量 s1、s2

#pragma pack(8)
struct students02
{
    int age;
    int degree;
    char name[15];
    char tel[15];
};
#pragma pack()

struct struct01
{
    char a;
    char b;
    int c;
    long d;
};

#pragma pack(1)
struct struct02
{
    char a;
    char b;
    int c;
    long d;
};
#pragma pack()

#pragma pack(4)
struct struct03
{
    char a;
    char b;
    int c;
    long d;
};
#pragma pack()

//链表结点
typedef struct LNode
{
    int data;
    struct LNode *next;
} * Lnodes;

int main()
{
    struct students01 s3 = {20, "胡天娇", 100};
    s1.age = 20;
    strcpy(s1.name, "章三");
    s1.degree = 50;
    printf("%s %d %d\n", s1.name, s1.age, s1.degree);
    printf("%s %d %d\n", s3.name, s3.age, s3.degree);
    printf("struct students01   -->%d\n", (int)sizeof(struct students01));
    printf("struct students02   -->%d\n", (int)sizeof(struct students02));
    printf("struct struct01     -->%d\n", (int)sizeof(struct struct01));
    printf("struct struct02     -->%d\n", (int)sizeof(struct struct02));
    printf("struct struct03     -->%d\n", (int)sizeof(struct struct03));
    printf("sizeof(int)         -->%d\n", sizeof(long));
    return 0;
}