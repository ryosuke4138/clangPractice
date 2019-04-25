#include <stdio.h>
#include <string.h>
#define SIZE 1000
#define STR_SIZE 256
/*
    辞書順でもっとも若い単語
    Youngest word in dictionary order
*/
int main(void)
{
    char str[STR_SIZE], str_youngest[STR_SIZE] = "zzz";

    while (scanf("%s", str)==1)
    {
        //replace to lowercases
        int i;
        for (i=0; i<=strlen(str); i++){
            if ('A'<=str[i] && str[i]<='Z') {
                str[i] = str[i] - ('A' - 'a');
            }
        }
        
        //compare between str & str_youngest in dictionary order
        for (i=0; i<=strlen(str_youngest); i++) {
            if (str_youngest[i] > str[i]) {
                strcpy(str_youngest, str);
                break;
            } else if (str_youngest[i] == str[i]) {
                continue;
            } else {
                break;
            }
        }
    }

    printf("%s\n", str_youngest);

    return 0;
}