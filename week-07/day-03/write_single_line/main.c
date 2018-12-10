#include <stdio.h>

int main() {
    FILE *fptr = fopen("../my-file.txt", "a+");


    fputs("\nGabor", fptr);
    fclose(fptr);
    return 0;
}