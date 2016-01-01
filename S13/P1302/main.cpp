#include <stdio.h>
void TryFish(int i);
void sort(int *a,int len);
int Fish[31],N,T;
int FishFlag[31] = {0};
int BestFishFlag[31] = {0};
int BestWeight = 0,Weight = 0,BestNum = 0,Num = 0;
int main()
{
	int k,result[31],i = 0;
	scanf("%d %d",&N,&T);
	for (k = 1;k <= N;k++)
	{
		scanf("%d",&Fish[k]);
	}
	TryFish(1);
	for (k = 1;k <= N;k++)
	{
		if (BestFishFlag[k])
		{
			result[++i] = Fish[k];
		}
	}
	sort(result,i);
	for (k = 1;k <= i;k++)
	{
		printf("%d\n",result[k]);
	}
	return 0;
}
void sort(int *a,int len)
{
	int i,j,temp;
	for (i = 1;i < len;i++)
		for (j = 1;j <= len - i;j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
}
void TryFish(int i)
{
	int j,k;
	for (j = 0;j <= 1;j++)
	{
		 if (j == 1)
		 {
			 if (Weight + Fish[i] > T)
			 {
				 continue;
			 }
			 Weight += Fish[i];
			 Num++;
			 FishFlag[i] = 1;
		 }
		 if (i == N)
		 {
			 if (Weight <= T && (Weight > BestWeight || (Weight == BestWeight && Num > BestNum)))
			 {
				 BestWeight = Weight;
				 BestNum = Num;
				 for (k = 1;k <= N;k++)
				 {
					 BestFishFlag[k] = FishFlag[k];
				 }
			 }
		 }
		 else 
		 {
			 TryFish(i + 1);
		 }
		 if (j == 1)
		 {
			 Weight -= Fish[i];
			 Num--;
			 FishFlag[i] = 0;
		 }
	}
}