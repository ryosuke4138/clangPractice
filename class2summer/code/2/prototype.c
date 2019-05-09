
#include <stdio.h>
double avg4(double v1, double v2, double v3, double v4);
int main(void)
{
    double p1, p2, p3, p4;
    double avg;
    p1 = 1.0; p2 = 2.0; p3 = 3.0; p4 = 4.0;
    avg = avg4(p1, p2, p3, p4);
    printf("p1  = %f, p2  = %f,\n", p1, p2);
    printf("p3  = %f, p4  = %f\n", p3, p4);
    printf("avg = %f\n", avg);
    return 0;
}
double avg4(double v1, double v2, double v3, double v4)
{
    double a;
    a = (v1 + v2 + v3 + v4)/4;
    v1 = 10.0;
    return a;
}
