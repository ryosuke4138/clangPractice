#include<stdio.h>
#define SIZE 256
int main(void){
  char x[SIZE];
  printf("Input x: ");
  scanf("%s", x);
  
  int n;
  for(int i=0; i<SIZE; i++){
    if(x[i] == 0)break;
    n++;
  }
  
  printf("Length: %d\n", n);
    return 0;
}  
