/*============================================================
; Program: Hardware Multiplication Algorithm
; Name: Colton Owenby
; Course: 2310
; Section: 001
; Program Number: Programming Assignment 2
; Date: 6/9/2024
: Description: Binary Calculator
 ============================================================*/
#include <stdio.h>
#include <stdlib.h>

void prt_bin(int value, int length)
{
    for (int i = length - 1; i >= 0; i--)
    {
        if ((value >> i) & 1)
            putchar('1');
        else
            putchar('0');
    }
}

int main()
{
  int multiplicand, multiplier;
  unsigned int c = 0, acc = 0, mq, mdr;

  printf("multiplicand: ");
  scanf("%d", &multiplicand);
  printf("multiplier: ");
  scanf("%d", &multiplier);

  //Error Checking for a value outside of the range
  if (multiplicand < 0 || multiplicand > 255 || multiplier < 0 || multiplier > 255)
  {
      printf("Error: Both values must be between 0 and 255.\n");
      return 1;
  }

  mq = multiplier;
  mdr = multiplicand;

  printf("\nc and acc set to 0\n");
  printf("mq set to multiplier    = %3d decimal and ", multiplier);
  prt_bin(mq, 8); printf(" binary\n");
  printf("mdr set to multiplicand = %3d decimal and ", multiplicand);
  prt_bin(mdr, 8); printf(" binary\n");
  printf("---------------------------------------------------\n");

  for (int step = 1; step <= 8; step++)
  {
      printf("step %d:   %d ", step, c);
      prt_bin(acc, 8); printf(" ");
      prt_bin(mq, 8); printf("\n");
      //Checks the least significant bit
      if (mq & 1)
      {
          printf("        +   ");
          prt_bin(mdr, 8); printf("        ^ add based on lsb=1\n");
          acc += mdr;
          //Ensures a carry
          if (acc > 255)
          {
            c = 1;
            acc &= 0xFF;
          }
      }
      else
      {
        printf("        +   ");
        prt_bin(0, 8); printf("        ^ no add based on lsb=0\n");
      }

      printf("          ----------\n");
      printf("          %d ", c);
      prt_bin(acc, 8); printf(" ");
      prt_bin(mq, 8); printf("\n");

      int new_bit = acc & 1;
      acc >>= 1;
      acc |= (c << 7);
      mq >>= 1;
      mq |= (new_bit << 7);
      c = 0;
      //Prints the result after after the shift
      printf("       >>                     shift right\n");
      printf("          %d ", c);
      prt_bin(acc, 8); printf(" ");
      prt_bin(mq, 8); printf("\n");
      printf("---------------------------------------------------\n");
  }
   //Prints the check
  printf("check:                 binary   decimal\n");
  printf("                     ");
  prt_bin(mdr, 8); printf("       %3d\n", multiplicand);
  printf("           x         ");
  prt_bin(multiplier, 8); printf("  x    %3d\n", multiplier);
  printf("             ----------------    ------\n");
  //Prints the total calculation
  unsigned int product = multiplicand * multiplier;
  printf("             ");
  prt_bin(product, 16); printf("     %5d\n", product);

  return 0;
}
