#include <stdio.h>
#include <stdlib.h>
int main(void){
  FILE *fp;
  fp = fopen("kukuout.txt", "w");
  if(fp == NULL){
    printf("Open error\n");
    exit(1);
  }
  int i, j;
  for(i=1; i<=9; i++){
    for(j=1; j<=9; j++){
      fprintf(fp, "%d", i*j);
    }
    fprintf(fp, "\n");
  }
  return 0;
}
