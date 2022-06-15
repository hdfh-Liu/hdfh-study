#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//结构体
/*
//是一些值的集合，这些值称为成员变量。结构体的每个成员可以是不同类型的变量。

//用学生为例，介绍结构体。

//要描述一个学生，例如name等。
//struct是结构体关键字，不能修改。stu为结构体标签，课随意修改。 struct stu结构体声明。

// struct stu//第一种写法
// {
//     //成员变量
//     char name[10];
//     short age;
//     int tele[12];
//     char sex[5];
// }s1,s2,s3;//s1,s2,s3是三个全局的结构体变量，与下面的s相似，这里的是变量

typedef struct stu//第二种写法,将struct stu这个局部变量改名为stu，主函数中可以使用stu直接创建变量。
{
     //成员变量
    char name[10];
    short age;
    int tele[12];
    char sex[5];
}stu;//这个结构体的新名字，这里的stu是类型


int main()
{
    //struct stu s;//为局部变量
    stu s2;
    stu s3={"刘某",20,"123445678","男"}；
    
    return 0;
}


//结构体中包含结构体

struct s
{
    int a;
    char c;
    char aaa[10];
    double d;
};

struct t
{
    char ch[10];
    struct s S;
    char *pc;
};

int main()
{
    //初始话结构体
    struct t T={"hh",{10,'q',1212312,2.33123},NULL};//嵌套结构体初始化
    printf("%s\n",T.ch);
    printf("%s\n",T.S.c);//结构体的反问通过.这个操作符可以进行反问
    return 0;
}

*/
//结构体传参
//针对结构体变量传参是使用.     针对结构体指针式采用->.在以后的使用尽量采用指针方式。
typedef struct stu
{
    char name[20];
    short age;
    char tese[12];
    char sex[5];
}stu;

void printf1(stu s)//方式一
{
printf("%s\n",s.name);
printf("%s\n",s.tese);
}

void printf2(stu* s)//方式二
{
    printf("%s\n",s->name);
    printf("%s\n",s->tese);
}


//选择打印时最好选择方式二，直接取用数据。方式一需要将数据在拷贝一份，然后调用，会当数值很大时，可能会溢出，也会降低效率。
int main()
{
    stu s={"刘某",20,"12345678233","男"};
    printf1(s);
    printf2(&s);
}