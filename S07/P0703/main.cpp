#include<stdio.h>
#include<string.h>
#include<math.h>

int palindromic(int a);
int prime(int a);
int main()
{
	int min,max,i;
	scanf("%d",&min);
	scanf("%d",&max);
	for (i=min;i<=max;i++)
	{
		if (palindromic(i)&&prime(i))
		{
			printf("%d ",i);
		}
	}
	return 0;
}

int prime(int a)
{
	int i;
	if (a==1)
	{
		return 0;
	}
	else
	{
		for (i=2;i<=(int)sqrt(double(a));i++)
		{
			if (!(a%i))
			{
				return 0;
				break;
			}
		}
		if (i>(int)sqrt(double(a)))
		{
			return 1;
		}
	}
}
int palindromic(int a)
{
	int len,i=0,temp[30];
	while (a>0)
	{
		temp[i]=a%10;
		a=a/10;
		i++;
	}
	len=i;
	for (i=0;i<len/2;i++)
	{
		if (temp[i]!=temp[len-i-1])
		{
			return 0;
			break;
		}
	}
	if (i==len/2)
	{
		return 1;
	}
}
