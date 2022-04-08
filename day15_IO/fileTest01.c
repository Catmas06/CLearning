/**
    文件操作
        每打开一个文件，系统会根据文件的情况自动创建一个 FILE 结构体变量，用以记录被打开文件的各种信息
            - C语言自动实现，无需关心底层，各编译器的 FILE 包含内容大同小异
        1、文件在读写前要先打开文件，使用后要关闭文件

        - 打开文件
            FILE * fopen ( const char * filename, const char * mode );
                -W Create an empty file for output operations. If a file with the same name already exists
                   its contents are discarded and the file is treated as a new empty file.
        - 关闭文件
            int fclose ( FILE * stream );

        - 读文件
            char * fgets ( char * str, int num, FILE * stream );
                可以向 stream 传入 stdin
                num: Maximum number of characters to be copied into str (including the terminating null-character).
                文件正常读取结束后会返回空指针

        - 写文件
            int fputs ( const char * str, FILE * stream );
                可以向 stream 传入 stdout

        - 对格式化的数据进行读文件
            int fscanf ( FILE * stream, const char * format, ... );

        - 对格式化的数据进行写文件
            int fprintf ( FILE * stream, const char * format, ... );

        - 以二进制形式写
            size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
                ptr:    Pointer to the array of elements to be written, converted to a const void*.
                size:   Size in bytes of each element to be written.
                count:  Number of elements, each one with a size of size bytes.
                stream: Pointer to a FILE object that specifies an output stream.

        - 以二进制形式读
            size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
                返回实际读取的count个数，可以指定读5个，若只读入3个，则返回3
                若返回值小于count，则读取完成

        - 判断读取结束的原因。正常结束返回1
            int feof ( FILE * stream );

    流
        在程序和外部设备建抽象出来的一个层级，程序直接与流交互，流再与外部设备交互。只用关心程序和流之间的交互
        C语言程序运行时默认打开三个流
            stdin   -标准输入流 -键盘
            stdout  -标准输出流 -屏幕
            stderr  -标准错误流 -屏幕
**/

#include <stdio.h>

struct S
{
    int age;
    int num;
    char name[15];
};

int main()
{
    FILE *pf_r = fopen("sr.dat", "r");
    if (pf_r == NULL)
    {
        perror("fopen");
        return 1;
    }
    struct S s = {0};
    //以格式化文本文件形式读
    fscanf(pf_r, "%d %d %s\n", &s.age, &s.num, s.name);
    printf("%-4d %-4d %-4s\n", s.age, s.num, s.name);
    fclose(pf_r);
    pf_r = NULL;

    FILE *pf_w = fopen("sw.dat", "a");
    //以二进制形式写
    fwrite(&s, sizeof(struct S), 1, pf_w);
    fclose(pf_w);
    pf_w = fopen("sw.dat", "r");
    struct S s2 = {0};

    //以二进制形式读
    fread(&s2, sizeof(struct S), 1, pf_w);
    printf("%-4d %-4d %-4s\n", s2.age, s2.num, s2.name);

    return 0;
}