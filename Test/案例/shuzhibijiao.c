#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h" //数学库函数



//求最大值
int main()
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


