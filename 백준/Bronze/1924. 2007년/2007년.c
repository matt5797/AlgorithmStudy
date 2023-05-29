#include <stdio.h>

int main(void)
{
	int m,n,add=0,i;

	scanf("%d %d",&m,&n);
	
	add += n-1;

	for(i=1;i<m;i++)
	{
		if(i==2)
			add +=28;
		else if(i == 4 ||i == 6 ||i == 9 ||i == 11)
			add += 30;
		else
			add += 31;
	}

	switch(add%7)
	{
	case 0:
		printf("MON\n"); break;
	case 1:
		printf("TUE\n"); break;
	case 2:
		printf("WED\n"); break;
	case 3:
		printf("THU\n"); break;
	case 4:
		printf("FRI\n"); break;
	case 5:
		printf("SAT\n"); break;
	case 6:
		printf("SUN\n"); break;
	}

	return 0;
}