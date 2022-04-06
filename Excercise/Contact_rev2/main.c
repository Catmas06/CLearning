#include "contact.h"

int main()
{
    int input;
    // Contact *contact = malloc(sizeof(Contact));
    // initContact(contact);
    Contact con;
    initContact(&con);
    char inputName[DEFAULT_NAME_SIZE];
    do
    {
        printf("***********************************\n");
        printf("***** Please select operation *****\n");
        printf("*****  1.ADD       2.DELETE   *****\n");
        printf("*****  3.MODIFY    4.SEARCH   *****\n");
        printf("*****  5.PRINT     6.SORT     *****\n");
        printf("*****  0.EXIT                 *****\n");
        printf("***********************************\n");
        scanf("%d", &input);
        setbuf(stdin, NULL); //使stdin输入流由默认缓冲区转为无缓冲区
        switch (input)
        {
        case ADD:
            contactAdd(&con);
            // ontactAdd(contact);
            break;
        case DELETE:
            printf("请输入要删除的联系人姓名：\n");
            scanf("%s", inputName);
            contactDelete(&con, inputName);
            // contactDelete(contact, inputName);
            break;
        case MODIFY:
            printf("请输入要更改的联系人姓名：\n");
            scanf("%s", inputName);
            contactModify(&con, inputName);
            break;
        case SEARCH:
            printf("请输入要查找的联系人姓名：\n");
            scanf("%s", inputName);
            contactSearch(&con, inputName);
            // contactSearch(contact, inputName);
            break;
        case PRINT:
            printContact(&con);
            // printContact(contact);
            break;
        case SORT:
            sortByName(&con);
            break;
        case EXIT:
            saveToFile(&con);
            break;
        default:
            printf("Input is not available,please reinput\n");
            break;
        }
    } while (input);

    return 0;
}