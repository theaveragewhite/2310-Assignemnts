/*
 * Name: Colton Owenby
 * Date Submitted: 9/23/2023
 * Lab Section: 001
 * Assignment Name: Lab 4
 * Email: coltono@clemson.edu
 */

#include "functions.h"

//Check to make sure you have a backup of the input.txt since
//it is being cleared

int main(int argc, char** argv)
{
    printf("Checking command line arguments.\n");

    if (argc < 2)
    {
        printf("Not enough arguments: ./exe filename\n");
        exit(-1);
    }

    FILE* fp = fopen(argv[1], "r");
    if(fp==NULL)
    {
        printf("fp did not open\n");
        exit(-1);
    }
    int size = 0;
    int **mat = readFile(fp, &size);
    printMatrix(mat, size);
    calculateVal(mat, size);

    return 0;
}
