#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h" //数学库函数


/* 
//*********函数的声明和定义*********
//函数的声明
int add(int, int);

//主函数
int main()
{
    int a = 12;
    int b = 5;
    int sum = 0;
    scanf("%d%d", &a, &b);
    //函数调用
    sum = add(a, b);
    printf("%d\n", sum);
    return 0;
}
//+++++++声明定义的正确使用，将声明放在函数的头文件内，既.h文件。
//+++++++将定义放在函数的c文件内，既.c文件
//+++++++使用在编写代码中，引用头文件，不用在额外声明。
//+++++++自己写的代码库，既头文件，在引用时使用双引号“”，使用标准库使用尖括号<>。

//函数的定义
int add(int x, int y)
{
    int sum = x + y;
    return sum;
}
 */

//*********printf的嵌套使用需要注意的事项。*********
/* int main()
{
    printf("%d",printf("%d",printf("%d",printf("%d",45))));//printf返回值为int整形变量，返回值为打印的个数。本句话为打印45+2+1+1
    return 0;
} */

/* //*********函数嵌套调用，链式访问*********
int main()
{
    int a = 0;
    //第一种方式，正常使用。
    a = strlen("abc");
    printf("%d\n", a);
    //第二种方式，链式访问。
    printf("%d\n", strlen("abc")); //链式访问。
    return 0;
} */

/* //*********每调用一次函数，就将num的值+1.*********
void add(int *p) //p是指针变量
{
    (*p)++; //括号的用途是将*p加一，若是没有括号，则只是p加一。++的优先级较高，注意加括号。
}

int main()
{
    int num = 0;
    add(&num);
    printf("%d\n", num);
    add(&num);
    printf("%d\n", num);
    add(&num);
    printf("%d\n", num);
    add(&num);
    printf("%d\n", num);

    return 0;
} */

/* //用函数表示二分查找值
int binary_search(int arr[], int i, int sz) //这个地方的arr是主函数数组的首元素的地址，本质上这里的arr是指针.出现的问题：err后没有加[]导致无法运行。
{
    //int sz = sizeof(arr) / sizeof(arr[0]); //得到元素个数在函数中无法计算，既在主函数计算
    int left = 0;
    int right = sz - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] < i)
        {
            left = mid + 1;
        }
        else if (arr[mid] > i)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    //在一个有序数组中查找某一个数，
    //查找到值返回对应数到下标，没有找到返回-1
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 6;
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret = binary_search(arr, i, sz); //二分查找到意思，即为函数名
    if (ret == -1)
    {
        printf("没有找到对应的数值。\n");
    }
    else
    {
        printf("对应数值的下标为%d\n", ret);
    }

    return 0;
} */

/* //用函数方式判断一年是不是闰年
int runnian(int x)
{
    int a = 0;
    if (x % 4 == 0 && x % 100 != 0) //瑞年判断规则，1、能被4整除，不能被100整除。2、能被400整除。
    {
        return 1;
    }
    else if (x % 400 == 0)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int i = 0;
    int a = 0;
    for (i = 1000; i < 2000; i++)
    {
        if (runnian(i) == 1)
        {
            printf("%d为闰年,", i);
            a++;
        }
    }
    printf("\n共有%d个闰年\n", a);
    return 0;
} */

/* //用函数打印一个素数
int is_sushu(int x) //注意函数的命名，可能会与代码库中的重复。
{

    int a = 0;
    for (a = 2; a <= sqrt(x); a++)
    {
        if (x % a == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int i = 100;
    int b = 0;
    for (i = 100; i < 200; i++)
    {
        if (is_sushu(i) == 1)
        {
            printf("%d.", i);
            b++;
        }
    }
    printf("\n共有%d个素数\n", b);

    return 0;
} */

/* //通过函数，对两个整形变量进行交换。
void Swap(int x, int y) //这里的void表示该函数没有返回值
{
    int c = 0;
    c = x;
    x = y;
    y = c;
}//该函数不能实现交换功能
void Swap2(int *pa, int *pb) //int* 叫做指针变量，对两个变量的存放地址进行操作
{
    int d = 0;
   // d = *pa; // * pa 为解引用操作，既找到该地址，取出该地址内的内容
    *pa = *pb;
    *pb = d;
}
int Swap3(int x, int y)
{
    int e = 0;
    e = x;
    x = y;
    y = e;
    return x;
    return y;
}//该函数不能实现交换功能，切无用
int main()
{
    int a = 10;
    int b = 17;
    //Swap2(&a, &b);
    Swap3(a, b);
    printf("a=%d,b=%d\n", a, b);

    return 0;
} */

/* //定义函数比较两函数的大小
//定义函数
int get_max(int x, int y)//这里的int表示有返回值
{
    int c = 0;
    if (x > y)
    {
        c = x;
    }
    else
    {
        c = y;
    }

    return c;
}
//使用定义函数
int main()
{
    int a = 0;
    int b = 0;
    int max = 0;
    scanf("%d%d",&a,&b);
    get_max(a, b);
    max = get_max(a, b);
    printf("%d\n", max);

    return 0;
} */

/* 
int main()
{
    //memset,memory- set,内存设置。
    char arr[]="****i love yo*******u";
    memset(arr,'o',13);
    printf("%s\n",arr);


    return 0;
}

 */

/* int main()
{
    //strlcpy  -string copy,字符串拷贝
    char arr1[] = "steing";
    char arr2[10] = "&&&&%%%&&";
    strcpy(arr2-1, arr1);
    printf("%s\n", arr2);
    return 0 ;
} */

/* int add(int x, int y)
{

    int z = 0;
    z = x + y;
    return z;
}

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d%d",&a,&b);
    int sum = add(a, b);
    printf("%d\n", sum);

    return 0;
} */



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