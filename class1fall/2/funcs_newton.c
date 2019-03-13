#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include "newton.h"
#include <stdbool.h>

/* y = x - 1.2*exp(-x) */
double func_1(double x){
  return x-1.2*exp(-x);
}

/* y = x*sin(x)+log(x) */
double func_2(double x){
  return x*sin(x)+log(x);
}

/* differential */
double func_d(double x,double(*f)(double)){
  double h;
  h = 1e-6;
  return (f(x+h) - f(x))/h ;
}

/* newton */
double newton(double x, double error, int max_iteration, double(*f)(double)){
  for(int i=0; i<max_iteration; i++){
    double x_new = x - (f(x) / func_d(x, *f));
    if(fabs(x - x_new) < error) break;
    x = x_new;
  }
  return x;
}

