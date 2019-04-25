#include<stdio.h>
#define SIZE 256
void s_convert(char *x, char *y){
  char offset = 'a' - 'A';
  int i, n = 0;
  for(i = 0; i < SIZE; i++){
    if(x[i] == '\0')break;
    n++;
  }
  for(i = 0; i < n; i++){
    if(x[i] <= 'Z' && x[i] >= 'A'){
      y[i] = x[i] + offset;
    }else{
      y[i] = x[i];
    }
  }
  return;
}


int main(void){
  char x[SIZE], y[SIZE];
  printf("Input: "); scanf("%s", x);
  
  s_convert(x, y);

  printf("x: %s\n", x);
  printf("y: %s\n", y);
  return 0;
}
