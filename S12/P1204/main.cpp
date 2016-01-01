#include <stdio.h>
#include <stdlib.h>

void solve(int a[][21], int b[], int num, int m, int n);
int IsPrime(int n);

int main()
{
	int n, i;
	int a[21][21] = {0}, b[401] = {0};
	scanf("%d", &n);
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
	a[1][1] = 1;
	b[1] = 1;
	for (i = 2; i <= n * n; i++)
	{
		solve(a, b, i, 2, n);
	}
	printf("0\n");
	return 0;
}

void solve(int a[][21], int b[], int num, int m, int n)
{
	int i, j;
	if (m == n * n)
	{
		if ((IsPrime(a[m / n][n - 1] + num) == 1) && (IsPrime(a[m / n - 1][n] + num) == 1))
		{
			a[n][n] = num;
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
		}
		return;
	}
	if (m <= n)
	{
		if ((IsPrime(a[1][m - 1] + num) == 1))
		{
			a[1][m] = num;
			b[num] = 1;
			for (i = 2; i <= n * n; i++)
			{
				if (b[i] == 0)
				{
					solve(a, b, i, m + 1, n);
				}
			}
			b[num] = 0;
		}
		return;
	}
	else if (m % n == 1)
	{
		if ((IsPrime(a[m / n][1] + num) == 1))
		{
			a[m / n + 1][1] = num;
			b[num] = 1;
			for (i = 2; i <= n * n; i++)
			{
				if (b[i] == 0)
				{
					solve(a, b, i, m + 1, n);
				}
			}
			b[num] = 0;
		}
		return;
	}
	else if (m % n == 0)
	{
		if ((IsPrime(a[m / n][n - 1] + num) == 1) && (IsPrime(a[m / n - 1][n] + num) == 1))
		{
			a[m / n][n] = num;
			b[num] = 1;
			for (i = 2; i <= n * n; i++)
			{
				if (b[i] == 0)
				{
					solve(a, b, i, m + 1, n);
				}
			}
			b[num] = 0;
		}
		return;
	}
	else
	{
		if ((IsPrime(a[m / n + 1][m % n - 1] + num) == 1) && (IsPrime(a[m / n][m % n] + num) == 1))
		{
			a[m / n + 1][m % n] = num;
			b[num] = 1;
			for (i = 2; i <= n * n; i++)
			{
				if (b[i] == 0)
				{
					solve(a, b, i, m + 1, n);
				}
			}
			b[num] = 0;
		}
		return;
	}
}

int IsPrime(int n)
{
	int i;
	if(n == 2)
		return 1;
	if(n == 1 || n % 2 == 0)
		return 0;
	for(i=3;i * i <= n;i+=2)
	{
		if(n % i == 0)
			return 0;
	}
	return 1;
}
