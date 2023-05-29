#include <stdio.h>

int main(void)
{
	int a,i,j;

	scanf("%d",&a);

	for(i=0;i<a;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%c",'*');
		}
	printf("\n");
	}
	return 0;
}