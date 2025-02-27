/*
 * Name: Colton Owenby
 * Date Submitted: 9/23/2023
 * Lab Section: 001
 * Assignment Name: Lab 4
 * Email: coltono@clemson.edu
 */

#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** readFile(FILE* fp, int *size);
void printMatrix (int** mat, int num);
int calculateVal(int ** mat, int size);
bool isRightDiagonal(int size, int row, int col);
bool isLeftDiagonal(int row, int col);

#endif
