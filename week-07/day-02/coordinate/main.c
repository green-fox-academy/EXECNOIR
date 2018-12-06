#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Create a struct to store coordinates (for example: int x and int y)
// Create an array which can store coordinates, do not create multidimensonal arrays here
// Fill up the coordinates in the array with random number.


typedef struct coordinates{
    int x;
    int y;
}coordinates_t;

int main()
{
	srand(time(0));
	coordinates_t array[5];

	for (int i = 0; i <= sizeof(array)/sizeof(array[0]) ; ++i) {
		coordinates_t coordinate;
		coordinate.x = rand()%200;
		coordinate.y = rand()%200;
		array[i] = coordinate;

	}

	for (int j = 0; j < sizeof(array)/sizeof(array[0]) ; ++j) {
		printf("X: %d Y: %d\n", array[j].x, array[j].y);
	}

	return 0;
}