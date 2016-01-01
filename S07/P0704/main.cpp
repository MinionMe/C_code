#include<stdio.h>

void inter(int a[],int b[],int result[],int num_a,int num_b);
void sum(int a[],int b[],int result[],int num_a,int num_b);
void oth(int a[],int b[],int result[],int num_a,int num_b);
int main()
{
	int a[30],b[30],num_a,num_b,i,c[30];	
	scanf("%d",&num_a);
	for (i=0;i<num_a;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&num_b);
	for (i=0;i<num_b;i++)
	{
		scanf("%d",&b[i]);
	}
	inter(a,b,c,num_a,num_b);
	for (i=0;;i++)
	{
		if (c[i]!=0)
		{
			printf("%d ",c[i]);
		}
		else break;
	}
	printf("\n");
	sum(a,b,c,num_a,num_b);
	for (i=0;;i++)
	{
		if (c[i]!=0)
		{
			printf("%d ",c[i]);
		}
		else break;
	}
	printf("\n");
	oth(a,b,c,num_a,num_b);
	for (i=0;;i++)
	{
		if (c[i]!=0)
		{
			printf("%d ",c[i]);
		}
		else break;
	}
	printf("\n");
	return 0;
}

void inter(int a[],int b[],int result[],int num_a,int num_b)
{	
	int i,j,k=0;
	for (i=0;i<num_a;i++)
		for (j=0;j<num_b;j++)
		{
			if (a[i]==b[j])
			{
				result[k]=a[i];
				k++;
				break;
			}
		}
	result[k]=0;
}
void sum(int a[],int b[],int result[],int num_a,int num_b)
{
	int i,j,k,d[30],temp;
	for (i=0;i<num_a;i++)
		for(j=0;;j++)
		{	
			if (result[j]==0)
			{
				d[i]=1;
				break;
			}
			else if(a[i]==result[j])
			{
				d[i]=0;
				break;
			}
		}
	for (i=0;i<num_b;i++)
	{
		result[i]=b[i];
	}
	for (i=0,k=num_b;i<num_a;i++)
	{
		if (d[i]==1)
		{
			result[k]=a[i];
			k++;
		}
	}
	for(i=0;i<k-1;i++)
		for (j=k-1;j>i;j--)
		{
			if (result[j]<result[j-1])
			{
				temp=result[j];
				result[j]=result[j-1];
				result[j-1]=temp;
			}
		}
	result[k]=0;
}
void oth(int a[],int b[],int result[],int num_a,int num_b)
{
	int i,j,d[30];
	inter( a,b,result,num_a,num_b);
	for (i=0;i<num_a;i++)
		for(j=0;;j++)
		{	
			if (result[j]==0)
			{
				d[i]=1;
				break;
			}
			else if(a[i]==result[j])
			{
				d[i]=0;
				break;
			}
		}
	for (i=0,j=0;i<num_a;i++)
	{
		if (d[i]==1)
		{
			result[j]=a[i];
			j++;
		}
	}
	result[j]=0;
}


