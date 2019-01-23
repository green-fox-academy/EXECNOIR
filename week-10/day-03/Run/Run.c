//
// Created by EXEC_NOIR on 1/9/2019.
//
#include "Run.h"
#include <stdlib.h>
#include <stdio.h>

competitor_t* create_competitors()
{
    competitor_t comp1;


}

int* randomize_results(int* array, int counter)
{
    int same = 0;
    int random = rand()%5+1;
    if(counter > 4){
        return array;
    }else{
        for (int i = 0; i < 5; ++i) {
            if(random == array[i]){
                same = 1;
            }
        }
    }

    if(same == 1){
        return randomize_results(array, counter);
    }else{
        array[counter] = random;
        return randomize_results(array, counter+1);
    }
}