#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

#define X 5  //�������̡�Ϊ���Է��㣬��5�����̡�8�����̵�ʱ�临�Ӷȣ�����˲��𰡡����ڴ����õ��㷨  
#define Y 5

void print_chess();  
int next(int *x,int *y,int step);  
int traverse(int x,int y,int count);  
int traverse_chess(int x,int y,int tag);  

int chess[X][Y]; //����  

int main()  
{  
	clock_t start,end; //��¼һ�³����ʱ  
	int i,j;  
	//��ʼ������  
	for(i=0;i<X;i++)  
	{  
		for(j=0;j<Y;j++)  
		{  
			chess[i][j]=0;  
		}  
	}  
	start=clock();  

	//����һ  
	chess[2][1]=1;  
	int result=traverse(2,1,2);  

	//������  
	//int result=traverse_chess(2,0,1); //Ҳ����ʹ���������  

	end=clock();  
	if(1==result)  
	{  
		printf("ok\n");  
		print_chess();  
		printf("����ʱ:%f\n",(double)(end-start)/CLOCKS_PER_SEC);  
	}  
	else  
	{  
		printf("��·��ͨ������޷�̤���������\n");  
	}  
	return 0;  
}  

/* 
�ж���һ�����λ���Ƿ���� 
��ǰ���λ��(x,y) 
step:��һ�����λ�ñ�� 
*/  
int next(int *x,int *y,int step)  
{  
	// printf("%d\n",step);  
	switch(step)  
	{  
	case 0:  
		if(*y+2<=Y-1 && *x-1>=0 && chess[*x-1][*y+2]==0)  
		{  
			*y+=2;  
			*x-=1;  
			return 1;  
		}  
		break;  
	case 1:  
		if(*y+2<=Y-1 && *x+1<=X-1 && chess[*x+1][*y+2]==0)  
		{  
			*y+=2;  
			*x+=1;  
			return 1;  
		}  
		break;  
	case 2:  
		if(*y+1<=Y-1 && *x+2<=X-1 && chess[*x+2][*y+1]==0)  
		{  
			*y+=1;  
			*x+=2;  
			return 1;  
		}  
		break;  
	case 3:  
		if(*y-1>=0 && *x+2<=X-1 && chess[*x+2][*y-1]==0)  
		{  
			*y-=1;  
			*x+=2;  
			return 1;  
		}  
		break;  
	case 4:  
		if(*y-2>=0 && *x+1<=X-1 && chess[*x+1][*y-2]==0)  
		{  
			*y-=2;  
			*x+=1;  
			return 1;  
		}  
		break;  
	case 5:  
		if(*y-2>=0 && *x-1>=0 && chess[*x-1][*y-2]==0)  
		{  
			*y-=2;  
			*x-=1;  
			return 1;  
		}  
		break;  
	case 6:  
		if(*y-1>=0 && *x-2>=0 && chess[*x-2][*y-1]==0)  
		{  
			*y-=1;  
			*x-=2;  
			return 1;  
		}  
		break;  
	case 7:  
		if(*y+1<=Y-1 && *x-2>=0 && chess[*x-2][*y+1]==0)  
		{  
			*y+=1;  
			*x-=2;  
			return 1;  
		}  
		break;  
	default:  
		break;  
	}  
	return 0;  
}  

/* 
������������-����һ 
(x,y)Ϊ����λ�� 
countΪ�������� 
*/  
int traverse(int x,int y,int count)  
{  
	int x1=x,y1=y; //�½ڵ�λ��  
	if(count>X*Y) //��ȫ�������ҿ��ã��򷵻ء�  
		return 1;  
	int flag,result,i;  
	for(i=0;i<8;i++)  
	{  
		flag=next(&x1,&y1,i); //Ѱ����һ������λ��  
		if(1==flag)  
		{  
			chess[x1][y1]=count; //���ҵ��Ľ���ʶ����,  
			result=traverse(x1,y1,count+1); //���½ڵ�Ϊ���ݣ��ٴεݹ���һ�����ý��  
			if(result) //��ǰ������ȫ������  
			{  
				return 1;  
			}  
			else //���ҵ��Ľ������һ������λ�ã����л���  
			{  
				chess[x1][y1]=0;  
				x1=x; //���λ��ҲҪ����  
				y1=y;  
			}  
		}  
	}  
	return 0;  
}  

/* 
������������-������ 
(x,y)Ϊ����λ�� 
tagΪ�������� 
*/  
int traverse_chess(int x,int y,int tag)  
{  
	int x1=x,y1=y,flag=0,count=0;  
	chess[x][y]=tag;  
	if(X*Y==tag)  
	{  
		return 1;  
	}  
	flag=next(&x1,&y1,count);  
	while(0==flag && count<=7)  
	{  
		count++;  
		flag=next(&x1,&y1,count);  
	}  
	while(flag)  
	{  
		if(traverse_chess(x1,y1,tag+1)) //���ȫ��������ϣ��򷵻ء�  
		{  
			return 1;  
		}  
		//û���ҵ���һ�����ý�㣬�����  
		x1=x;  
		y1=y;  
		count++;  
		flag=next(&x1,&y1,count);  
		while(0==flag && count<=7)  
		{  
			count++;  
			flag=next(&x1,&y1,count);  
		}  
	}  
	if(flag==0)  
	{  
		chess[x][y]=0;  
	}  
	return 0;  
}  

/* 
��ӡ���� 
*/  
void print_chess()  
{  
	int i,j;  
	for(i=0;i<X;i++)  
	{  
		for(j=0;j<Y;j++)  
		{  
			printf("%d\t",chess[i][j]);  
		}  
		printf("\n");  
	}  
} 