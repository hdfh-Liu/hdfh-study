#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*
//指针
int main()
{
    int a=10;
    int* p=&a;//指针变量，既指针

    return 0;
}


//指针与指针类型
//指针在存放地址时能够全部存放，但是在修改地址内内容时需要指针类型。
int main()
{
    // printf("%d\n", sizeof(char *));
    // printf("%d\n", sizeof(int *));
    // printf("%d\n", sizeof(double *));
    // printf("%d\n", sizeof(short *));
    //都是8个字节，此电脑为64位电脑

    int a = 0x11223344;
    int* pa = &a;
    *pa=0;//内存里面的11223344全部变成0；
    char* pc = &a;
    *pa=0;//内存里面的11223344只有44一个字节变成0；
    printf("%p\n", pa);
    printf("%p\n", pc);
    return 0;
}

//指针加减整数
int main()
{
    int a=0x11223344;
    int* pa=&a;
    char*pc=&a;
    printf("%p\n",pa);
    printf("%p\n",pa+1);//整形指针加了一个整形，即四个字节
    printf("%p\n",pc);
    printf("%p\n",pc+1);//char指针加了一个char既一个字节


    return 0;
}

//野指针:指针指向位置是不可知的（随机的、不正确的、没有明确限制的）

//指针没有初始化
int main()
{
    int *p; //指针没有初始化，默认为随机值
    *p = 10;
    return 0;
}

//指针越界访问
int main()
{
    int arr[10]={0};
    int* p=arr;
    int i=0;
    for ( i = 0; i < 11; i++)
    {
        //当指针指向的位置范围超出数值时，就是野指针。
        *(p++)=i;
    }
    

    return 0;
}

//指针指向的空间释放


int main()
{
    //指针初始化
    int a=0;
    int*pa=&a;
    int*p=NULL;//NULL,用来初始化指针的，或者给指针赋值的
}


//指针运算
//指针+—运算
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 8};
    int i = 0;
    int sz = sizeof(arr[]) / sizeof(arr[0]);
    int *p = arr;
    for (i = 0; i < sz; i++)
    {
        printf("%d\n", *p);
        p = p + 1;
    }
    return 0;
}

//指针-指针:指针与指针之间的得到中间的元素个数（指向同一块空间的，不能指向不同的空间）
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    printf("%d\n",&arr[7]-&arr[2]);
    return 0;
}


//strken-求字符串长度的实现。
int my_strlen(char *str)//注意加指针*
{
    char *starrt = str;
    char *len = str;
    while (*len != '\0')//注意加指针*
    {
        len++;
    }

    return len - starrt;
}

int main()
{
    char arr[] = "bit";
    int b = my_strlen(arr);
    printf("%d\n", b);
}


//指针和数组

int main()
{
    int arr[10] = {0}; //数组名时首元素的地址
    printf("%p\n", arr);
    printf("5p\n", &arr[0]);
    //前面有说过，

    return 0;
}

//二级指针
int main()
{
    int a = 10;
    int *pa = &a;    //这里是一级指针变量
    int **ppa = &pa; //这里的ppa是二级指针,依次类推，多级指针
    //使用
    printf("%d\n",**ppa);
    printf("%d\n",*pa);
    printf("%d\n",*ppa);

    printf("%p\n",*pa);
    printf("%p\n",*ppa);
    printf("%p\n",**ppa);

    return 0;
}
*/

//指针数组——本质上是数组——存放指针的数值
int main()
{
    int a = 10;
    int b = 2;
    int c = 6;
    int *pa = &a;
    int *pb = &b;
    int *pc = &c;
    //在多数值情况下很麻烦，可以这样写
    int *arr[3] = {&a, &b, &c}; //指针数组
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
    printf("%d\n", *arr[0]);//*为解引用操作符，即通过arr里面的数值，找到对应的地址，然后取出地址内的值。
    printf("%d\n", *arr[1]);
    printf("%d\n", *arr[2]);
    return 0;
}

//数组指针——本质上是指针
