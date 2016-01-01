#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[100],exp[100];
	int num[100],i = 0,k = 0,value;
	gets(str);
	num[0] = 0;
	while (str[i] != '=')
	{
		if (str[i] != '+'&&str[i] != '-')
		{
			num[k] = num[k] * 10 + str[i] - '0';
		}
		else 
		{
			exp[k] = str[i];
			k++;
			num[k] = 0;
		}
		i++;
	}
	for (i = 0,value = num[0];i < k;i++)
	{
		if (exp[i] == '+')
		{
			value += num[i+1];
		}
		if (exp[i] == '-')
		{
			value -= num[i+1];
		}
	}
	printf("%d",value);
	return 0;
}