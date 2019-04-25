#include<stdio.h>
#define SIZE 256

int s_match(char *x, char *y){
  int i, n=0, result;
  for(i=0; i<SIZE; i++){
    if(x[i] == 0)break;
    n++;
  }

  for(i=0; i<n; i++){
    result = 1;
    if(y[i] != x[i]){result = 0; break;}
  }
  return result;
}

int main(void){
  char x[SIZE], y[SIZE];
  printf("Input x: "); scanf("%s", x);
  printf("Input y: "); scanf("%s", y);

  int result;
  result = s_match(x, y);
  
  printf("Match %d\n", result);
  return 0;
}  
