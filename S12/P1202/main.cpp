#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp1,*fp2;
	char str1[100] = {'0'},str2[100] = {'0'},line = 1;
	fp1 = fopen("D:\\S11\\P1102\\file1.txt","r");
	fp2 = fopen("D:\\S11\\P1102\\file2.txt","r");
	while (!feof(fp1) && !feof(fp2))
	{
		fgets(str1,100,fp1);
		fgets(str2,100,fp2);
		if (strcmp(str1,str2))
		{
			printf("%d\n",line);
			return 0;
		}
		line++;
	}
	printf("same");
	return 0;
}