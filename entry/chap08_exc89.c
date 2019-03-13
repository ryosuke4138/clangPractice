/*
 * 標準入力に現れた行数をカウントするプログラムを作成せよ
 */

#include <stdio.h>

int main(void)
{
    int ch, cnt=1;
    while((ch=getchar()) != EOF)
        if(ch=='\n')cnt++;
    
    printf("改行の出現回数:%2d\n", cnt);
    
    return 0;
}
    
