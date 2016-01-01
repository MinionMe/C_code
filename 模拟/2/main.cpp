#include <stdio.h>
#include <math.h>
void TryDig(int *p);
int IsPrime(int n);
int main()
{
	int N,num[20] = {0},i,j = 0,dig[200] = {0};
	scanf("%d",&N);
	TryDig(dig);
	for (i = 0;N > 1;i++)
	{
		if (N % dig[i] == 0)
		{
			num[j++] = dig[i];
			N /= dig[i];
			i--;
		}
	}
	printf("1");
	for (i = 0;i < j;i++)
	{
		printf("*%d",num[i]);
	}
	return 0;
}
void TryDig(int *p)
{
	int i,num;
	for (i = 2,num = 0;num < 200;i++)
	{
		if (IsPrime(i) == 1)
		{
			*(p + num) = i;
			num++;
		}
		else continue;
	}
}
int IsPrime(int n)
{
	int i;
	for (i = 2;i <= sqrt((float)n);i++)
	{
		if (n % i == 0)
			break;
	}
	if (i > sqrt((float)n))
		return 1;
	else 
		return 0;
}