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

char check(double avg){
  char g;
  if(avg >= 90){
    g = 'S';
  }else if(avg >= 80){
    g = 'A';
  }else if(avg >= 70){
    g = 'B';
  }else if(avg >= 60){
    g = 'C';
  }else{
    g = 'F';
  }
  return g;
}

int main(void){
  struct student a = {"Alice", 82, 72, 58};
  struct student b = {"Bob"};
  b.english = 71;
  b.math = 92;
  b.physics = 98;
  
  a.avg = calc_avg(a.english, a.math, a.physics);
  b.avg = calc_avg(b.english, b.math, b.physics);

  a.grade = check(a.avg);
  b.grade = check(b.avg);

  printf("%s\n E: %d, M: %d, P: %d\n", a.name, a.english, a.math, a.physics);
  printf(" Avg: %.2f -> %c\n", a.avg, a.grade);
  printf("%s\n E: %d, M: %d, P: %d\n", b.name, b.english, b.math, b.physics);
  printf(" Avg: %.2f -> %c\n", b.avg, b.grade);
  return 0;
}


