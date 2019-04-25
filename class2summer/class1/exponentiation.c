#include <stdio.h>
#include <math.h>
/*
   x以下の全ての3のベキ乗数を昇順に列挙するプログラム
*/
int main(void)
{
	int x=0, i=0;

	scanf("%d",&x);
	while(1){
		int tmp=pow(3,i++);
		if(tmp>x) break;
		printf("%d\n", tmp);
	}

	return 0;
}
