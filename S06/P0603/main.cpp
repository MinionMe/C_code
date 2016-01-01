#include<stdio.h>
#include<string.h>

int main()
{
	int max,min,value0,i,j,n,value1;
	char number[5],number1[5],number2[5],temp;
	gets(number);
	n=strlen(number);
	do 
	{
		strcpy(number1,number);
		strcpy(number2,number);
		value0=(number[0]-48)*1000+(number[1]-48)*100+(number[2]-48)*10+number[3]-48;
		for (i=0;i<n-1;i++)	
			for (j=n-1;j>i;j--)
			{
				if (number1[j]<number1[j-1])
				{
					temp=number1[j-1];
					number1[j-1]=number1[j];
					number1[j]=temp;
				}
				if (number2[j]>number2[j-1])
				{
					temp=number2[j-1];
					number2[j-1]=number2[j];
					number2[j]=temp;
				}
			}
		max=(number2[0]-48)*1000+(number2[1]-48)*100+(number2[2]-48)*10+number2[3]-48;
		min=(number1[0]-48)*1000+(number1[1]-48)*100+(number1[2]-48)*10+number1[3]-48;
		value1=max-min;
		i=3;
		j=value1;
		while (j>0)
		{
			number[i]=j%10+48;
			j=j/10;
			i--;
		}
	} while (value0!=value1);
	printf("%d",value0);
}