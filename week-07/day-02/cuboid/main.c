#include <stdio.h>

// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

typedef struct rectangular_cuboid {
    double a;
    double b;
    double c;
}cuboid_t;

int get_surface(cuboid_t cuboid);
int get_volume(cuboid_t cuboid);

int main()
{
    cuboid_t cuboid;
    cuboid.a = 5;
    cuboid.b = 10;
    cuboid.c = 15;

    printf("Surface: %d\nVolume: %d\n", get_surface(cuboid), get_volume(cuboid));

    return 0;
}
int get_surface(cuboid_t cuboid)
{
    return 2*(cuboid.a+cuboid.b*cuboid.b+cuboid.c*cuboid.a+cuboid.c);
}
int get_volume(cuboid_t cuboid)
{
    return cuboid.a*cuboid.b*cuboid.c;
}