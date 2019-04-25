#include <stdio.h>
#define SIZE 256

void s_convert (char *x, char *y){
    int i, j, offset;
    offset = 'a' - 'A';
    for(i = 0 ; i < SIZE ; i++){
        if(x[i] == '\0'){break;}
    }
    for(j = 0 ; j < i ; j++){
        if(x[j] >= 'A' && x[j] <= 'Z'){
            y[j] = x[j] + offset;
        }else{
            y[j] = x[j];
        }
    }
    return;
}

int main(void){
    char x[SIZE], y[SIZE];
    printf("Input: "); scanf("%s", x);

    s_convert(x, y);

    printf("x: %s\n", x);
    printf("y: %s\n", y);
    return 0;
}
