/*============================================================
; Program: Floating Point
; Name: Colton Owenby
; Course: 2310
; Section: 001
; Program Number: 11
; Date: 6/19/2024
: Description: Generates a table of all 256 possible 8-bit floating point numbers
 ============================================================*/

#include <stdio.h>

int main()
{
  int sign, exp, fraction, significand;
  int i;
  float f;
  float prev = 0;

  for (i = 0; i < 256; i++)
  {
    /* begin your code */
    //Shift right by 7 to get the sign bit and mask it with 1
    sign = (i >> 7) & 0x1;
    //Shift right by 3 to get the exponent bits and mask with 0xF
    exp = (i >> 3) & 0xF;
    //Masks with 0x7 to get the last 3 bits as the fraction
    fraction = i & 0x7;

    //Determines if the number is normalized or denormalized
    if (exp == 0)
    {

      significand = fraction;
      exp = -7;
    }
    else
    {

      significand = 8 + fraction;
      exp = exp - 8;
    }


    f = (float)significand / 8.0;

    //Adjusts the significand by scaling it according to the exponent
    if (exp > 0)
    {

      while (exp > 0)
      {
        f *= 2.0;
        exp--;
      }
    }
   else if (exp < 0)
    {
      while (exp < 0)
      {
        f /= 2.0;
        exp++;
      }
    }

    //Applies the sign to the final floating-point value
    if (sign)
    {
      f = -f;
    }

    /* end your code */

    printf ("%02x => %08x = %+11.6f (spacing = %+11.6f)\n",
            i, *(int*) &f, f, prev-f);
    prev = f;
  }

  return 0;
}
