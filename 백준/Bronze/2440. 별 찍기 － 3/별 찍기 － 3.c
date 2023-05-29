#include <stdio.h>

int main(void)
{
	int a,i,j;

	scanf("%d",&a);

	for(i=a;i>0;i--)
	{
		for(j=1;j<=i;j++)
		{
			printf("%c",'*');
		}
	printf("\n");
	}
	return 0;
}