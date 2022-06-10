#define ROW 3
#define COL 3

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"
//声明
void InitBoard(char board[ROW][COL],int row,int col );//和void game 输出的数值一致
void DisplayBoard(char board[ROW][COL],int row,int col );
void PlayerMove(char board[ROW][COL],int row,int col );
void ComeptuerMove(char board[ROW][COL],int row,int col );
char IsWin(char board[ROW][COL],int row,int col );
int IsFull(char board[ROW][COL],int row,int col );
void menu();
void game(); //游戏的整个逻辑
void test();