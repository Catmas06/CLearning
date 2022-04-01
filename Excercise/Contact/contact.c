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

int contactAdd(Contact *src)
{
    if (contactIsFull(src))
    {
        return 0;
    }
    char input[DEFAULT_SIZE * 4];
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
    int i = 0;
    while (i < src->size)
    {
        if (strcmp(src->data[i].name, inputName) == 0)
        {
            printf("查找成功\n");
            printf("%-15s\t %-4s\t %-15s\t %-20s\t\n", "name", "sex", "tel", "address");
            printf("%-15s\t %-4s\t %-15s\t %-20s\t\n", src->data[i].name, src->data[i].sex, src->data[i].tel, src->data[i].addr);
            return i;
        }
        i++;
    }
    printf("查找失败，请检查输入或添加\n");
    return -1;
}