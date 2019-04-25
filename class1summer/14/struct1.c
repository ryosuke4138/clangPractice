#include<stdio.h>

struct student{
  char name[20];
  int english, math, physics;
  double avg;
  char grade;
};

int main(void){
  struct student a = {"Alice", 82, 72, 58};
  struct student b = {"Bob"};
  b.english = 71;
  b.math = 92;
  b.physics = 98;
  
  printf("%s\n E: %d, M: %d, P: %d\n", a.name, a.english, a.math, a.physics);
  printf("%s\n E: %d, M: %d, P: %d\n", b.name, b.english, b.math, b.physics);
  return 0;
}


