#include<stdio.h>
int main()
{
	int type;
	double salary,tax;
	scanf("%d %lf",&type,&salary);
	switch(type)
	{
		case 1:tax=(salary<=17850)?(0.15*salary):(0.15*17850+0.28*(salary-17850));break;
		case 2:tax=(salary<=23900)?(0.15*salary):(0.15*23900+0.28*(salary-23900));break;
		case 3:tax=(salary<=29750)?(0.15*salary):(0.15*29750+0.28*(salary-29750));break;
		default:tax=(salary<=14875)?(0.15*salary):(0.15*14875+0.28*(salary-14875));
	}
	printf("%f",tax);
	return 0;
}


