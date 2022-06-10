#include "sanziqi.h"

//厨师换棋盘代码
void InitBoard(char board[ROW][COL], int row, int col) //和void game 输出的数值一致
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

//打印棋盘代码,无法控制列
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    //只对行进行了控制
    // for (i = 0; i < row; i++)
    // {
    //     //打印一行的数据
    //     printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]); //%c是打印数据内第几行的数值
    //     //打印分隔行
    //     if (i < row - 1)
    //     {
    //         printf("---|---|---\n");
    //     }
    // }
    //对行列都进行控制
    for (i = 0; i < row; i++)
    {
        //打印一行的数据
        int j = 0;
        for (j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        //打印分隔行
        if (i < row - 1)
        {
            for (j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
    int a = 0;
    int b = 0;
    printf("*走\n");
    printf("请输入要下的坐标\n");
    while (1)
    {
        scanf("%d%d", &a, &b);
        //判断ab的合法性
        if (a >= 1 && a <= ROW && b >= 1 && b <= COL)
        {
            if (board[a - 1][b - 1] == ' ')
            {
                board[a - 1][b - 1] = *;
            }
            else
            {
                printf("该坐标已经输入过，请重新输入！\n");
            }
        }
        else
        {
            printf("输入坐标不对，请重新输入。\n");
            printf("横坐标值在1～%d之间。\n", ROW);
            printf("纵坐标值在1～%d之间。\n", COL);
        }
    }
}

//————————————————————————————————————————————————————————————————————————

void menu()
{
    printf("*************************************\n");
    printf("****1.paly            0.exit*********\n");
    printf("*************************************\n");
    //printf("*\_-*\_*-\_-*\_-*\_*-\_-*\_-*\_*-\_-*\n");
}
void game() //游戏的整个逻辑
{
    char board[ROW][COL] = {0}; //这里可以写成char board [3][3]={0};这是固定值了。
    //初始化棋盘
    InitBoard(board, ROW, COL);
    //打印棋盘
    DisplayBoard(board, ROW, COL);
    //下棋
    while (1)
    {
        //玩家下棋
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //电脑下棋
    }
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
            game();
            break;
        case 0:
            printf("游戏结束，即将关闭程序\n");
            break;
        default:
            printf("\n");
            printf("               \n");
            printf("--------------\n");
            printf("请选择‘1’或者’0‘\n");
            printf("--------------\n");
            printf("               \n");
            break;
        }
    } while (a);
}