#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void){
  int i;
  double r;
  FILE *fp;
  fp = fopen("tritable.txt", "w");
  if(fp == NULL){
    printf("Open error\n");
    exit(1);
  }
  for(i = 0 ; i < 90 ; i++){
    r = i / 180.0 * M_PI;
    fprintf(fp, "%f %f\n", sin(r), cos(r));
  }
  fclose(fp);
  return 0;
}
