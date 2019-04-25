#include <stdio.h>
#include <math.h>
int main(void){
  int i;
  double r;
  for(i = 0 ; i < 90 ; i++){
    r = i / 180.0 * M_PI;
    printf("%f %f\n", sin(r), cos(r));
  }
  return 0; 
}
