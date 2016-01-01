#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[100];
	int a[27],i;
	gets(str);
	for (i = 0;i < 27;i++)
	{
		*(a + i) = 0;
	}
	for (i = 0;i < strlen(str);i++)
	{
		if (*(str + i) > 96 && *(str + i) < 123)
		{
			a[*(str + i) - 96]++;
			if (a[*(str + i) - 96] == 1 || a[*(str + i) - 96] == 3 || a[*(str + i) - 96] ==6)
			{
				printf("%c",*(str + i));
			}
		}
		else printf(" ");
	}
	return 0;
}