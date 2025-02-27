#include <stdio.h>
int main()
{
int a, b, c;
a = 0;
b = 1;
c = 0;

	while (a <= 17)
	{
		a = a + b;
		c++;
	}

      printf("A = %d, B = %d, C = %d\n", a, b, c);
 }
