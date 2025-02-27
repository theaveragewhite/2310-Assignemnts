#include <stdio.h>

void readInfo(FILE*, header_t*, circle_t*);

int isHitCir(circle_t, point_t);

void makeCircle(FILE* out, circle_t* cir, int w, int h);
