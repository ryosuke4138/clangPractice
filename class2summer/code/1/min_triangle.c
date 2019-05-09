
#include <stdio.h>
#include <math.h>
/*
     面積最小の三角形
*/
float calculate_triangle(int a, int b, int c)
{
    float s=0, area=0;

    s = (a + b + c) / 2;
	area = pow(s * (s-a) * (s-b) * (s-c), 0.5);
    return area;
}

int main(void)
{
	int a, b, c, area_min_index=0;
    float area_min = 100000, area_tmp;

    int i;
	for (i=1; scanf("%d %d %d", &a, &b, &c)==3; i++)
    {
        area_tmp = calculate_triangle(a, b, c);
        if (area_min > area_tmp){
            area_min = area_tmp;
            area_min_index = i; 
        }
	}

	printf("%d", area_min_index); 
	return 0;
}
