#include <stdio.h>
#include "Run.h"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));


    int results[5];
    for (int i = 0; i < 5; ++i) {
        results[i] = -1;
    }
    for (int j = 0; j < 5; ++j) {
        printf("%d ", results[j]);
    }
    printf("\n");
    randomize_results(results, 0);
    for (int j = 0; j < 5; ++j) {
        printf("%d ", results[j]);
    }

    return 0;
}