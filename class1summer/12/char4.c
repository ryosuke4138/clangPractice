#include<stdio.h>
int main(void){
  char x, y, offset = 'a' - 'A';
  printf("Input a letter: ");
  scanf("%c", &x);
  
  if(x < 91){
    y = x + offset;
  }else if(x > 96){
    y = x - offset;
  }

  printf("%c -> %c\n", x, y);
  return 0;
}
