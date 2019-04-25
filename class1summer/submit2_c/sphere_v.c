#include<stdio.h>
#include<math.h>
double sphere_V(double r){
    return 4.0 / 3 * M_PI * pow(r, 3);
}

double sphere_S(double r){
    return 4 * M_PI * pow(r, 2);
}

int main(void){
    double r, V, S;
    printf("Input a number: "); scanf("%lf", &r);

    V = sphere_V(r);
    S = sphere_S(r);

    printf("Volume is %.6f\n", V);
    printf("Surface is %.6f\n", S);

    return 0;
}
