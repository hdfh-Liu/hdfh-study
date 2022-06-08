#include <stab.h>
#include <stdio.h>
#include <string.h>

//三个柱子，上面有n个铁饼，上小下大放置。
//将n个铁饼移动到另一根柱子上需要多少步？

//递归
int hlt(int n)
{
    if (n >= 3)
    {
        while (n >= 3)
        {
            return 2 * hlt(n-1)+ 1;
        }
    }
     else if (n == 2)
    {
        return 3;
    }
    else if (n == 1)
    {
        return 1;
    }
    else 
    return 0;
}

int main()
{
    int n = 0;
    qishi:
    scanf("%d", &n);
    hlt(n);
    while (hlt(n)==0)
    {
        printf("请输入大于0的整数\n");
        goto qishi;
    }
    printf("共需要移动%d步\n",hlt(n));
    return 0;
}