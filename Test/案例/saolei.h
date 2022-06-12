#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2 
#define Count 80


void InitBorad(char borad[ROWS][COLS], int rows,int cols,char set);//直接传set，就把需要填充的数据直接上传过去，
void DisplayBorad(char board[ROWS][COLS],int row,int col);
void SetMine(char borad[ROWS][COLS],int row,int col);

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);

int get_mine_count(char mine[ROWS][COLS], int a, int b);
