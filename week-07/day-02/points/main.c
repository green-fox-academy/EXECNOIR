#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:

int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
*/

typedef struct point{
    float x;
    float y;
}points_t;

points_t construct_point(float x, float y);
float distance_between_points(points_t point1, points_t point2);

int main()
{
    points_t p1 = construct_point(1, 1);
    points_t p2 = construct_point(1, 5.5);
    float dist = distance_between_points(p1, p2);
    printf("%.2f", dist);
    return 0;
}

points_t construct_point(float x, float y){
    points_t point;
    point.x = x;
    point.y = y;
    return point;
}
float distance_between_points(points_t point1, points_t point2){
    //return valami gyököt kell vonni meg kisfaszom
}