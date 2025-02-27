/*
 * Name: Colton Owenby
 * Date Submitted: 10/3/2023
 * Lab Section: 001
 * Assignment Name: Lab 5
 * Email: coltono@clemson.edu
 */

#include "ppmUtil.h"
void writeHeader(FILE* image, header_t head)
{
  fprintf(image, "%s %d %d %d ", head.type, head.width, head.height, head.maxVal);
}
void writePixels(FILE* image,pixel_t* p, header_t head)
{

}

pixel_t* readPixels(FILE* image, header_t head)
{
  int row = 0;
  int col = 0;
  unsigned char red,green,blue;
  red = green = blue = 0;
  image_t* image= allocate_memory(head);
  for(row = 0; row < head.height; row++)
  {
    for(col = 0; col < head.width; col++)
    {
      fscanf(image, "%c%c%c", &red, &green, &blue);
      image->pixels[row][col].r = red;
      image->pixels[row][col].g = green;
      image->pixels[row][col].b = blue;
    }
  }

  return image;
}

pixel_t* read(FILE* in, header_t *head)
{

}
void write(FILE* image, header_t head, pixel_t* pix)
{


}

pixel_t* allocatePixMemory(header_t h)
{
  int row;

  /* First allocate memory for the image_t . The image_t
    has a header and a double pointer for the pixels            */
  pixel_t* image = (pixel_t*) malloc(sizeof(pixel_t));

  /* After you have allocated the memory for the image_t,
    you can now set the header equal to the header passed in.   */
  image->header = header;

  /* Now we need to allocate the memory for the actual pixels.
    This is a 2d array so allocate for the 2D array.            */
  image->pixels = (pixel_t**) malloc(sizeof(pixel_t*) * header.height);
  for(row = 0; row < header.height; row++)
  {
    image->pixels[row] = (pixel_t*)malloc(sizeof(pixel_t) * header.width);
  }

  return image;
}

void ckComment(FILE* in)
{

}

void readHeader(FILE* in, header_t *hdr)
{
  fscanf(in, "%s %d %d %d ", hdr.type, &hdr.width, &hdr.height, &hdr.maxVal);
  return hdr;
}

void freeMemory(pixel_t* pix)
{

}
