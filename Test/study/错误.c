#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"

//出现错误，不知道是哪里的问题，待修正

//数组
// int mian()
// {
//     int arr[] = {1, 2, 3, 4,5};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         printf("arr中[%d]的地址为:%p\n", i,&arr[i]);
//     }

//     return 0;
// }

//正确的代码如下
//数组
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         printf("arr中%d的地址为：%p\n", i, &arr[i]);
//     }

//     printf("aaaaa\n");
//     return 0;
// }