#include "contact.h"

int main()
{
    int input;
    // Contact *contact = malloc(sizeof(Contact));
    Contact con;
    initContact(&con);
    char inputName[DEFAULT_SIZE];
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
        switch (input)
        {
        case ADD:
            contactAdd(&con);
            break;
        case DELETE:
            break;
        case MODIFY:
            break;
        case SEARCH:
            printf("请输入要查找的联系人姓名：\n");
            scanf("%s", inputName);
            contactSearch(&con, inputName);
            break;
        case PRINT:
            printContact(&con);
            break;
        case SORT:
            break;
        case EXIT:
            break;
        default:
            printf("Input is not available,please reinput\n");
            break;
        }
    } while (input);

    return 0;
}