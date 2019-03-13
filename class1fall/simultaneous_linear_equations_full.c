#include <stdio.h>
#include <stdlib.h>

void PrintAb(double *A, double *b, int N){ //行列・ベクトルを表示させる関数
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
  int i=0, j=0, k=0, N=0;
  double r;
  double *ai, *ak, *akk;
  double *A, *b;

  printf("Input N= "); //何正方行列を作るか
  scanf("%d", &N);

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

  /* 行列・ベクトルの入力 */
  ai = A; 
  for(i=0; i<N; i++){ //行列Aをscanfで入力させる
    for(j=0; j<N; j++){
      printf("A[%d][%d] = ",i, j); scanf("%lf", ai+j);
    }
    ai+=N;
  }
  for(i=0; i<N; i++){
    printf("b[%d] = ", i); scanf("%lf", b+i);
  }
  PrintAb(A, b, N); //入力されたA|bを表示

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
    PrintAb(A, b, N);
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
    PrintAb(A, b, N);
    ai-=N;
  }

  printf("\n"); /* 区切りのための改行 */

  /* メモリの解放 */
  free(A);
  free(b);
  
  return 0;
}
