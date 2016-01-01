#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int K,len;
char str[100];
int Get_Val(int start,int end);
int Get_Min(int start,int K);
int main()
{
	scanf("%s",str);
	scanf("%d",&K);
	len = strlen(str);
	printf("%d",Get_Min(0,K));
	return 0;
}
int Get_Val(int start,int end)
{
	int i,sum;
	for (i = start,sum = 0;i <= end;i++)
	{
		sum = sum * 10 + str[i] - '0';
	}
	return sum;
}
int Get_Min(int start,int k)
{
	int i,sum = 0,Minsum = 99999;
	if (k == 0)
	{
		return Get_Val(start,len - 1);
	}
	for (i = 0;i < len - start - k;i++)
	{
		sum += Get_Val(start,start + i);
		sum += Get_Min(start + i + 1,k - 1);
		if (sum < Minsum)
		{
			Minsum = sum;
		}
		sum = 0;
	}
	return Minsum;
}