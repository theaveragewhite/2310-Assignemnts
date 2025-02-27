/*
 * Name: Colton Owenby
 * Date Submitted: 9/14/2023
 * Lab Section: 001
 * Assignment Name: Lab 3
 * Email: coltono@clemson.edu
 */

#include "src/functions.h"

int main(int argc, char* argv[])
{

  //Opens the file for read access with the given command line argument.
  FILE *fp1;
  fp1 = fopen(argv[1], "r");
  //Opens a new files called output to write the answers to.
  FILE *fp2;
  fp2 = fopen("output.txt", "w");

  //If the correct number of arguments are not called it automatically aborts the program.
  assert(fp1);

  //Calls the functions numSentences and numWords.
  //Fseek() resets where the file pointer is in the file.
  //So the example below means it is being intialized and reset to the beginning of the file.
  fseek(fp1, 0, SEEK_SET);
  numSentences(fp1, fp2);
  fseek(fp1, 0, SEEK_SET);
  numWords(fp1, fp2);

  //Closes the file
  fclose(fp1);
  fclose(fp2);

  return 0;
}
