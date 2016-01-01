#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,k,n;
	char line[8],temp[8];
	gets(line);
	n=strlen(line);
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
		{
			if (line[i]==line[j])
			{
				printf("no");
				return 0;
			}
		}
	for (j=0,i=0;1;j++)
	{
		temp[j]=line[i];
		k=0;
		for (;k<j;k++)
		{
			if(temp[j]==temp[k])
			{
				printf("no");
				return 0;				
			}
		}
		i=(i+line[i]-48)%n;
		if (i==0)
		{
			break;
		}
	}
	if (j==n-1)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	return 0;
}