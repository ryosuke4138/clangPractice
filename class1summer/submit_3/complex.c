#include<stdio.h>
#include<math.h>

struct my_complex{
  double re;
  double im;
};

struct my_complex complex_mul(struct my_complex x, struct my_complex y){
  struct my_complex z = {};
  z.re = x.re * y.re - x.im * y.im;
  z.im = x.re * y.im + x.im * y.re;
  return z;
}

struct my_complex complex_div(struct my_complex x, struct my_complex y){
  struct my_complex z = {};
  z.re = ( x.re * y.re + x.im * y.im ) / ( pow(y.re, 2) + pow(y.im, 2) );
  z.im = ( x.im * y.re - x.re * y.im ) / ( pow(y.re, 2) + pow(y.im, 2) );
  return z;
}

int main(void){
  struct my_complex x, y, z_mul, z_div;
  printf("Real part of x = "); scanf("%lf", &x.re);
  printf("Imaginary part of y = "); scanf("%lf", &x.im);
  printf("Real part of x = "); scanf("%lf", &y.re);
  printf("Imaginary part of y = "); scanf("%lf", &y.im);

  z_mul = complex_mul(x, y);
  z_div = complex_div(x, y);

  printf("x*y = %f + %fi\n", z_mul.re, z_mul.im);
  printf("x/y = %f + %fi\n", z_div.re, z_div.im);
  return 0;
}

