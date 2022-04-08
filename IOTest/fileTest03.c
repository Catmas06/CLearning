/*
    文件的随机读取

    调整文件指针
    int fseek ( FILE * stream, long int offset, int origin );
        origin 设定偏移量计算方式
            SEEK_SET	Beginning of file
            SEEK_CUR	Current position of the file pointer
            SEEK_END	End of file * 会指向末尾的'\0'，且偏移量只能为负数

    返回当前文件指针位置
    long int ftell ( FILE * stream );

    让文件指针偏移到起始位置
    void rewind ( FILE * stream );
*/
#include <stdio.h>

int main() {
    FILE* pf = fopen("test03.txt", "r");
    if(pf == NULL) {
        perror("fopen");
        return 1;
    }  // pf:abcdefg
    char ch = fgetc(pf);  // a
    printf("%c ", ch);
    ch = fgetc(pf);  // b
    printf("%c ", ch);
    fseek(pf, 3, SEEK_CUR);
    ch = fgetc(pf);  // f
    printf("%c ", ch);
    fseek(pf, -1, SEEK_END);
    ch = fgetc(pf);  // g
    printf("%c ", ch);
    fseek(pf, 1, SEEK_SET);
    ch = fgetc(pf);  // b
    printf("%c ", ch);
    return 0;
}