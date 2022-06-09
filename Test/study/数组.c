#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"

//sizeof    求字符串所占的空间大小-计算对象的大小，单位是字节-是操作符
//strlen    求字符串的长度-只能求字符串-是库函数

//数组名————————数组名是数组首元素的地址（有两个例外）
//1.sizeof（数组名）-数组名表示整个数组，sizeof（数组名）计算的是整个数组的大小，单位是字节。
//2.&数组名，数组代表整个数组，&数组名，取出整个数组数组的地址。
int main()
{
    int arr[]={1,2,3,4,5,6};
    printf("%p\n",arr);
    printf("%p\n",&arr[0]);//这两种都是第一个元素的地址
    printf("%p\n",&arr);//数组的地址，整个数组

    printf("\n");
    //验证他们之间的不同
    printf("%p\n",arr+1);
    printf("%p\n",&arr[0]+1);//这两种都是第一个元素的地址
    printf("%p\n",&arr+1);//数组的地址，整个数组


    return 0;
}



/*
//实现一个冒泡排序函数将一个整形数组排序。
//本函数效率低下
void bubble_sort(int arr[], int sz) //此处出现过错误，是arr缺少[]，导致下方if判断语句出错，表达arr后不应该是变量等问题。
{
    int i = 0;
    //sz=sizeof(arr)/sizeof(arr[0]);//在函数内并不能你求出arr长度，在主函数内可以求出
    for (i = 0; i < sz - 1; i++) //需要进行sz-1趟冒泡排序
    {
        //每一趟冒泡排序的内容
        int a = 0;
        for (a = 0; a < sz - 1 - i; a++)
        {
            if (arr[a] > arr[a + 1])
            {
                int tmp = arr[a]; //tmp作为临时变量用以给arr交换值.
                arr[a] = arr[a + 1];
                arr[a + 1] = tmp;
            }
        }
    }
}
//对上方函数进行修改
void bubble_sort1(int arr[], int sz) //此处出现过错误，是arr缺少[]，导致下方if判断语句出错，表达arr后不应该是变量等问题。
{
    int i = 0;
    //sz=sizeof(arr)/sizeof(arr[0]);//在函数内并不能你求出arr长度，在主函数内可以求出
    for (i = 0; i < sz - 1; i++) //需要进行sz-1趟冒泡排序
    {
        int flag = 1; //假设本次排序的数据是顺序。
        //每一趟冒泡排序的内容
        int a = 0;
        for (a = 0; a < sz - 1 - i; a++)
        {
            if (arr[a] > arr[a + 1])
            {
                int tmp = arr[a]; //tmp作为临时变量用以给arr交换值.
                arr[a] = arr[a + 1];
                arr[a + 1] = tmp;
                flag = 0; //进入此循环就代表本次排序并未完成，既将flag赋值为0；
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {9, 8, 7, 27, 5, 4, 78, 2, 1, 237};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    bubble_sort(arr, sz);    //冒泡排序
    for (i = 0; i < sz; i++) //本处出现错误，判断条件多写了一个=号，导致排序后会出现一个随机值。原因溢出
    {
        printf("%d, ", arr[i]);
        //本处开始多写了一个i++，导致每次打印结果总是跳过了一位数。
    }
    printf("\n");
    bubble_sort1(arr, sz);   //冒泡排序
    for (i = 0; i < sz; i++) //本处出现错误，判断条件多写了一个=号，导致排序后会出现一个随机值。原因溢出
    {
        printf("%d, ", arr[i]);
        //本处开始多写了一个i++，导致每次打印结果总是跳过了一位数。
    }
    return 0;
}

/*
//二维数值
int main()
{
    int arr[2][3]; //2行3列,既有2行3列的矩阵
    char arr1[2][3];
    double aee3[3][5];
    int arr4[2][3] = {1, 2, 3, 4};       //不完全初始化。从左向右，从上至下填充，没有数值的自动填充为0；
    //int arr5[2][3] = {{1} 2, 3, 4, {5}}; //第一行放1，然后填充填充到5的一行。
    int arr6[][3] = {1, 2, 3, 4, 5};     //行可以省略，但是列不可以省略！！！
    int arr7[5][6]={1,2,3,4,5,6,7,8,2,4,6,3,7,5,3,5,3,7,34,5,6,2,34,6,};

    int i = 0;
    for (i = 0; i < 5; i++)
    {
        int j=0;
        for (j = 0; j < 6; j++)
        {
            printf("数组中%d的地址为%p\n", arr7[i][j],&arr7[i][j]);
        }
        printf("\n");
    }

    return 0;
}


//一维数组
//%p是打印地址
int main()
{
    int arr[] = {1, 2, 3, 4, 5};//为一维数值
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("arr中%d的地址为：%p\n", i, &arr[i]);
    }

    printf("aaaaa\n");
    return 0;
}


//数值
int main()
{
    //创建一个数组，存放10个整形变量


    int arr[10];
    char arr1[5];
    int n=4;//char arr3[n];  此处无用，n处需要为常量表达事，n为变量表达式。

    int arr3[5]={1,2,3};//不完全初始化，剩下的元素初始化默认为0；
    char arr4[3]={'a','c',98};//不完全初始化，剩下的元素初始化默认为0；数字为asll码的代码标识，98为b。
    char arr6[5]="adc";//存放了abc\0共四个元素，第五个元素为0；
    char arr7[]="asdasd";//会根据字符串内的内容自动规定数值的大小。最后一个字符为\0，总共事n+1字符。
    int sz =sizeof (arr3)/sizeof (arr3[0]);//求字符串长度
    printf ("%d\n",sz);




    return 0;
}
*/