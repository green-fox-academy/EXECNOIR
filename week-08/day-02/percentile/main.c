#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int main()
{
    int size1 = 0;
    int size2 = 0;
    scanf("%d", &size1);
    scanf("%d", &size2);

    float* matrixptr = (float*)malloc((size1*size2) * sizeof(float));

    for (int i = 0; i < size2; ++i) {
        for (int j = 0; j < size1; ++j) {
            scanf("%f", &matrixptr[i * size1 + j]);
        }
    }
    for (int k = 0; k < size2; ++k) {
        for (int l = 0; l < size1; ++l) {
            if((k * l) < (size1*size2)*(80/100))
            {
                printf("%.1f ", matrixptr[k * size1 + l]);
            }
        }
        printf("\n");
    }



    /*for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%d", &matrixptr[i][j]);
        }
    }*/

    return 0;
}