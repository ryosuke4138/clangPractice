#include <stdio.h>

int fact(int n);
// int fact2(int n);
int main(void)
{
	int n, f;
	scanf("%d", &n);
	f=fact(n);
	printf("%d!= %d\n", n, f);
	return 0;
}

int fact(int n)
{
	int m;

	if(n==0) return 0;
	m = fact(n-1);
	return n*m;
}

/*
int fact2(int n)
{
	int fact = 1;
	int i;

	for(i=1;i<=n;i++){
		fact *=i;
	}
	return(fact);
}
*/
