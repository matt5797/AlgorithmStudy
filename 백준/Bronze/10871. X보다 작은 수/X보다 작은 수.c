#include <stdio.h>
#include <stdlib.h>

#define NULL -23145

int main()
{
	int a,x,i,cnt=0;
	int *arr;
	int *arr2;

	scanf("%d %d",&a,&x);

	arr = (int*)malloc(sizeof(int)*a);
	arr2 = (int*)malloc(sizeof(int)*a);
	
	for(i=0;i<a;i++)
	{
		scanf("%d",&arr[i]);
	}

	for(i=0;i<a;i++)
	{
		if(arr[i]>x)
		{
			arr[i] = NULL;
		}
		if(arr[i]==x)
		{
			arr[i] = NULL;
		}
	}

	for(i=0;i<a;i++)
	{
		if(!(arr[i]==NULL))
		{
			arr2[cnt] = arr[i];
			cnt++;
		}
	}
	
	for(i=0;i<cnt;i++)
	{
		if(i==cnt-1)
			printf("%d",arr2[i]);
		else
			printf("%d ",arr2[i]);
	}
	
	free(arr);
	free(arr2);

	return 0;
}