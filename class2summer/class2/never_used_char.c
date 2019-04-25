
#include <stdio.h>
#include <math.h>
#include <string.h>
/*
    一度も使われなかった英字【必須】
    alphabets never used
*/
int main(void)
{
    char alphabet[26];
    char moji;

    //make lowercase alphabet list
    for(moji='a'; moji<='z'; ++moji)
        alphabet[moji-'a'] = moji;
    
    while(scanf("%c", &moji)==1){
        //replace uppercase to lowercase
        if ('A'<=moji && moji<='Z'){
            moji -= 'A' - 'a';
        }
        //remove used alphabets from list
        if ('a'<=moji && moji<='z'){
            alphabet[moji-'a'] = 0;
        }
    }

    //output alphabets never used
    int i;
    for(i=0; i<26; i++){
        if (alphabet[i]!=0){
            printf("%c", alphabet[i]);
        }
    }
    putchar('\n');

    return 0;
}
