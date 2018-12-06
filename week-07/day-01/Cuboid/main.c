#include <stdio.h>

int main() {
    double l;
    double w;
    double h;
    printf("Height: \n");
    scanf("%lf", &h);
    printf("Width: \n");
    scanf("%lf", &w);
    printf("Lenght: \n");
    scanf("%lf", &l);

    double surf = 2*(l*w+w*h+h*l);
    double volume = l*w*h;

    printf("Surface: %0.lf\n", surf);
    printf("Volume: %0.lf\n", volume);
    return 0;
}