#include<stdio.h>
int main(void){
  char x, y, offset = 'a' - 'A';
  printf("Input a Capital letter: ");
  scanf("%c", &x);

  y = x + offset;

  printf("%c -> %c\n", x, y);
  return 0;
}
