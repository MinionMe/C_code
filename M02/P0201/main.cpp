#include<stdio.h>
int main()
{
	int i;
	double MaxScore=0,MinScore=100,AveScore;
	double TotalScore=0,Scores[10];
	for(i=0;i<=9;i++)
	{
		scanf("%lf",&Scores[i]);
		if(Scores[i]<MinScore) MinScore=Scores[i];
		if(Scores[i]>MaxScore) MaxScore=Scores[i];
		TotalScore+=Scores[i];
	}
	AveScore=(TotalScore-MaxScore-MinScore)/8.0;
	printf("%5.2f",AveScore);
	return 0;
}
