#include<stdio.h>
#include<math.h>
void sphere(double r, double *pV, double *pS){
    *pV = 4.0 / 3 * M_PI * pow(r, 3);
    *pS = 4 * M_PI * pow(r, 2);
    return;
}

int main(void){
    double r, V, S;
    printf("Input a number: "); scanf("%lf", &r);

    sphere(r, &V, &S);

    printf("Volume = %.6f\n", V);
    printf("Surface = %.6f\n", S);

    return 0;
}
