/*
   標準入力からの入力を標準出力にコピーする
 */

#include <stdio.h>

int main(void)
{
    int ch;

    while(1) {
       ch = getchar();       
       putchar(ch);
    }
    return 0;
}
