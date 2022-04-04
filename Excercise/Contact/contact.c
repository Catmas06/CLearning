#include "contact.h"

void initContact(Contact *src)
{
    // src = malloc(sizeof(Contact));
    memset(src->data, 0, sizeof(src->data));
    src->size = 0;
}

void printContact(Contact *src)
{
    printf("%-15s\t %-4s\t %-15s\t %-20s\t\n", "name", "sex", "tel", "address");
    for (int i = 0; i < src->size; i++)
    {
        printf("%-15s\t %-4s\t %-15s\t %-20s\t\n", src->data[i].name, src->data[i].sex, src->data[i].tel, src->data[i].addr);
    }
    return;
}

int contactIsNull(Contact *src)
{
    if (src->size == 0)
    {
        return 1;
    }
    return 0;
}

int contactIsFull(Contact *src)
{
    if (src->size == MAX_CONTACT_SIZE)
    {
        return 1;
    }
    return 0;
}

int findByName(Contact *src, char *inputName)
{
    int i = 0;
    while (i < src->size)
    {
        if (strcmp(src->data[i].name, inputName) == 0)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int contactAdd(Contact *src)
{
    if (contactIsFull(src))
    {
        return 0;
    }
    char input[DEFAULT_ADDR_SIZE];
    printf("请输入想要添加的联系人姓名>\n");
    getchar();
    scanf("%s", input);
    strcpy(src->data[src->size].name, input);
    printf("请输入想要添加的联系人性别>\n");
    getchar();
    scanf("%s", input);
    strcpy(src->data[src->size].sex, input);
    printf("请输入想要添加的联系人电话>\n");
    getchar();
    scanf("%s", input);
    strcpy(src->data[src->size].tel, input);
    printf("请输入想要添加的联系人地址>\n");
    getchar();
    scanf("%s", input);
    strcpy(src->data[src->size].addr, input);
    printf("添加成功！\n");
    (src->size)++;
    return 1;
}

int contactSearch(Contact *src, char inputName[])
{
    int i = findByName(src, inputName);
    if (i == -1)
    {
        printf("查无此人\n");
    }
    printf("查找成功\n");
    printf("%-15s\t %-4s\t %-15s\t %-20s\t\n", "name", "sex", "tel", "address");
    printf("%-15s\t %-4s\t %-15s\t %-20s\t\n", src->data[i].name, src->data[i].sex, src->data[i].tel, src->data[i].addr);
    return i;
}

int contactDelete(Contact *src, char *inputName)
{
    if (contactIsNull(src))
    {
        printf("当前通讯录已为空，删除失败\n");
        return -1;
    }
    int i = findByName(src, inputName);
    if (i == -1)
    {
        printf("查无此人\n");
        return -1;
    }
    printf("正在删除指定联系人：\n");
    printf("%-15s\t %-4s\t %-15s\t %-20s\t\n", "name", "sex", "tel", "address");
    printf("%-15s\t %-4s\t %-15s\t %-20s\t\n", src->data[i].name, src->data[i].sex, src->data[i].tel, src->data[i].addr);
    (src->size)--;
    int ret = i;
    while (i < src->size)
    {
        strcpy(src->data[i].name, src->data[i + 1].name);
        strcpy(src->data[i].sex, src->data[i + 1].sex);
        strcpy(src->data[i].tel, src->data[i + 1].tel);
        strcpy(src->data[i].addr, src->data[i + 1].addr);
        i++;
    }
    printf("删除成功\n");
    return ret;
}

int contactModify(Contact *src, char *inputName)
{
    if (contactIsNull(src))
    {
        printf("当前通讯录为空,编辑失败\n");
        return -1;
    }
    int i = findByName(src, inputName);
    if (i == -1)
    {
        printf("查无此人\n");
        return -1;
    }
    printf("当前编辑的联系人为：");
    printf("%-15s\t %-4s\t %-15s\t %-20s\t\n", "name", "sex", "tel", "address");
    printf("%-15s\t %-4s\t %-15s\t %-20s\t\n", src->data[i].name, src->data[i].sex, src->data[i].tel, src->data[i].addr);
    char input[DEFAULT_ADDR_SIZE];
    printf("请输入想要修改的联系人姓名>\n");
    getchar();
    scanf("%s", input);
    strcpy(src->data[i].name, input);
    printf("请输入想要修改的联系人性别>\n");
    getchar();
    scanf("%s", input);
    strcpy(src->data[i].sex, input);
    printf("请输入想要修改的联系人电话>\n");
    getchar();
    scanf("%s", input);
    strcpy(src->data[i].tel, input);
    printf("请输入想要修改的联系人地址>\n");
    getchar();
    scanf("%s", input);
    strcpy(src->data[i].addr, input);
    printf("编辑已保存\n");
    return i;
}

int compare(const void *a, const void *b)
{
    return strcmp(((PeopleInFo *)a)->name, ((PeopleInFo *)b)->name);
}

void sortByName(Contact *src)
{
    qsort(src->data, src->size, sizeof(PeopleInFo), compare);
    printf("排序成功\n");
}