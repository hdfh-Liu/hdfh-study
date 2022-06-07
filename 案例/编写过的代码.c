#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h" //数学库函数


/* //一个关机程序
int main()
{
    char input[10] = {0};
    system("shutdown -s -t 60"); //system执行系统命令的，shutdown -s -t 60 为在60秒内关机。
    again:
    printf("你的电脑将在一分内关机，如果输入“我是猪“，就取消关机！\n");
    scanf("%s", input);
    if (strcmp(input, "我是猪") == 0) //比较两个字符串-strcomp（）
    {
        system("shudown -a");
    }
    else
    {
        goto again;
    }
    return 0;
} */

/* //打印乘法口诀
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int i = 0; //行数
    int x = 0;
    for (i = 1; i <= 9; i++)
    {

        int j = 1;
        for (j = 1; j <= i; j++)
        {
            x = i * j;
            printf("%d*%d=%-2d ", i, j, x);//x可以不定义直接编写为i*j
        }
printf("\n");
    }

    return 0;
} */

//求最大值
/* int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int max = arr[0]; //最大值直接赋值为0，在比对负数的会出现最大值为0的情况，所以直接将数组中的某一个值赋值给max。
    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]); //得到元素个数
    //scanf("arr[%d%d%d%d%d%d%d%d%d%d]",&a,&b,&c,&d,&e,&f,&g,&h)
    for (i = 1; i < sz; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("最大值为：%d", max);

    return 0;
}
 */


/* //分数求和(1/1+1/2-1/3```1/100)
int main()
{
    int a = 1;
    int b = 1;
    double sum = 0.0;
    for (b = 1; b <= 100; b++)
    {
        sum += a * 1.0 / b;
        a = -a;
    }

    printf("和为：%lf/n", sum);

    return 0;
} */


/* //计算1～100之间有多少个9.
int main()
{
    int a = 0;
    int i = 0;
    for (i = 2; i < 100; i++)
    {
        if (i % 10 == 9)//十位数有9
        {
            a++;
        }
        if (i / 10 == 9)//个位数有9
        {
            a++;
        }
    }

    printf("共有%d个9", a);

    return 0;
} */


/* //打印素数
int main()
{
    int i = 0;
    int a = 0;
    int b = 0;
    //sqrt-开平方的数学库函数
    for (i = 100; i <= 200; i++)
    {
        for (a = 2; a < sqrt(i); a++)
        {
            if (i % a == 0)
            {
                break;
            }
        }
        if (a > sqrt(i))
        {
            printf("%d为素数,", i); 
            b++;
        }
    }


    //第一种方法
    for (i = 100; i <= 200; i++)
    {
        //素数判断的规则，1、试除法，只能被本身和1整除。2、
        int a=0;
        for (a = 2; a < i; a++)
        {
            
            if (i % a == 0)
            {
                break;
            }
           
        }
        if (a == i)
            {
                printf("%d为素数,",i);
                b++;
            }
    } */
/*    printf("\n共有%d个素数", b);
    return 0;
} 
*/


//打印闰年
/*int main()
{
    int i = 0;
    int a = 0;
    for (i = 2000; i <= 3000; i++)
    {
        if (i % 4 == 0 && i % 100 != 0) //瑞年判断规则，1、能被4整除，不能被100整除。2、能被400整除。
        {
            printf("%d为闰年\n", i);
            a++;
        }
        else if (i % 400 == 0)
        {
            printf("%d为闰年\n", i);
            a++;
        }
    }
     //   if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
    //{
      //  printf("%d为闰年\n", i);
       // a++;
    //}
        printf("\n共有%d个闰年", a);

    return 0;
}
*/


/*//求最大公约数
int main()
{

    int a = 0;
    int b = 0;
    int r = 0;
    scanf("%d%d", &a, &b);//出现过错误，既取地址符忘添加。
    while (a % b)//节约步骤可以写为while(r=a%b),将下面的r去除。
    {
        r = a % b;
        a = b;
        b = r;
    }
    printf("最大公约数为：%d\n", b);

    return 0;
}
*/


//求1～100里，3的倍数。
/*int main()

{
    int i = 0;
    for (i = 1; i < 100; i++)
    {
        if (i % 3 == 0)
        {
            printf("%d\n", i);
        }
    }
}
*/


//求三个值从大到小的排序
/*int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int r = 0;
    scanf("%d%d%d", &a, &b, &c);
    if (a < b)
    {
        r = a;
        a = b;
        b = r;
    }
    if (a < c)
    {
        r = a;
        a = c;
        c = r;
    }
    if (b < c)
    {
        r = b;
        b = c;
        c = r;
    }

    printf("%d %d %d\n", a, b, c);
    return 0;
}
*/

/* int main()
{

printf("你好，世界。\n");

    return 0;
} */