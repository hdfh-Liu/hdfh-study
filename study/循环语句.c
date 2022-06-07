#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"

//go to 语句

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


//循环语句

//猜密码三次是否正确
/* int mian()
{

    int i = 0;
    char mima[10] = {0};
    for (i = 0; i < 3; i++)
    {
        printf("请输入密码");
        scanf("%s", mima);
        // if (mima == "123456") //等号不能用于字符串之间的比较，应该使用一个库函数-strcmp
        if (strcmp(mima, "123456") == 0)
        {
            printf("正确，登陆成功");
            break;
        }
        else
        {
            printf("密码错误");
        }
    }
    if (i == 3)
    {
        printf("三次密码错误，退出系统\n");
    }

    return 0;
} */

//编写代码，演示两个字符向中间移动
/* int main()
{
    char arr1[] = "illove";
    char arr2[] = "######";
    int left = 0;

    int sz = sizeof(arr1) / sizeof(arr1[0]); //(可以求，要求麻烦)
    int right = sz - 2;
    //  int sz = strlen (arr1)  - 1;

    //for (left = 0; left <= right; left++,right++) 逗号出现问题。
    // {
    while (left <= right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("% s\n", arr2);
        //Sleep(1000);
        //system("cls");
        left++;
        right++;
        //}
    }

    return 0;
} */

//二分查找算法
/*
int main()
{
    //二分查找算法
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 7;
    int sz = sizeof(arr) /sizeof(arr[0]); //计算元素个数
    int left = 0; //左下标
    int right = sz - 1; //右下标
    while (left <= right) 
    {
        int mid = (left + right) /2;
        if (arr[mid] > k) //出现错误，表现为死循环（if (arr[mid>k])）
        {
            right = mid - 1;
            
        }
        else if (arr[mid] < k) 
        {
            left = mid + 1;
        }
        else 
        {
            printf("找到了, 下标为： % d\n", mid );
            break;
        }
    }
    if (left < right) 
    {
        printf("找不到\n" );
    }
    return 0;
}

*/

//10的阶乘和
/*int main()
{
    
    int i = 0;
    int m = 0;
    int ret = 1;
    int sum = 0;
    for (m = 1; m <= 10; m++) 
    {
        ret = 1;
        for (i = 1; i <= m; i++) 
        {
            ret = ret*i;
        }
        sum = ret + sum;
        
    }
    printf("%d\n", sum);
    return 0;
} 
*/
