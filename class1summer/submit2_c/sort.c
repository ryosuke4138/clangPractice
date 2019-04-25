#include<stdio.h>
#include<math.h>
#define SIZE 10
void sort10(int *data){
    for(int i = 0; i < SIZE; i++){
        for(int j = i + 1; j < SIZE; j++){
            if(data[i] > data[j]){
                int tmp =  data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
    return;
}

int main(void){
    int i, data[SIZE] = {39, 77, 31, 22, 4, 6, 72, 7, 90, 55};
    printf("before: ");
    for(i = 0; i < SIZE; i++){
        printf("%d", data[i]);
        if(i != SIZE - 1){printf(", ");}
    }
    printf("\n");
    
    sort10(data);
    
    printf("sorted: ");
    for(i = 0; i < SIZE; i++){
        printf("%d", data[i]);
        if(i != SIZE - 1){printf(", ");}
    }
    printf("\n");
    return 0;
}
