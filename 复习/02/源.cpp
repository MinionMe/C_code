#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int seed,min,max,a[5] = {0},i,j,temp;
	scanf("%d",&seed);
	scanf("%d %d",&min,&max);
	srand(unsigned (seed));
	for (i = 0;i < 5;i++)
	{
		a[i] = rand() % (max - min + 1) + min;
		for (j = 0;j < i;j++)
		{
			if (a[j] == a[i])
			{
				i--;
				break;
			}
		}
	}
	for (i = 4;i > 0;i--)
		for (j = 4;j > 4 - i;j--)
		{
			if (a[j] < a[j - 1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	for (i = 0;i < 5;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}