#include <stdio.h>
#include <stdlib.h>

// Function to compute the offset of element a[i][j] in a 2D array
/*int offset(int i, int j, int n) {
    return (i * n + j) * 4;
}*/

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s i j n\n", argv[0]);
        return 1;
    }

    // Convert command-line arguments to integers
    int i = atoi(argv[1]);
    int j = atoi(argv[2]);
    int n = atoi(argv[3]);

    // Compute the offset
    int result = offset(i, j, n);

    // Print the result
    printf("The offset for a[%d][%d] is %d\n", i, j, result);

    return 0;
}
