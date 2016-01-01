#include <stdio.h>
#include <stdlib.h>
void TryDo(int i,int j,int k);
int ItemFlag[5][5] = {0},flag[100] = {0};
int N,sum = 1,num = 0;
int main()
{
	int y0,x0;
	scanf("%d",&N);
	scanf("%d %d",&x0,&y0);
	ItemFlag[x0][y0] = 1;
	TryDo(1,x0,y0);
	printf("%d",num);
	return 0;
}
void TryDo(int i,int x,int y)
{
	int j,k,y0 = y,x0 = x;
	for (j = 0;j < 8;j++)
	{
		if (j == 0)
		{
			if (x + 1 >= 0 && x + 1 <= N && y - 2 >= 0 && y - 2 <= N && ItemFlag[x + 1][y - 2] == 0)
			{
				x0 = x + 1;
				y0 = y - 2;
				ItemFlag[x0][y0] = 1;
				sum++;
				flag[i] = 1;
			}
			else continue;
		}
		else if (j == 1)
		{
			if (x + 2 >= 0 && x + 2 <= N && y - 1 >= 0 && y - 1 <= N && ItemFlag[x + 2][y - 1] == 0)
			{
				x0 = x + 2;
				y0 = y - 1;
				ItemFlag[x0][y0] = 1;
				sum++;
				flag[i] = 1;
			}
			else continue;
		}
		else if (j == 2)
		{
			if (x + 2 >= 0 && x + 2 <= N && y + 1 >= 0 && y + 1 <= N && ItemFlag[x + 2][y + 1] == 0)
			{
				x0 = x + 2;
				y0 = y + 1;
				ItemFlag[x0][y0] = 1;
				sum++;
				flag[i] = 1;
			}
			else continue;
		}
		else if (j == 3)
		{
			if (x + 1 >= 0 && x + 1 <= N && y + 2 >= 0 && y + 2 <= N && ItemFlag[x + 1][y + 2] == 0)
			{
				x0 = x + 1;
				y0 = y + 2;
				ItemFlag[x0][y0] = 1;
				sum++;
				flag[i] = 1;
			}
			else continue;
		}
		else if (j == 4)
		{
			if (x - 1 >= 0 && x - 1 <= N && y + 2 >= 0 && y + 2 <= N && ItemFlag[x - 1][y + 2] == 0)
			{
				x0 = x - 1;
				y0 = y + 2;
				ItemFlag[x0][y0] = 1;
				sum++;
				flag[i] = 1;
			}
			else continue;
		}
		else if (j == 5)
		{
			if (x - 2 >= 0 && x - 2 <= N && y + 1 >= 0 && y + 1 <= N && ItemFlag[x - 2][y + 1] == 0)
			{
				x0 = x - 2;
				y0 = y + 1;
				ItemFlag[x0][y0] = 1;
				sum++;
				flag[i] = 1;
			}
			else continue;
		}
		else if (j == 6)
		{
			if (x - 2 >= 0 && x - 2 <= N && y - 1 >= 0 && y - 1 <= N && ItemFlag[x - 2][y - 1] == 0)
			{
				x0 = x - 2;
				y0 = y - 1;
				ItemFlag[x0][y0] = 1;
				sum++;
				flag[i] = 1;
			}
			else continue;
		}
		else if (j == 7)
		{
			if (x - 1 >= 0 && x - 1 <= N && y - 2 >= 0 && y - 2 <= N && ItemFlag[x - 1][y - 2] == 0)
			{
				x0 = x - 1;
				y0 = y - 2;
				ItemFlag[x0][y0] = 1;
				sum++;
				flag[i] = 1;
			}
			else continue;
		}
		if (sum == (N + 1) * (N + 1))
		{
			num++;
		}
		else
		{
			if (flag[i] == 0)
			{
				return;
			}
			else TryDo(i + 1,x0,y0);
		}
		if (flag[i] == 0)
		{
			return;
		}
		else
		{
			ItemFlag[x0][y0] = 0;
			sum--;
			flag[i] = 0;
		}
	}
}