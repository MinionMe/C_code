#include <stdio.h>
#include <stdlib.h>
int Trybig(int *a,int len);
int start = 0,end;
int main()
{
	int i,N,a[100],max;
	scanf("%d",&N);
	scanf("%d",a);
	for (i = 1;i < N;i++)
	{
		scanf(" %d",a + i);
	}
	max = Trybig(a,N);
	printf("%d\n",max);
	for (i = start;i <= end;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
int Trybig(int *a,int len)
{
	int Maxsum = 0,sum = 0,i;
	for (i = 0;i < len;i++)
	{
		sum += a[i];
		if (sum < 0)
		{
			sum = 0;
			start = i + 1;
		}
		else if (sum > Maxsum)
		{
			end = i;
			Maxsum = sum;
		}
	}
	return Maxsum;
}