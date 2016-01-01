#include<stdio.h>
#include<string.h>

int main(void)
{
	int i,j,a,number;
	char line[100],letters[50][20]={'0'};
	gets(line);
	for (i=0,number=0,a=0;i<strlen(line);i++)
	{
		if(line[i]==' ')
		{	
			for (j=a;j<=i-1;j++)
				{
					letters[number][j-a]=line[j];
				}
			number++;
			a=i+1;
		}
		if (i==strlen(line)-1)
		{
			for (j=a;j<=i;j++)
			{
				letters[number][j-a]=line[j];
			}
			number++;
		}
	}
	for (i=0;i<number;i++)
		for (j=i+1;j<number;j++)
		{
			if (number==1) break;
			else if (!(strcmp(letters[i],letters[j])))
			{
				number--;
			}
		}
	printf("%d",number);
	return 0;
}