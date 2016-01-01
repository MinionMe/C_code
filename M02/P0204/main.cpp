#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

#define X 5  //定义棋盘。为测试方便，用5格棋盘。8格棋盘的时间复杂度，真的伤不起啊……期待更好的算法  
#define Y 5

void print_chess();  
int next(int *x,int *y,int step);  
int traverse(int x,int y,int count);  
int traverse_chess(int x,int y,int tag);  

int chess[X][Y]; //棋盘  

int main()  
{  
	clock_t start,end; //记录一下程序耗时  
	int i,j;  
	//初始化棋盘  
	for(i=0;i<X;i++)  
	{  
		for(j=0;j<Y;j++)  
		{  
			chess[i][j]=0;  
		}  
	}  
	start=clock();  

	//方法一  
	chess[2][1]=1;  
	int result=traverse(2,1,2);  

	//方法二  
	//int result=traverse_chess(2,0,1); //也可以使用这个方法  

	end=clock();  
	if(1==result)  
	{  
		printf("ok\n");  
		print_chess();  
		printf("共耗时:%f\n",(double)(end-start)/CLOCKS_PER_SEC);  
	}  
	else  
	{  
		printf("此路不通，马儿无法踏遍所有棋格！\n");  
	}  
	return 0;  
}  

/* 
判断下一个结点位置是否可用 
当前结点位置(x,y) 
step:下一个结点位置编号 
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
遍历整个棋盘-方法一 
(x,y)为坐标位置 
count为遍历次数 
*/  
int traverse(int x,int y,int count)  
{  
	int x1=x,y1=y; //新节点位置  
	if(count>X*Y) //已全部遍历且可用，则返回。  
		return 1;  
	int flag,result,i;  
	for(i=0;i<8;i++)  
	{  
		flag=next(&x1,&y1,i); //寻找下一个可用位置  
		if(1==flag)  
		{  
			chess[x1][y1]=count; //新找到的结点标识可用,  
			result=traverse(x1,y1,count+1); //以新节点为根据，再次递归下一个可用结点  
			if(result) //当前棋盘已全部可用  
			{  
				return 1;  
			}  
			else //新找到的结点无下一个可用位置，进行回溯  
			{  
				chess[x1][y1]=0;  
				x1=x; //结点位置也要回溯  
				y1=y;  
			}  
		}  
	}  
	return 0;  
}  

/* 
遍历整个棋盘-方法二 
(x,y)为坐标位置 
tag为遍历次数 
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
		if(traverse_chess(x1,y1,tag+1)) //如果全部遍历完毕，则返回。  
		{  
			return 1;  
		}  
		//没有找到下一个可用结点，则回溯  
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
打印棋盘 
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