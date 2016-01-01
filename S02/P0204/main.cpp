#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	while(a>=10)
	{
		b=a%10;
		a=a/10;
		printf("%d",b);
	}
	printf("%d",a);
	return 0;
}
