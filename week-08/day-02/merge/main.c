#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int* pointer = malloc(10*sizeof(int));
    int* pointer2 = malloc(10*sizeof(int));
    int numbers = 0;
    for (int i = 0; i < 10; ++i) {
        pointer[i] = numbers;
        numbers +=2;
    }
    numbers = 1;
    for (int j = 0; j < 10; ++j) {
        pointer2[j] = numbers;
        numbers+=2;
    }
    /*for (int k = 0; k < 10; ++k) {
        printf("%d\n", pointer2[k]);
    }*/
    pointer2 = realloc(pointer2, 20*sizeof(int));
    for (int k = 0; k < 10; ++k) {
        pointer2[k+10] = pointer[k];
    }
    for (int l = 19; l > -1; --l) {

        printf("%d\n",pointer2[l]);
    }
    free(pointer);
    free(pointer2);
    return 0;
}