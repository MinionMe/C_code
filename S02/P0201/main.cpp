#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	double a,b,c,max,p,h;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(abs(b-c)<a&&a<(b+c))
	{
		max=(a>b)?a:b;
		max=(max>c)?max:c;
		p=(a+b+c)/2;
		h=2*sqrt(p*(p-a)*(p-b)*(p-c))/max;
		printf("%f",h);
	}
	else
	printf("NO");
	return 0;
}




