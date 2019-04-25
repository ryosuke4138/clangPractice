#include <stdio.h>
/*
   連続して現れた数値
*/
int main(void)
{
	int data, p_data=0, max_data, count=1, max_count=1;

	scanf("%d",&p_data);
	max_data=p_data;

	while (scanf("%d",&data)==1) {
		if(p_data==data) {
			count++;
			if(max_count<=count) {
				max_count=count;
				max_data=data;
			}
		} else {
			count=1;
		}
		p_data=data;
	}

	printf("%d %d\n", max_count, max_data);
	return 0;
}
