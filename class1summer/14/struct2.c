#include<stdio.h>

struct student{
  char name[20];
  int english, math, physics;
  double avg;
  char grade;
};

double calc_avg(int a, int b, int c){
  return (a + b + c) / 3;
}

int main(void){
  struct student a = {"Alice", 82, 72, 58};
  struct student b = {"Bob"};
  b.english = 71;
  b.math = 92;
  b.physics = 98;
  
  a.avg = calc_avg(a.english, a.math, a.physics);
  b.avg = calc_avg(b.english, b.math, b.physics);

  printf("%s\n E: %d, M: %d, P: %d\n", a.name, a.english, a.math, a.physics);
  printf(" Avg: %.2f\n", a.avg);
  printf("%s\n E: %d, M: %d, P: %d\n", b.name, b.english, b.math, b.physics);
  printf(" Avg: %.2f\n", b.avg);
  return 0;
}


