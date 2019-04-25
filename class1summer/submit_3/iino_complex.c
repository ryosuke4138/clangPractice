#include <stdio.h>

struct my_complex{
  double re;
  double im;
};

struct my_complex complex_times(struct my_complex x, struct my_complex y){
  struct my_complex z;
  z.re = x.re * y.re - x.im * y.im;
  z.im = x.re * y.im + x.im * y.re;
  return z;
}

struct my_complex complex_devide(struct my_complex x, struct my_complex y){
  struct my_complex w;
  w.re = (x.re * y.re + x.im * y.im) / (y.re * y.re + y.im * y.im);
  w.im = (x.im * y.re - x.re * y.im) / (y.re * y.re + y.im * y.im);
  return w;
}

int main(void){
  struct my_complex x, y, z, w;
  printf("Real part of x = "); scanf("%lf", &x.re);
  printf("Imaginary part of x = "); scanf("%lf", &x.im);
  printf("Real part of y = "); scanf("%lf", &y.re);
  printf("Imaginary part of y = "); scanf("%lf", &y.im);

  z = complex_times(x, y);
  w = complex_devide(x, y);

  printf("x*y = %f + %fi\n", z.re, z.im);
  printf("x/y = %f + %fi\n", w.re, w.im);
  return 0;
}
