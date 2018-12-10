#include <iostream>
#include <stdio.h>


int main() {
    FILE *fptr;
    fptr = fopen("../my-file.txt", "r");

    int text = 0;
    while(text != EOF){
        text = fgetc(fptr);
        printf("%c", text);
    }

    return 0;
}