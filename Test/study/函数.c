#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"
//函数库搜索了解网址：cplusplus.com。可以直接进入网址了解函数的名称意义等内容。
//同上还有一个网址：cppreference.com。分中英文，在前面家zh或en。


//求第n个斐波那契数。（不考虑溢出）斐波那契数列：前两个数之和等于第三个数。
//描述第n个斐波那契数的公式。当n<2时，n=1。当n>2时，第n个等于(n-1)+(n-2)。
//递归的方式
int fib(int i) //计算过于臃肿，屏蔽掉
{
    int a = 1;
    if (i <= 2)
    {
        return 1;
    }
    else
    {
        //return i = fib(i - 1) + fib(i - 2);  这里会改变i的值，使得后面的fib不在准确。
        return fib(i - 1) + fib(i - 2);
    }
}
//迭代
int fib1(int i)
{
    int a = 1;
    int b = 1;
    int c = 1;

    while (i > 2)
    {
        c = a + b;
        a = b;
        b = c;
        i--;
    }
    return c;
}
int main()
{
    int i = 0;
    int a = 0;
    scanf("%d", &i);

    //fib(i);
    // a = fib(i);
    // printf("%d\n", a);
    // printf("%d\n", fib(i));
    printf("%d\n", fib1(i)); //打印fib1方式求的值

    return 0;
}//i过大，结果会溢出，造成结果为负值等错误。

/*
//递归加上循环
//求出n的阶乘，不考虑溢出
int fac1(int i)
{
    int a = 0;
    int b = 1;//b的初始值为1，这样下面的乘积才能正确。
    for (a = 1; a <= i; a++)
    {
        b *= a;
    }

    return b;
}
int fac2(int i)//方法2，当n<=1时，n的阶乘就是1，当n>1时，n的阶乘就是n*(n-1)。
{
    if (i<=1)
    {
        return i;
    }
    else
    {
        i*=fac2(i-1);
        return i;
    }
    
    return 0;
}
int main()
{
    int i = 0;
    int a = 0;
    int b = 0;
    scanf("%d", &i);
    fac1(i); //求阶乘的第一种方式
    a = fac1(i);
    printf("%d\n", a);
    fac2(i);
    b = fac2(i);
    printf("%d\n", b);

    return 0;
}

/*
//递归
//编写函数，不允许创建临时变量，求字符串长度。
int my_strlen(char *str) //str为指针变量！！ 为第一种长度计算方法，但是中间还是存在临时变量
{
    int a = 0;
    while (*str != '\0') //出现编写错误，将str改为char会提示char不是错误
    {
        a++;
        str++;
    }
    return a;
}
int my_strlen1(char *str)
{
    if (*str != '\0')
    {
        return 1 + my_strlen1(str + 1);
    }
    else
        return 0; //当此处返回值为1时，其总的字符串长度会加1.(原因是放if执行完后会继续执行return，导致值上加)
}

int main()
{
    char arr[] = "bit";
    scanf("%s", &arr);
    int len = my_strlen(arr); //arr事数组，数值传参，传过去的不是整个数值，而是第一个元素的地址
    int len1 = my_strlen1(arr);
    printf("字符串长度为%d\n", len);
    printf("字符串长度为%d\n", len1);

    return 0;
}


//递归
//输入一个整形值（无符号），按照顺序打印它的每一位。例如：输入1234，打印：1 2 3 4.
void print(int n)
{
    if (n > 9)
    {
        print(n / 10);
    }
    printf("%d ", n % 10);
}
int main()
{
    unsigned int num = 0;
    scanf("%d", &num); //输入1234
    //递归
    print(num);

    return 0;
}


//函数的声明和定义
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


//printf的嵌套使用需要注意的事项。
int main()
{
    printf("%d",printf("%d",printf("%d",printf("%d",45))));//printf返回值为int整形变量，返回值为打印的个数。本句话为打印45+2+1+1
    return 0;
} 

//函数嵌套调用，链式访问
int main()
{
    int a = 0;
    //第一种方式，正常使用。
    a = strlen("abc");
    printf("%d\n", a);
    //第二种方式，链式访问。
    printf("%d\n", strlen("abc")); //链式访问。
    return 0;
}

//每调用一次函数，就将num的值+1.
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
}

//用函数表示二分查找值
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
} 

//用函数方式判断一年是不是闰年
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
} 

//用函数打印一个素数
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
} 
//通过函数，对两个整形变量进行交换。
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
} 

//定义函数比较两函数的大小
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
} 


int main()
{
    //memset,memory- set,内存设置。
    char arr[]="****i love yo*******u";
    memset(arr,'o',13);
    printf("%s\n",arr);


    return 0;
}



int main()
{
    //strlcpy  -string copy,字符串拷贝
    char arr1[] = "steing";
    char arr2[10] = "&&&&%%%&&";
    strcpy(arr2-1, arr1);
    printf("%s\n", arr2);
    return 0 ;
} 

int add(int x, int y)
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
}  */