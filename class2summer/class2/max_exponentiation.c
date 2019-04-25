#include <stdio.h>
#include <math.h>
/*
    n桁以内の最大の3のベキ乗数
    Maximum of 3 power multipliers within n digits
*/
int GetDigit(int num){
    int digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

int main(void) {   
    int n;
    scanf("%d", &n);
    double i = 1.0, power_tmp=0.0, power_result;
    while (1) {
        double power_tmp = pow(3.0, i++);
        if (GetDigit(power_tmp) > n) {
            break;
        }
        power_result = power_tmp;
    }
    printf("%.0f\n", power_result);

    return 0;
}