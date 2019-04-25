#include <stdio.h>
#include <stdlib.h>
#define SIZE 300

int main(void){
  FILE *fp;
  fp = fopen("score.txt", "r");
  if(fp == NULL){
    printf("Open error\n");
    exit(1);
  }

  int i, data[SIZE], count = 0, max = 0, min = 100, failure = 0;
  double average;
  for(i = 0; i < SIZE; i++){
    fscanf(fp, "%d", &data[count]);
    if(data[count] != -1){
      average += data[count];
      if(data[count] > max){max = data[count];}
      if(data[count] < min){min = data[count];}
      count++;
    }
  }
  fclose(fp);
  average /= count;

  for(i = 0; i < count; i++){
    if(data[i] < average - 20){failure++;}
  }

  printf("Count: %d\n", count);
  printf("Average: %f\n", average);
  printf("Max: %d\n", max);
  printf("Min: %d\n", min);
  printf("Failure: %d\n", failure);
  return 0;
}