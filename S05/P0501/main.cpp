#include<stdio.h>
#include<string.h>
int main(void)
{
	int i;
	char str[20],ch;
	gets(str);
	scanf("%c",&ch);
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]!=ch)
		{
			printf("%c",str[i]);
		}
	}
	return 0;
}
