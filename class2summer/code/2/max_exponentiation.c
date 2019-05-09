#include <stdio.h>
#include <math.h>
#include <string.h>
#define SIZE 256
/*
    n桁以内の最大の3のベキ乗数
    Maximum of 3 power multipliers within n digits
    配列を使うことで巨大な数字の計算に対応させる
*/

/*--- 配列(整数値)a[]を2乗して,配列dに下位桁から格納 ---*/
/*--- parameter nは配列aの桁数 ---*/
//void ary_power3(int a[], int n, int d[]) {
    //int i, tmp, digits=0;

    //for (i = 0; i < n; i++) {
        //if (a[i] == 0) {
            //d[digits++] += 0;
        //} else {
            //while (x) {
                //tmp = a[i] * a[i];
                //d[digits++] += x % 10;
                //x /= 10;
                //d[digits] = x % 10;
            //}
        //}
    //return digits;
//}

/*--- 配列(整数値)a[]に3をかけて,配列a_next[]に下位桁から上書き ---*/
void ary_power3(int a[]) {
    int tmp=0, tmp_prev=0, digits=0;

    int i = SIZE;
    while (i--) {
        if (0<=a[digits] || a[digits]<=9) {
            tmp = 3 * a[digits];
            a[digits++] = (tmp_prev + tmp % 10) % 10;
            tmp_prev = tmp / 10 + (tmp_prev + tmp % 10) / 10;
        }
    }
}

int get_digits(int d[]){
    int i=0; //index
    int digit=SIZE; //result

    for (i=SIZE-1; i>=0; i--) {
        //printf("d[%d]:%d\n", i, d[i]);
        if(d[i]==0){
            digit--;
        } else {
            break;
        }
    }
    return digit;
}

void print_array(int d[]) {
    int i; //index
    int flag=0;
    for (i=SIZE-1; i>=0; i--) {
        if (flag == 0 && d[i] == 0) {
            continue;
        } else flag++;

        printf("%d", d[i]);
    }
    putchar('\n');    
}

int main(void) {   
    //index, input
    int i, n;
    scanf("%d", &n);
    //Substitute 0 for all array elements except the first 3
    int d[256]={}, d_prev[256]={}; 
    d[0] = 3;
    int dno=0; /* 変換後の桁数 */

    while (1) {
        memcpy(d_prev, d, sizeof(d));
        ary_power3(d);
        dno = get_digits(d);
        if (dno > n) break; //指定した桁数を超えたらループを抜ける
    }
    print_array(d_prev);

    return 0;
}