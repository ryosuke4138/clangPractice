#include<stdio.h>
int main(void){
  char x;
  printf("Input a letter: ");
  scanf("%c", &x);
  printf("x = %c, code: %d\n", x, x);
  return 0;
}
