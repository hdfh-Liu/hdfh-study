/*#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//编写代码，演示两个字符向中间移动
int main()
{
    char arr1[] = "illove";
    char arr2 [] = "######";
    int left = 0;
    int right = strlen(arr1)  - 1;
    
    //int sz = sizeof(arr1) /sizeof(arr1[0]); //(可以求，要求麻烦)
    //int right = sz - 2;
    //  int sz = strlen (arr1)  - 1;
    
    
    //for (left = 0; left <= right; left++,right--) 逗号出现问题。
    // {
        while (left <= right) 
        {
            arr2[left] = arr1[left];
            arr2[right] = arr1[right];
            printf( "% s\n", arr2 );
            //Sleep(1000);
            left++;
            right--;
            //}
          }
    
    
    
    return 0;
}
*/
//代码在windows上可正常运行
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//#include "windows.h"
//#include "stblib.h"
//编写代码，演示两个字符向中间移动
int main()
{
    char arr1[] = "illove";
    char arr2[] = "######";
    int left = 0;
    // int sz = sizeof(arr1) / sizeof(arr1[0]); //(可以求，要求麻烦)
    int right = strlen(arr1) - 1;
    // int sz = strlen (arr1)  - 1;
    //for (left = 0; left <= right; left++,right++) 逗号出现问题。
    // {
    while (left <= right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s\n", arr2);
        //Sleep(1000);
        // system("cls");
        left++;
        right--;
        //}
    }
    return 0;
}