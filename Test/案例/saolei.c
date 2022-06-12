#include "saolei.h"

int get_mine_count(char mine[ROWS][COLS], int a, int b)
{
    return mine[a - 1][b - 1] +
           mine[a - 1][b] +
           mine[a - 1][b + 1] +
           mine[a][b - 1] +
           mine[a][b + 1] +
           mine[a + 1][b - 1] +
           mine[a + 1][b] +
           mine[a + 1][b + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int a = 0;
    int b = 0;
    int cab= 0;
    while (cab < row * col - Count)
    {
        printf("请输入你认为有雷的坐标：>\n"); //本处应该放在循环内，如若放在循环外，答应的数值会放进scanf里面，然后无限循环
        scanf("%d%d", &a, &b);
        if (a >= 1 && a <= row && b >= 1 && b <= col)
        {
            //坐标合法
            if (mine[a][b] == '1')
            {
                printf("此坐标是雷，游戏失败！\n");
                DisplayBorad(mine, row, col);
                break;
            }
            else //计算ab坐标周围几个雷
            {
                int c = get_mine_count(mine, a, b);
                show[a][b] = c + '0'; //出错，导致行列交换了    
                DisplayBorad(show, row, col);
                cab++;
            }
        }
        else
        {
            printf("输入坐标错误，请重新输入！\n");
            printf("坐标值为1～%d\n", row);
            printf("纵坐标值为1～%d\n", col);
        }
    }
    if (cab == row * col - Count )
    {
        printf("游戏胜利，排雷结束！\n");
        printf("「」「」「」「」「」「」「」「」「」「」「」「」「」\n");
        DisplayBorad(mine, row, col);
    }
}

void SetMine(char borad[ROWS][COLS], int row, int col)
{
    int i = Count;
    while (i)
    {
        int a = rand() % row + 1; //生成1～9的随机数
        int b = rand() % col + 1;
        if (borad[a][b] == '0')
        {
            borad[a][b] = '1';
            i--;
        }
    }
}
void InitBorad(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBorad(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    //打印列号
    printf("   ");
    for (i = 1; i <= row; i++)
    {
        printf("  %d ", i);
    }
    printf("\n");

    for (i = 1; i <= row; i++)
    {
        printf(" %d ", i);

        for (j = 1; j <= col; j++)
        {

            printf("  %c ", board[i][j]);
        }

        printf(" \n");
    }
}

void game()
{
    //雷的信息存储
    //布置雷的信息数组
    //排除雷信息的数组
    char show[ROWS][COLS] = {' '}; //排查雷的信息
    char mine[ROWS][COLS] = {0};   //布置雷的信息
    //初始化
    InitBorad(mine, ROWS, COLS, '0');
    InitBorad(show, ROWS, COLS, '*');
    //打印棋盘
    DisplayBorad(show, ROW, COL);
    // DisplayBorad(mine, ROW, COL);
    //布置雷
    SetMine(mine, ROW, COL);
    DisplayBorad(mine, ROW, COL); //调试，看是否成功布置雷
    //扫雷
    FindMine(mine, show, ROW, COL);
}

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
    srand((unsigned int)time(NULL)); //!!!!!!
    do
    {

        menu();
        printf("请选择：>");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("扫雷游戏开始\n");
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
    } while (a); //判断真假，然后是否继续进入循环，
}

//--------------------------------------------------------------
int main()
{
    test();

    return 0;
}