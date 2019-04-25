#include<stdio.h>
#define SIZE 256
int main(void){
  char f[SIZE], g[SIZE];
  printf("Input family name: ");
  scanf("%s", f);
  printf("Input given name: ");
  scanf("%s", g);
  printf("Your name is %s %s.\n", g, f);
  return 0;
}
