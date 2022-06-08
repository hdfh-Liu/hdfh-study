#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h" //数学库函数
#include "time.h" //时间库函数

void menu()
{
    printf(" 新游戏即将开始， 做出你的选择  \n");
    printf("********************************\n");
    printf("*****   1.play       0.exit*****\n");
    printf("********************************\n");
    printf("\n");
}
void game()
{
    int c = 0;
    //引入时间戳
    //time_t time(time_t *timer).time_t是一个长整形
    //scanf((unsigned int)time(NULL));这个代码放在主函数内，放在void函数内每次都调用，使得随机数不够随机。
    printf("猜数字游戏开始\n");
    c = rand() % 100 + 1; //生成随机数的函数。生成固定数之间的数值。例如1～100；右键time能看到数值范围，将范围摸上100，能得到1～99的数值。并且不能放入下面的do循环，不然每次选择玩后就从新生成随机数
                          // printf("%d\n", c);//这里为打印测试书写
    while (1)
    {
        int d = 0; //接收猜的数值
        printf("请输入你猜的数值\n");
        scanf("%d", &d);
        if (d > c)
        {
            printf("猜测数值大于随机数\n");
        }
        else if (d < c)
        {
            printf("猜测数值小于随机数\n");
        }
        else
        {
            printf("猜测正确，数值为%d\n", c);
            break;
        }
    }
}
int main()
{
    int a = 0;
    srand((unsigned int)time(NULL)); //见上方
    do
    {
        menu();
        printf("请选择");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            game();
            break;
        case 0:
            printf("游戏结束\n");
            break;
        default:
            printf("选择错误，请输入“1”或“0”\n");
            break;
        }
    } while (a); //a=0为假，跳出循环。

    return 0;
}