#include<stdio.h>
#include<string.h> 

int main(void)
{
	char left[101] = {'0'},ch[2] = {'0'},right[101] = {'0'},result[201],temp[2] = {'0'};
	int i,j,n;
	gets(result);
	ch[0] = result[0];
	n = strlen(result);
	for (i = 1;i < n;i++)
	{	
		temp[0] = result[i];
		if (temp[0] <= ch[0])
		{
			strcat(right,temp);
		}
		else
		{
			strcat(left,temp);
		}
	}
	n = strlen(right);
	for (i = 0;i < n - 1;i++)
		for (j = n - 1;j > i + 1;j--)
		{
			if (right[j] < right[j - 1])
			{
				temp[0] = right[j - 1];
				right[j - 1] = right[j];
				right[j] = temp[0];
			}
		}
		strcpy(result,left + 1);
		strcat(result,ch);
		strcat(result,right + 1);
		puts(result);
}