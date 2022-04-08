/*
    将结构体数据转换为字符串数据
    将字符串转换为格式化的输入
        int sscanf ( const char * s, const char * format, ...);
    将格式化的输出转换为字符串  sprintf()
        int sprintf ( char * str, const char * format, ... );
*/
#include <stdio.h>

struct S {
    char arr[10];
    int age;
    float f;
};

int main() {
    struct S s = { "abc", 10, 31.3 };
    struct S temp = { 0 };
    char buffer[50];
    // 将结构体变量放入buffer字符串中
    sprintf(buffer, "%s %d %f", s.arr, s.age, s.f);
    // 打印的是一个字符串数据
    printf("%s\n", buffer);
    // 从buffer字符串中还原出一个结构体数据
    sscanf(buffer, "%s %d %f", temp.arr, &(temp.age), &(temp.f));
    // 打印的是一个结构体数据
    printf("%s %d %f\n", temp.arr, temp.age, temp.f);
    return 0;
}