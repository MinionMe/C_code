#include<stdio.h>
#include<string.h>
 
int main(void)
{
	char letter1[1000],letter2[1000],result;
	int len1,len2,i;
	gets(letter1);
	gets(letter2);
	len1 = strlen(letter1);
	len2 = strlen(letter2);
	if (len1 != len2)
	{
		for (i = 0;;i++)
		{
			if (letter1[i] != letter2[i])
			{
				result = letter1[i] - letter2[i];
				break;
			}
		}
	}
	else
	{
		for (i = 0;i < len1;i++)
		{
			if (letter1[i] != letter2[i])
			{
				result = letter1[i] - letter2[i];
				break;
			}
		}     
		if (i == len1)
		{
			result = 0;
		}
	}
	printf("%d",result);
	return 0;
}