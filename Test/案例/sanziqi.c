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
                board[a - 1][b - 1] = '*';
                break; //已经填充值了，在填充完成后需要跳出输入坐标。不然会一直需要输入坐标
            }
            else
            {
                printf("该坐标已经输入过，请重新输入！\n");
            }
        }
        else
        {
            printf("该坐标已经有值，请重新输入。\n");
            printf("横坐标值在1～%d之间。\n", ROW);
            printf("纵坐标值在1～%d之间。\n", COL);
        }
    }
}
void ComeptuerMove(char board[ROW][COL], int row, int col)
{
    printf("#走\n");
    int a = 0;
    int b = 0;
    while (1)
    {

        a = rand() % ROW; //rand生成随机值，在test生成，因为只能生成一次。
        b = rand() % COL;
        if (board[a][b] == ' ')
        {
            board[a][b] = '#';
            break; //已经填充值了，在填充完成后需要跳出输入坐标。不然会一直需要输入坐标
        }
        else
        {
        }
    }
}
char IsWin(char board[ROW][COL], int row, int col) //能返回四种值，用以判断双方输赢，是否平局。游戏继续｜｜｜返回*#分别表示*#赢，返回J表示游戏继续，返回P表示平局。
{
    int i = 0;
    //判断行
    for (i = 0; i < ROW; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][0]; //可以直接返回对应数组内的内容
            // if (board == '*')
            // {
            //     return *;
            // }
            // if (board == '#')
            // {
            //     return #;
            // }
        }
    }
    //判断列
    for (i = 0; i < COL; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
        {
            return board[1][i];
        }
    }
    //对角线判断
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if (IsFull(board, ROW, COL) == 1)
    {
        return 'p';
    }

    return 'C';
}
//判断是否平局  返回1表示棋盘满了，返回0表示棋盘没有满
int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
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
    char ret = 0;               //判断的临时变量
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
        //判断输赢
       ret = IsWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }

        //电脑下棋
        ComeptuerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //判断输赢
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
    }
    if (ret == '*')
    {
        printf("下*的玩家胜利～～～\n");
    }
    else if (ret == '#')
    {
        printf("下#玩家胜利～～～\n");
    }
    else
    {
        printf("---平局---\n");
    }
}
void test()
{ 
    int a = 0;
    srand((unsigned int)time(NULL)); //将NULL的时间搓作为srand 的随机生成器，时间搓返回的数值为time-t类型，需要修改为长整形。需要引用stbilb和time的头文件
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

int main()
{

    test();

    return 0;
}