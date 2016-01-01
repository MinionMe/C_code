#include<stdio.h>
#include<string.h>

int main(void)
{
	int i,k,j,number_a[26],number_b[26];
	char a[80],b[80];
	scanf("%s %s",a,b);
	for (k=0;k<26;k++)
	{
		j=65+k;
		number_a[k]=0;
		number_b[k]=0;
		for (i=0;i<strlen(a);i++)
		{
			if ((a[i]==j)||(a[i]==j+32))
			{
				number_a[k]++;
			}
		}
		for (i=0;i<strlen(b);i++)
		{
			if ((b[i]==j)||(b[i]==j+32))
			{
				number_b[k]++;
			}
		}		
	}
	for (i=0;i<26;i++)
	{
		if (number_a[i]!=number_b[i])
		{
			printf("no");
			break;
		}
		if (i==25)
		{
			printf("yes");
			break;
		}
	}
	return 0;	
}

