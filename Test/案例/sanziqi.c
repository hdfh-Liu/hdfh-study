#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"
//#include <sanziqi.h>

void menu()
{
    printf("*************************************\n");
    printf("****1.paly            0.exit*********\n");
    printf("*************************************\n");
    //printf("*\_-*\_*-\_-*\_-*\_*-\_-*\_-*\_*-\_-*\n");
}
void test()
{
    int a = 0;
    do
    {

        menu();
        printf("请选择：>");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("三子棋游戏开始\n");
            break;
        case 0:
            printf("游戏结束，即将关闭程序\n");
            break;
        default:
        printf("\n");
            printf("--------------\n");
            printf("请选择‘1’或者’0‘\n");
            printf("--------------\n");
            break;
        }
    } while (a);
}

int main()
{

    test();

    return 0;
}