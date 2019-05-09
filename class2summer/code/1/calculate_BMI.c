#include<stdio.h>
#include<math.h>
#include<string.h> //strcpy
/*
   何人かの人について、名前・身長・体重が与えられているとき、
   その中で一番 BMI の小さい人を見つけるプログラムを作れ。
   w / h^2
*/

int main(void)
{
    char name_low_bmi[256], name[256];
    double height=0, weight=0, bmi=0, bmi_min=100000;

    while(scanf("%s %lf %lf", name, &height, &weight)==3)
    {
        bmi = weight / pow(height, 2);
        if(bmi_min>bmi){
           strcpy(name_low_bmi, name);
           bmi_min=bmi;
        }
    }

    printf("%s\n", name_low_bmi);
    return 0;
}