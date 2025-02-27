/*
 * Name: Colton Owenby
 * Date Submitted: 9/23/2023
 * Lab Section: 001
 * Assignment Name: Lab 4
 * Email: coltono@clemson.edu
 */

#include "functions.h"

int** readFile(FILE* fp, int *size)
{
    fscanf(fp, "%d", size);
    int num = *size;
    int index = 0;

    int** mat = (int**)malloc(num * sizeof(int*)); //num amount of rows
    for(index = 0; index < num; index++)
        mat[index] = (int*)malloc(num * sizeof(int)); //num amount of columns

    int row = 0;
    int col = 0;
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            fscanf(fp, "%d", &mat[row][col]);
        }
    }
    return mat;
}


void printMatrix (int** mat, int num)
{
    int row = 0;
    int col = 0;
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            printf("%.2d\t", mat[row][col]);
        }
        printf("\n");
    }

}

int calculateVal(int** mat, int size)
{
  int sum = 0;
  int row = 0;
  int col = 0;
  for(row = 0; row < size; row++)
  {
      for(col = 0; col < size; col++)
      {

        if(!isLeftDiagonal(row, col) && isRightDiagonal(size, row, col))
        {
          sum += mat[row][col];
        }
        else if(isLeftDiagonal(row, col) && isRightDiagonal(size, row, col))
        {
          sum += mat[row][col];
        }
      }
  }
  printf("Total = %.2d\n", sum);
  return 0;
}

bool isRightDiagonal(int size, int row, int col)
{
  if(row != col && row != size - 1 - col)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isLeftDiagonal(int row, int col)
{
  if(row == col)
  {
    return true;
  }
  else
  {
    return false;
  }
}
