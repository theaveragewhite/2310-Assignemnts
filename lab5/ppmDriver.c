/*
 * Name: Colton Owenby
 * Date Submitted: 10/3/2023
 * Lab Section: 001
 * Assignment Name: Lab 5
 * Email: coltono@clemson.edu
 */

#include "ppmUtil.h"
int main(int argc, char** argv)
{
  if(argc != 3)
  {
    printf("USAGE: <executable> <oldImage> <newImage>\n\n");
    return -1;
  }

	// open file for reading in and a new output file
  FILE* oldImage = fopen(argv[1], "r");
  FILE* newImage = fopen(argv[2], "w");

   if(!oldImage || !newImage)
   {
    printf("ERROR: File(s) could not be opened.\n");
    return -1;
   }

  image_t* image = read_ppm(oldImage);
  write_p6(newImage, image);
  free (image);
  free (newImage);
  return 0;
}
