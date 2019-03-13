#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#define N 4

int main(void) {
  int i=0, k=0, j=0, p=0, pmax=0, tmp=0;  
  double** a;
  double* x;
  double* b;
  double r;

  /* 行列・ベクトルのメモリ確保 */
  a = (double**)malloc(sizeof(double*) * N);
  for(i=0; i<N; i++){
    a[i] = malloc(sizeof(double) * N);
  }
  x = (double*)malloc(sizeof(double) * N);
  b = (double*)malloc(sizeof(double) * N);

  /* 行列・ベクトルの入力 */
  a[0][0] = 2 ;  a[0][1] = 4 ;  a[0][2] = 1 ; a[0][3] =-3 ; b[0] = 0;
  a[1][0] = -1;  a[1][1] =-2 ;  a[1][2] = 2 ; a[1][3] = 4 ; b[1] = 10;
  a[2][0] = 4 ;  a[2][1] = 2 ;  a[2][2] =-3 ; a[2][3] = 5 ; b[2] = 2;
  a[3][0] = 5 ;  a[3][1] =-4 ;  a[3][2] =-3 ; a[3][3] = 1 ; b[3] = 6;


  /* 最大値検出,　行列の行の交換 */
  p = k;
  pmax = fabs( a[k][k] );
  for(i = k+1; i < N; i++){
  if(fabs( a[i][k] ) > pmax){
    p = i;
    pmax = fabs( a[i][k] );
    } 
  }
  if(p != k){
    for(i = k; i < N; i++){
      tmp = a[k][i];
      a[k][i] = a[p][i];
      a[p][i] = tmp;
    }
    tmp = b[k];
    b[k] = b[p];
    b[p] = tmp;
  }

  /* 前進消去 */
  for(k=0; k<N; k++){        
    for(j=k+1; j<N; j++){
      r = a[j][k] / a[k][k] ;
      for(i=k+1; i<N; i++) a[j][i] -= a[k][i] * r;
      b[j] -= r * b[k];
    } 
  }

  /* 階段行列 */
  for(i=0; i<N; i++){
    for(j=0; j<N; j++) printf("%f\t", a[j][i]);
    printf("%f\n", b[i]);
  }

  /* 後退代入 */
  for(i=N-1; i>=0; i--){
    x[i] = b[i];
    for(j=N-1; j>i; j--) x[i] -= a[i][j]*x[j];
    x[i] /= a[i][i];
  }

  /* 出力 */
  printf("%f %f %f %f \n", x[0], x[1], x[2], x[3]);

  free(a);
  free(b);
  free(x);

  return 0;
}
