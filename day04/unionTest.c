/*
    联合(共用体)
        - 联合体的大小是最大对齐数的整数倍（无默认对齐数）

*/
#include <stdio.h>

//判断系统是否小端 小端返回1，否则返回0
int check_sys()
{
    union temp
    {
        char a;
        int i;
    };
    union temp u;
    u.i = 1;
    return u.a;
}

union Un
{
    //所有的变量共用一个空间
    char c;
    int i;
};

int main()
{
    union Un u;
    printf("%d\n", (int)sizeof(u));
    //内存地址相同
    printf("u   -->%p\n", &u);
    printf("u.c -->%p\n", &u.c);
    printf("u.i -->%p\n", &u.i);
    printf("当前是否为小端存储，是为1，否则0    -->%d\n", check_sys);
    return 0;
}