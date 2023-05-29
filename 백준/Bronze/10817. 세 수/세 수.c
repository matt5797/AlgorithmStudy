#include <stdio.h>

int main()
{
	int a,b,c,r;
	int arr[3];

	scanf("%d %d %d",&a,&b,&c);


	if(a>=b && a>=c && b>=c)	//abc
		r = b;
	if(a>=b && a>=c && c>=b)	//acb
		r = c;
	if(b>=a && b>=c && a>=c)	//bac
		r = a;
	if(b>=a && b>=c && c>=a)	//bca
		r = c;
	if(c>=a && c>=b && a>=b)	//cab
		r = a;
	if(c>=b && c>=a && b>=a)	//cba
		r = b;

	printf("%d\n",r);
	
	return 0;
}