#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"

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