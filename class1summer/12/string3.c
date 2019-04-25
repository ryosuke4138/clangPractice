#include<stdio.h>
#define SIZE 256

void s_reverse(char *x, char *y){
  int i, n=0;
  for(i=0; i<SIZE; i++){
    if(x[i] == 0)break;
    n++;
  }

  for(i=0; i<n; i++){
    y[i] = x[n - i -1];
  }
  return;
}

int main(void){
  char x[SIZE], y[SIZE];
  printf("Input x: "); scanf("%s", x);

  s_reverse(x, y);
  
  printf("x: %s\n", x);
  printf("y: %s\n", y);
  return 0;
}  
