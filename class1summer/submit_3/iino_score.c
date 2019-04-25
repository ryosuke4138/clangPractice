#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, j, score, data = 0, count = 0, max = 0, min = 100, failure = 0;
    double average;
    FILE *fp;
    fp = fopen("score.txt", "r");
    if(fp == NULL){
        printf("open error\n");
        exit(1);
    }
    for(i = 0 ; i < 300 ; i++){
        fscanf(fp, "%d", &score);
        if(score != -1){
            count++;
            data += score;
            if(max < score){
                max = score;
            }
            if(min > score){
                min = score;
            }
        }
    }
    fclose(fp);

    average = (double)data / count;

    fp = fopen("score.txt", "r");
    if(fp == NULL){
        printf("open error\n");
        exit(1);
    }
    for(j = 300 ; j > 0 ; j--){
        fscanf(fp, "%d", &score);
        if(score != -1){
            if(score <= average - 0){
                failure++;
            }
        }
    }

    printf("Count: %d\n", count);
    printf("Average: %f\n", average);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("Failure: %d\n", failure);

    fclose(fp);
    return 0;
}