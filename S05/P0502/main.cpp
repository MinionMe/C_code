#include<stdio.h>
int main(void)
{
	int n,i,j,a[20],b[20],MAX=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0,j=1;i<=n-1;i++)
	{
		if(a[i]==a[i+1])
		{
			j++;
		}
		else 
		{
			j=1;
		}
		b[i]=j;
	}	
	for(i=0;i<=n-1;i++)
	{
		if(b[i]>MAX)
		{
			MAX=b[i];
			j=i;
		}	
	}
	printf("%d\n",a[j]);	
	return 0;
}
