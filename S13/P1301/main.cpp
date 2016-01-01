#include <stdio.h>
void gametable();

int main()
{
	gametable();
	return 0;
}
void gametable()
{
	static short int table[5097][5096];
	int number,p,q,i,j;
	scanf("%d",&number);
	table[1][1] = 2;
	table[2][1] = 1;
	p = 1;
	q = 0;
	while (q < number)
	{
		p += p;
		q = 2 * p;
		for (i = p + 1;i <= q;i++)
			for (j = 1;j < p;j++)
				table[i][j] = table[i - p][j] + p;
		table[1][p] = p + 1;
		for (i = 2;i <= p;i++)
			table[i][p] = table[i - 1][p] + 1;
		for (j = p + 1;j < q;j++)
		{
			for (i = 1;i < p;i++)
				table[i][j] = table[i + 1][j - 1];
			table[p][j] = table[1][j - 1];
		}
		for (i = 1;i <= p;i++)
			for (j = p;j < q;j++)
				table[table[i][j]][j] = i;
	}
	for (i = 1;i <= number;i++)
	{
		for (j = 1;j < number;j++)
			printf("%d ",table[i][j]);
		printf("\n");
	}
}