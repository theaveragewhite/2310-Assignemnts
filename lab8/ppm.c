#include "ppm.h"

void writeHeader(FILE* out, header_t hdr)
{
   fprintf(image, "%s %d %d %d ", hdr.type, hdr.width, hdr.height, hdr.maxVal);
}

void writePixel(FILE* out, pixel_t color)
{
  int row = 0;
  int col = 0;
  //unsigned char red,green,blue;
  pixel_t color = out->header;
  write_header(out_file, header);
  //red = green = blue = 0;
  /*Loop through the image and print each pixel*/
  for(row = 0; row < header.height; row++)
  {
    for(col = 0; col < header.width; col++)
    {
		 fprintf(out_file, "%c%c%c",
     image->pixels[row][col].r,
     image->pixels[row][col].g,
     image->pixels[row][col].b);
    }
  }

}
