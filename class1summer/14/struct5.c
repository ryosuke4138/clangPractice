#include<stdio.h>

struct my_complex{
  double re;
  double im;
};

struct my_complex complex_add(struct my_complex x, struct my_complex y){
  struct my_complex z = {};
  z.re = x.re + y.re;
  z.im = x.im + y.im;
  return z;
}

int main(void){
  struct my_complex x, y, z;
  printf("Real part of x = "); scanf("%lf", &x.re);
  printf("Imaginary part of y = "); scanf("%lf", &x.im);
  printf("Real part of x = "); scanf("%lf", &y.re);
  printf("Imaginary part of y = "); scanf("%lf", &y.im);

  z = complex_add(x, y);

  printf("z = %f + %fi\n", z.re, z.im);
  return 0;
}

