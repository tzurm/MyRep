#include <stdio.h>

#define true 0
#define false 1
#define ROW 4
#define COL 3

void SetMatrixZeros(int arr[ROW][COL], int row, int col)
{

    int arr_row[ROW] = {false};
    int arr_col[COL] = {false};
    int i = 0;
    int j = 0;
    for (i = 0; i < row; ++i)
    {
        arr_row[i] = false;
    }
    for (i = 0; i < col; ++i)
    {
        arr_col[i] = false;
    }

    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
        {
            if (0 == arr[i][j])
            {
                arr_row[i] = true;
                arr_col[j] = true;
            }
        }
    }

    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
        {
            if (true == arr_row[i] || true == arr_col[j])
            {
                arr[i][j] = 0;
            }
        }
    }
}

void PrintMatrix(int arr[][COL], int row, int col)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {

            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int arr[ROW][COL] = {
        {0, 11, 12},
        {14, 15, 16},
        {14, 15, 0},
        {14, 15, 16}};

    PrintMatrix(arr, ROW, COL);
    puts("");
    SetMatrixZeros(arr, ROW, COL);
    PrintMatrix(arr, ROW, COL);

    return 0;
}

/*
         t   f   t
    t    {0, 11, 12},           {0, 11, 12}
    f    {14, 15, 16},          {14, 15, 16}
    t    {14, 15, 0},           {14, 15, 0}
    f    {14, 15, 16}};         {14, 15, 16}


*/