#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_SIZE 15
#define MAX_CONTACT_SIZE 100
#define DEFAULT_SEX 2

enum Option
{
    EXIT,
    ADD,
    DELETE,
    MODIFY,
    SEARCH,
    PRINT,
    SORT
};

//定义people结构体
typedef struct PeopleInFo
{

    char sex[DEFAULT_SEX];
    char name[DEFAULT_SIZE];
    char addr[DEFAULT_SIZE * 4];
    char tel[DEFAULT_SIZE];
} PeopleInFo;

//定义通讯录结构体
typedef struct Contact
{
    PeopleInFo data[MAX_CONTACT_SIZE];
    int size;
} Contact;

//初始化一个通讯录并返回
void initContact(Contact *);
//打印通讯录
void printContact(Contact *);
//判断通讯录是否为空
int contactIsNull(Contact *);
//判断通讯录是否为满
int contactIsFull(Contact *);
//向通讯录添加条目
int contactAdd(Contact *);
//查找通讯录联系人（按名字查找、返回位置）
int contactSearch(Contact *, char *);
