#include<stdio.h>
void triangle(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n -1; j++){
            if(j < i){
                printf(" ");
            }else if(2 * n - i - j > 1){
                printf("*");
            }
        }
        printf("\n");
    }
    return;
}

int main(void){
    int n;
    printf("Input a natural number: "); scanf("%d", &n);

    triangle(n);
    
    return 0;
}

