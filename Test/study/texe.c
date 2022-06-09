#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"

//实现一个冒泡排序函数将一个整形数组排序。
void bubble_sort(int arr[], int sz)
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
                int b = arr[a];
                arr[a] = arr[a + 1];
                arr[a + 1] = b;
            }
        }
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    bubble_sort(arr,sz); //冒泡排序
    for (i = 0; i < sz; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}
