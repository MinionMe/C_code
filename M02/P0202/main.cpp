#include<conio.h> 
#include<stdio.h> 
#include<math.h>
#include<stdlib.h>
#define NUMBER 20
#define Esc   0x1b
#define Enter 0x0d

float A[NUMBER][NUMBER+1] ,ark;
int flag,n;

void exchange(int r,int k);
float max(int k);
void message();

int main()
{
	float x[NUMBER];     
	int k,i,j;
	char celect;

	system("cls");

	printf("\n��Gauss����Ԫ��Ԫ�������Է�����");
	printf("\n1.�ⷽ�����밴Enter.");
	printf("\n2.�˳���ʽ�밴Esc.");
	celect=getch();
	if(celect==Esc)
		exit(0);
	printf("\n ���뷽�����ά����n=");
	scanf("%d",&n);
	printf("\n��������ϵ������A������b:");
	for(i=1;i<=n;i++)
	{
		printf("\n������a%d1--a%d%dϵ��������b%d: \n",i,i,n,i);       
		for(j=1;j<=n+1;j++)    
			scanf("%f",&A[i][j]);
	}
	for(k=1;k<=n-1;k++)                       
	{
		ark=max(k);
		if(ark==0)                
		{
			printf("\n�˷����鲻�Ϸ�!");message();    
		}
		else if(flag!=k)
			exchange(flag,k);
		for(i=k+1;i<=n;i++)
			for(j=k+1;j<=n+1;j++)
				A[i][j]=A[i][j]-A[k][j]*A[i][k]/A[k][k];
	}
	x[n]=A[n][n+1]/A[n][n];
	for( k=n-1;k>=1;k--)
	{
		float me=0;
		for(j=k+1;j<=n;j++)
		{
			me=me+A[k][j]*x[j];
		}
		x[k]=(A[k][n+1]-me)/A[k][k];
	}
	for(i=1;i<=n;i++)
	{
		printf("\nx%d=%f",i,x[i]);
	}
	message();

	getch();
	return 1;
}

void exchange(int r,int k)        
{
	int i;
	for(i=1;i<=n+1;i++)
		A[0][i]=A[r][i];
	for(i=1;i<=n+1;i++)
		A[r][i]=A[k][i];
	for(i=1;i<=n+1;i++)
		A[k][i]=A[0][i];
}

float max(int k)          
{
	int i;
	float temp=0;
	for(i=k;i<=n;i++)
		if(fabs(A[i][k])>temp)
		{
			temp=fabs(A[i][k]);
			flag=i;
		}
		return temp;
}

void message()                                      
{
	printf("\n �������㰴 Enter ,�˳���ʽ�� Esc!");
	switch(getch())
	{
	case Enter: main();
	case Esc: exit(0);
	default:{printf("\n���Ϸ�������!");message();}
	}
}
