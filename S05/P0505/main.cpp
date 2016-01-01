#include<stdio.h>

int main(void)
{
	double x[10],temp,t,a[11][11];
	int i,j,k,n;
	int a0[10][10];
	scanf("%d", &n);	
	for (i=0;i<n;i++)                
		for (j=0;j<n;j++)
		{
			scanf("%d",&a0[i][j]);
			a[i][j]=(a0[i][j]+0.00);
		}	
	for (i=0;i<n;i++)
	{
		scanf("%lf",&a[i][n]);
	}
	for (i=0;i<n;i++)				
	{
		if (a[i][i]==0)
		{
			for (k=i+1;k<n;k++)
			{
				if (a[k][i]!=0)
				{
					for (j=0;j<=n;j++)
					{
						temp=a[i][j];
						a[i][j]=a[k][j];
						a[k][j]=temp;					
					}
					break;
				}
			}
		}
		if (k==n&&i!=n-1)
		{
			printf("Error");
			return 0;			
		}		
		 if (a[i][i]!=0)
		{
			for (k=i+1;k<n;k++)
			{
				t=a[k][i]/a[i][i];			
				for (j=i;j<=n;j++)
				{					
					a[k][j]-=a[i][j]*t;	
				}	
			}
		 }
		 k=0;
	}
	for (i=0;i<n;i++)
	{
		if (a[i][i]==0)
		{
			printf("Error");
			return 0;
		}
	}			
	if (a[n-1][n]==0)
	{
		printf("Error");
		return 0;
	}
	x[n-1]=a[n-1][n]/a[n-1][n-1];
	for (k=n-2;k>=0;k--)
	{
		x[k]=a[k][n];
		for (j=n-1;j>k;j--)
		{
			x[k]-=x[j]*a[k][j];			
		}
		x[k]=x[k]/a[k][k];
	}
	for (j=0;j<n;j++)
	{
		printf("%.2lf\n",x[j]);
	}
	return 0;	
}
