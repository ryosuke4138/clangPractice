#include <stdio.h>
#include "newton.h"

int main(void){
  double error, x;
  int max;

  x = 1.0; /* 初期値 */
  error = 1e-6;/* 収束条件 */
  max = 100; /* 反復回数 */

  double (*f[])() = {func_1, func_2};
  for(int i=0; i<2; i++){
    double n = newton(x, error, max, *f[i]);
    printf("%f\n", n);
  }

  return 0;
}
