#include <stdio.h>
#include <math.h>

//方程式cos(x) = x^2 の解をニュートン法によって解くプログラムをf'(x) = -sin(x) - 2xの計算箇所を数値微分を用いて書け。
//ニュートン法 x(i+1) = x(i) - f(x(i)) / f'(x(i))
//関数ポインタを用いて書け。

double func(double x){ //f(x) = cos(x) - x^2 を返す関数
  double y;
  y = cos(x) - pow(x, 2);
  return y;
}

double Newton(double x, double eps){ //ニュートン法の値を返す関数
  int i = 0;
  double h = 1e-4;
  int max_iteration = 100; //最大反復回数の設定
  double x_new, fx, dfx;
  double (*func_p)(double); //func_pを2つの
  func_p = func; //func_pに関数funcへのポインタを代入

  while (i < max_iteration) {
    fx = func_p(x);
    dfx = (func_p(x+h) - func_p(x)) / h;
    x_new = x - fx / dfx;
    if (fabs(x_new - x) < eps) break; //収束条件 |x(i+1) - x(i)| < ε
    if (fx == 0) break; //f(x)が0になれば終了
    else x = x_new;
    printf("x(%d) = %+.6f\n", i+1, x);
    i++;
  }
  return x;
}

int main(void){
  double x = 1.0, eps = 1e-6;
  printf("initial value: %.6f\n", x);
  x = Newton(x, eps);
  printf("answer = %.6f\n", x);
  return 0;
}


