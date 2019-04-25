
#include <stdio.h>
int main(void)
{
  int count[4][5];

  count[2][3] = 10;
  printf("count[2][3] = %d\n", count[2][3]);
  return 0;
}
