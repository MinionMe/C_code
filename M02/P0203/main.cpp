//quick sort
#include <stdlib.h>
#include <stdio.h>

#define N 7
void qsort (int a[], int left, int right);
int main()
{
	int a[10], i;
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);
	qsort(a, 0, N-1);
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	return 0;
}

void qsort (int a[], int left, int right)
{
	int l,r,value;
	if (left >= right)
	{
		return;
	}
	l = left;
	r = right;
	value = a[l];
	do 
	{
		while (l < r && a[r] >= value)
		{
			r--;
		}
		if (l < r)
		{
			a[l] = a[r];
			l++;
		}
		while (l < r && a[l] <= value)
		{
			l++;
		}
		if (l < r)
		{
			a[r] = a[l];
			r--;
		}
	} while (l != r);
	a[l] = value;
	qsort(a,left,l - 1);
	qsort(a,r + 1,right);
}