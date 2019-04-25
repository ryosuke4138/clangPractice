
#include <stdio.h>
int main(void)
{
  int a[10];
  int *p;

  p = &a[5];
  p[9] = 100;

;
  printf("a[9]=%d\n", a[9]);

  return 0;
}
