
#include    <stdio.h>
#define     N   100
int main(void)
{
    int i;
    int s;

    s = 0;
    for (i = 1; i <= N; i++)
        s += i;

    printf("s = %d\n", s);
    return 0;
}
