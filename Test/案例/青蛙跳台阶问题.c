#include <stab.h>
#include <stdio.h>
#include <string.h>

//共有n个台阶
//一只青蛙，一次可以跳一个台阶，一次也可以跳到2个台阶
//这只青蛙如果跳到n个台阶，共有多少次跳法。

int qwttj1(int i) //递归的方式
{
    if (i == 0)
    {
        return 0;
    }
    else if (i == 1)
    {
        return 1;
    }
    else if (i == 2)
    {
        return 2;
    }
    else if (i >= 3)
    {
        return qwttj1(i - 1) + qwttj1(i - 2);
    }
}

//迭代
int qwttj2(int i)
{
    int a = 1;
    int b = 2;
    int c = 0;

    if (i >= 3) //防止在循环完成后直接跳出
    {

        while (i >= 3)
        {
            c = a + b;
            a = b;
            b = c;
            i--;
        }
        return c; //优先级很高，会导致直接跳出
    }
    if (i == 2)
    {
        c = c + 2;
    }
    else if (i == 1)
    {
        c = c + 1;
    }
    else if (i == 0)
    {
    }
    return c;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    qwttj2(n);
    printf("%d\n", qwttj2(n));
    qwttj1(n);
    printf("%d\n", qwttj1(n));
    return 0;
}