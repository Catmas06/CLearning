/*
    枚举类型，本身是一个类型，枚举中定义的是枚举常量
*/
#include <stdio.h>
enum Color
{
    //这些是常量，只能赋初值，不能更改
    RED,
    GREEN,
    BLUE = 520
};

int main()
{
    int a = RED;
    a = 2;
    // cpp的语法检查更加严格，会报编译错误，最好不要直接赋数值
    //  enum Color b = 1;
    enum Color b = GREEN;
    printf("enum b  -->%d\n", b);
    b = BLUE;
    printf("int a   -->%d\n", a);
    printf("enum b  -->%d\n", b);
    return 0;
}