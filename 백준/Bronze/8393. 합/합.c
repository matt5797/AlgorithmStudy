#include <stdio.h>

int sum(int n)
{
	if(n == 0)
		return 0;
	return n+sum(n-1);
}

int main(void)
{
	int a;

	scanf("%d",&a);

	printf("%d\n",sum(a));

	return 0;
}