#include "saolei.h"

void InitBorad(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBorad(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 1; i < row; i++)
    {
        for (j = 1; j < col; j++)
        {
            printf(" %c", board[i][j]);
        }
        printf(" \n");
    }
}