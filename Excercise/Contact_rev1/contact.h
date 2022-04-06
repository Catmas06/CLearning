#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_NAME_SIZE 15
#define DEFAULT_TEL_SIZE 15
#define DEFAULT_ADDR_SIZE DEFAULT_NAME_SIZE * 4
#define MAX_CONTACT_SIZE 100
#define DEFAULT_SEX 5

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
    char name[DEFAULT_NAME_SIZE];
    char addr[DEFAULT_ADDR_SIZE];
    char tel[DEFAULT_TEL_SIZE];
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
//判断通讯录是否为空，为空返回1，否则返回0
int contactIsNull(Contact *);
//判断通讯录是否为满，为满返回1，否则返回0
int contactIsFull(Contact *);
//向通讯录添加条目
int contactAdd(Contact *);
//通过名字查找联系人，查找成功返回下标，否则返回-1，内部函数
const int findByName(Contact *, char *);
//查找通讯录联系人（按名字），查找成功返回下标，否则返回-1
int contactSearch(Contact *, char *);
//删除联系人（按名字），成功返回删除下标，否则返回-1
int contactDelete(Contact *, char *);
//编辑联系人（按名字），成功返回被编辑的下标，否则返回-1
int contactModify(Contact *, char *);
//重新排序（按姓名）
void sortByName(Contact *);