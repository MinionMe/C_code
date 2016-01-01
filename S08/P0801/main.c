#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int len_a,len_b,*a,*b,i,result[20],j,temp;
	scanf("%d",&len_a);
	a=(int*)malloc(len_a * sizeof(int));
	if (a == NULL)
	{
		return 0;
	}
	for (i = 0;i < len_a;i++)
	{
		scanf("%d",a + i);
	}
	scanf("%d",&len_b);
	b=(int*)malloc(len_b * sizeof(int));
	if (b == NULL)
	{
		return 0;
	}
	for (i = 0;i < len_b;i++)
	{
		scanf("%d",b + i);
	}
	for (i = 0;i < len_a;i++)
	{
		result[i] = *(a + i);
	}
	for (j = 0;j < len_b;i++,j++)
	{
		result[i] = *(b + j);
	}
	free(a);
	free(b);
	for (j = 0;j < len_a + len_b;j++)
		for (i = len_a + len_b - 1;i > j;i--)
		{
			if (result[i] < result[i - 1])
			{
				temp = result[i];
				result[i] = result[i - 1];
				result[i - 1] = temp; 
			}
		}
	for (i = 0;i < len_a + len_b;i++)
	{
		printf("%d ",result[i]);
	}
	return 0;	
}