#include <stdio.h>
#include <string.h>

void encode(char[], char[], char[], int);

int main()
{
    char str1[60] = "a short phrase";
    char key1[35] = "a sample key";
    char e[60];
    char d[60];

    printf("\nTesting key1: a sample key\n");
    printf("---------------------------\n");
    printf("original: %s\n", str1);
    encode(str1, e, key1, 0);
    printf("encoded: %s\n", e);
    encode(e, d, key1, 1);
    printf("decoded: %s\n", d);

    return 0;
}
