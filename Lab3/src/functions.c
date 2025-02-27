/*
 * Name: Colton Owenby
 * Date Submitted: 9/14/2023
 * Lab Section: 001
 * Assignment Name: Lab 3
 * Email: coltono@clemson.edu
 */
#include "functions.h"

void numSentences(FILE* in, FILE* out)
{
  //Variables
  char sentence; int total = 0;
  //Reads in every character in the file till the file ends.
  while((sentence=fgetc(in)) != EOF)
    {
        //Determines if the character in the sentence variable matches.
        if(sentence == '.' || sentence == '?' || sentence == '!')
        {
          //Determines if the matched character from above is not the same,
          //and determines if it was the same character from before.
          if(sentence == !fgetc(in) || sentence == fgetc(in))
          {
              if(sentence-1 == fgetc(in))
              {
                total++;
              }
              total--;
          }
          total++;
        }
    }
    //Outputs to a new file.
    fprintf(out, "Number of sentences are %d.\n", total);
}

void numWords(FILE* in, FILE* out)
{
  //Variables
  char word; int total = 0;
  //Reads in every character in the file till the file ends.
  while((word = fgetc(in)) != EOF)
    {
        //Determines if the character in the word variable matches.
        if(word == ' ' || word == '\t' || word == '\n' || word == '\0')
        {
          total++;
        }

    }
  //Outputs to a new file.
  fprintf(out, "Number of words are %d.\n", total);
}
