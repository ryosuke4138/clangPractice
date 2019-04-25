#include <stdio.h>
/*
   数値データの個数、総和、平均
*/
int main(void)
{
	int data=0, count=0, sum=0;
	double average = 0;

	while (scanf("%d",&data)==1) {
		sum+=data;
		count++;
	}
	average=(double)sum/count;

	if(count==0) {
		printf("No data\n");
	} else {
		printf("%d %d %.3f\n", count, sum, average);
	}
	return 0;
}
