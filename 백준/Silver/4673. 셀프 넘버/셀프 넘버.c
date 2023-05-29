#include<stdio.h>

void NotSelf(int *arr,int *num)
{
	int a,i;
	for(i=0;i<10000;i++)
	{
		a = arr[i];
		if(a<10000)
			num[a] = NULL;
	}
}

void self(int *arr)
{
	int t,h,ten,one,cnt=0;

	for(t=0;t<10;t++)
	{
		for(h=0;h<10;h++)
		{
			for(ten=0;ten<10;ten++)
			{
				for(one=0;one<10;one++)
				{
					arr[cnt] = t + h + ten + one + (1000*t) + (100*h) + (10*ten) + one;
					cnt++;
				}
			}
		}
	}
}

void sort(int *arr)
{
	int i,j,temp;
	for(i=0;i<9999;i++)
	{
		for(j=i+1;j<10000;j++)
		{
			if(arr[i]<arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void SetNum(int *num)
{
	int i;
	for(i=0;i<10000;i++)
		num[i] = i;
}

void RNull(int *num)
{
	int i,cnt=0;
	
	for(i=0;i<10000;i++)
	{
		if(num[i] != NULL)
		{
			num[cnt] = num[i];
			cnt++;
		}
	}
}

int main()
{
	int i,cnt;
	int arr[10000],num[10000];

	SetNum(num);
	self(arr);
	NotSelf(arr,num);

	RNull(num);

	for(i=0;i<983;i++)
	{
		printf("%d\n",num[i]);
	}

	return 0;
}