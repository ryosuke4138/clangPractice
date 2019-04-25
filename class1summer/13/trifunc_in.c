#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void){
  int i, sin_abs = 0, cos_abs = 0;
  double r, c, s;
  FILE *fp;
  fp = fopen("app_tritable.txt", "r");
  if(fp == NULL){
    printf("Open error\n");
    exit(1);
  }
  for(i = 0 ; i < 90 ; i++){
    r = i / 180.0 * M_PI;
    fscanf(fp, "%lf", &s);
    if(fabs(s - sin(r)) < pow(10, (-4))){
      sin_abs++;
    }
    fscanf(fp, "%lf", &c);
    if(fabs(c - cos(r)) < pow(10, (-4))){
      cos_abs++;
    }
  }
  printf("Data count (sin): %d\n", sin_abs);
  printf("Data count (cos): %d\n", cos_abs);
  fclose(fp);
  return 0;
}
