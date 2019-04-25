
#include <stdio.h>
#include <ctype.h> // tolower(), touptter()

char
int main(void)
{
	char *inputText[256];
	scanf(%s", &inputText);



	for(){
		printf("%c", inputText);
	}
	return 0;
}

char *StrToLower(char *s)
{
    char *p;                     /* 作業用ポインタ */
                                 /* for (  )ループの初期化の式で、pは文字列の
                                    先頭アドレスを指すように初期化される */
    for (p = s; *p; p++)         /* pがヌルでなければ */
        *p = tolower(*p);        /* pの指す中身を小文字に変換 */
    return (s);                  /* 文字列の先頭アドレスを返す */
}
