//
// Created by EXEC_NOIR on 1/9/2019.
//

#ifndef RUN_RUN_H
#define RUN_RUN_H


typedef enum country{
    HUN,
    ENG,
    POL,
    JAP,
    USA,
    GER,
} country_t;

typedef struct competitor{
    char name[100];
    country_t country;
    int result;
} competitor_t;

int* randomize_results(int* array, int counter);

#endif //RUN_RUN_H
