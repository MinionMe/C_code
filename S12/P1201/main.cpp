#include <stdio.h>

int main(void)
{
	FILE *fp;
	int i,status;
	float a[100] = {0},result = 0;
	fp = fopen("D:\\S11\\P1101\\data1.in","r");
	for (i = 0;;i++)
	{
		status = fscanf(fp,"%f",&a[i]);
		if (status == EOF)
		{
			break;
		}
		result += a[i];
	}
	result /= i;
	printf("%.2f\n",result);
	return 0;
}