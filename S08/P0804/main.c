#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  N 11

void getdigits(int *num,char *str);
void multiply(int *a,int *b,int *c);
int main(void)
{
	char str_a[N],str_b[N];
	int num_a[N],num_b[N],result[N * 2],j;
	scanf("%s",str_a);
	scanf("%s",str_b);
	getdigits(num_a,str_a);
	getdigits(num_b,str_b);
	multiply(num_a,num_b,result);
	j = N * 2 - 1;
	while (*(result + j) == 0)
	{
		j--;
	}
	for (;j >= 0;j--)
	{
		printf("%d",*(result + j));
	}
	return 0;
}

void getdigits(int *num,char *str)
{
	int i,len = strlen(str);
	for (i = 0;i < N;i++)
	{
		*(num + i) = 0;
	}
	for (i = 0;i < len;i++)
	{
		*(num+len-1-i) = *(str+i) - '0';
	}
}
void multiply(int *a,int *b,int *c)
{
	int i,j;
	for (i = 0;i < N * 2;i++)
	{
		*(c + i) = 0;
	}
	for (i = 0;i < N;i++)
		for (j = 0;j < N;j++)
		{
			*(c + i + j) += *(a + i) * *(b + j);
		}
	for (i = 0;i < N * 2-1;i++)
	{
		*(c + i +1) += *(c + i) / 10;
		*(c + i) = *(c + i) % 10;
	}
}

