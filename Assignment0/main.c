#include <stdio.h>
#include <math.h>

int main(int argc, char** argv)
{
    int a = 12;
    int b = 8;
    int c = 7;
    double s = (a + b + c) / 2.0;
    double area;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("s = %f\n", s);

    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("area = %f\n", area);
    return 0;
}