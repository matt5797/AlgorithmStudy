#include <stdio.h>

int main(void)
{
	int a,i,j;

	scanf("%d",&a);

	for(i=a;i>0;i--)
	{
		for(j=a;j>0;j--)
		{
			if(i<j)
				printf(" ");
			else
				printf("%c",'*');
		}
	printf("\n");
	}
	return 0;
}