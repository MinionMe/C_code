#include <stdio.h>

int Times(int N);
int main(void)
{
	int N;
	scanf("%d",&N);
	printf("%d",Times(N));
	return 0;
}
int Times(int N)
{
	switch (N)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 4;
		break;
	default:
		return Times(N - 1) + Times(N - 2) + Times(N - 3);
		break;
	}
}