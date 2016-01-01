#include <stdio.h>
#include <stdlib.h>

int Ackmann(int a, int b);
int main(void)
{
	int x,y,result;
	scanf("%d %d",&x,&y);
	result = Ackmann(x,y);
	printf("%d",result);
	return 0;
}
int Ackmann(int a, int b)
{
	if (a == 0)
		return b + 1;
	else
	{
		if (b == 0)
			return Ackmann(a - 1,1);
		else 
			return Ackmann(a - 1,Ackmann(a,b - 1));
	}
}
