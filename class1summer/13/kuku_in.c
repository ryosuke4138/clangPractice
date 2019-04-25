#include <stdio.h>
#include <stdlib.h>
int main(void){
  FILE *fp;
  fp = fopen("kukuin.txt", "r");
  if(fp == NULL){
    printf("Open error\n");
    exit(1);
  }
  int i, j, data;
  for(i=1; i<=9; i++){
    for(j=1; j<=9; j++){
      fscanf(fp, "%d", &data);
      if(data == i*j){printf("%3d-", data);
      }else{printf("%3dX", data);}
    }
    printf("\n");
  }
  fclose(fp);
  return 0;
}
