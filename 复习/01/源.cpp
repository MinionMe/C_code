#include <stdio.h>
#include <math.h>

int main()
{
	float a,b,c,delta,p;
	scanf("%f %f %f",&a,&b,&c);
	delta = b * b - 4 * a * c;
	p = - b / (2 * a);
	if (delta < 0)
	{
		printf("Error");
	}
	else if (delta == 0)
	{
		printf("%.6f",p);
	}
	else
	{
		printf("%.6f\n%.6f\n",p + sqrt(delta) / (2 * a),p - sqrt(delta) / (2 * a));
	}
	return 0;
} 