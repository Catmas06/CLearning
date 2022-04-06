#include <stdio.h>
int main()
{
    int num;
    char ch;
    scanf("%d", &num);
    //输入时会输入回车，缓冲区内会留有\n，因此会直接读入，跳过这个输入
    setbuf(stdin, NULL); //使stdin输入流由默认缓冲区转为无缓冲区
    scanf("%c", &ch);
    printf("hello world\n");
    return 0;
}