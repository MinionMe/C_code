#include<stdio.h>
#include<string.h>

int main()
{
	char line[100];
	int i,n,number[52]={0};
	gets(line);
	n=strlen(line);
	for (i=0;i<n;i++)					
	{		
		if (line[i]<97)
		{
			number[line[i]-65]++;
		}
		else
		{
			number[line[i]-71]++;
		}		 
	}
	for (i=0;i<26;i++)					
	{
		if (number[i]%2)
		{
			printf("%c",i+65);
			return 0;
		}
	}
	for (i=26;i<52;i++)
	{
		if (number[i]%2)
		{
			printf("%c",i+71);
			return 0;
		}	
	}
}