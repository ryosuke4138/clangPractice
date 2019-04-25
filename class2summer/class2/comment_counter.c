#include <stdio.h>
#define SIZE 1000
/*
    コメントの個数
    number of comments
*/
int count_comment(char buf[])
{
    static int flag = 0; //flag whether it is in comment
    int count = 0, i;

    //scanning buf[] to terminal character
    for (i=0; '\0'!=buf[i]; i++){
        if (flag == 0){
            if ('/' == buf[i] && '*'== buf[i+1]){
                flag = 1;
            }
        } else {
            if ('*' == buf[i] && '/' == buf[i+1]){
                flag = 0;
                count++;
            }
        }
    }
    return count;
}

int main(void)
{
    char buf[SIZE];
    int line = 0;

    while (fgets(buf, SIZE, stdin))
    {
        line += count_comment(buf);
    }
    printf("%d\n", line);

    return 0;
}