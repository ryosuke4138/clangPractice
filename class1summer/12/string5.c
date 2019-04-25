#include<stdio.h>
#define SIZE 256

int s_match(char *x, char *y){
  int i, result;
  for(i=0; i<SIZE; i++){
    result = 1;
    
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
