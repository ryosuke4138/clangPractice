#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4

void PrintAb(double *A, double *b){ //行列・ベクトルを表示させる関数
  int i, j;
  double *ai;
  ai = A;

  printf("A, b= \n");
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      printf("%6.1f\t", *(ai+j));
    }
    printf("|%6.1f\t", *(b+i));
    printf("\n");
    ai+=N;
  }
}

int main(void){
  int i=0, j=0, k=0, p=0, pmax=0, tmp=0;
  double r;
  double *ai, *ak, *akk, *akkk;
  double *A, *b;
  int data_A[N][N] = { {2, 4, 1, -3},
                       {-1, -2, 2, 4},
                       {4, 2, -3, 5},
                       {5, -4, -3, 1} };
  int data_b[N] = { 0, 10, 2, 6 };

  /* 行列・ベクトルのメモリ確保 */
  A = (double *) malloc(N*N*sizeof(double)); //Aのメモリを割り当てる
  if(A==NULL){ //メモリの例外処理
    printf("Can't allocate memory.\n");
    exit(1);
  }
  b = (double *) malloc(N*sizeof(double)); //bのメモリを割り当てる
  if(b==NULL){ //メモリの例外処理
    printf("Can't allocate memory.\n");
    exit(1);
  }

  /* data_Aとdata_bの行列・ベクトルの入力 */
  ai = A;
  for(i=0; i<N; i++){
      for(j=0; j<N; j++){
          *(ai+j) = data_A[i][j];
      }
      ai+=N;
  }
  for(i=0; i<N; i++){
    *(b+i) = data_b[i];
  }
  PrintAb(A, b);


  /* 最大値検出, 行列の行の交換 */
  akkk = A;
  for(k = 0; k < N; k++){
    p = k;
    pmax = fabs( *(akkk+N*(k+1)) );
    for(i = k+1; i < N; i++){
      if(fabs( *(akkk+(N*i+k)) ) > pmax){
        p = i;
        pmax = fabs( *(akkk+(N*i+k)) );
      }
    }
    if(p != k){
      for(i = k; i < N; i++){
        tmp = *(akkk+(N*k+i));
        *(akkk+(N*k+i)) = *(akkk+(N*p+i));
        *(akkk+(N*p+i)) = tmp;
      }
      tmp = *(b+k);
      *(b+k) = *(b+p);
      *(b+p) = tmp;
    }
  }

  /*前進消去*/
  ai = A;
  ak = A;
  for(k=0; k<N-1; k++){   /* k= 0, ... , N-2 */
    for(i=k+1; i<N; i++){ /* i= k+1, ... , N-1 */
        r = *(ai+i*N+k) / *(ak+k);
      for(j=k; j<N; j++){ /* j= k, ... , N-1 */
	      *(ai+i*N+j) -= *(ak+j)*r;
      }
      *(b+i) -= *(b+k) * r;
    }
    ak+=N;
  }

  /* 階段行列 */
  akk = A;
  for(k=0; k<N; k++){
    r = *(akk+k);
    for(i=k; i<N; i++){
      *(akk+i) = *(akk+i) / r;
    }
    *(b+k) = *(b+k) / r;
    akk+=N;
  }
     
  /*後退代入*/
  ai=ak; //ak: A[-1][0]
  for(i=N-1; i>=0; i--){ /* i= N-1, ... , 0 */ //割る動作が不足
    for(j=i+1; j<N; j++){ /* i= i+1, ... , N-1 */
      *(b+i) -= *(ai+j)* *(b+j);
    }
    for(k=i+1; k<N; k++) *(ai+k) = 0;
    *(b+i) /= *(ai+i);
    ai-=N;
  }

  printf("\n"); /* 区切りのための改行 */
  PrintAb(A, b);

  /* メモリの解放 */
  free(A);
  free(b);
  
  return 0;
}
