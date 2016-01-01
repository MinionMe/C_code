#include <stdio.h>
#include <math.h>

int main()
{
	long long int M,sum = 0;
	int i = 1;
	scanf("%lld",&M);
	do 
	{
		sum += pow(2.0,i);
		i++;
	} while (sum < M);
	sum -= pow(2.0,i - 1);
	printf("%d\n",i - 2);
	printf("%lld",sum);
	return 0;
}