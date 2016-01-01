#include <stdio.h>
char num[10];
int N,K;
int get_max_val(int start,int k);
int get_max_val(int start,int k);
int main()
{
	scanf("%d %d",&N,&K);
	scanf("%s",num);
	printf("%d\n",get_max_val(0,K + 1));
	return 0;
}
int get_arr_val(int start,int end)
{
	int res = 0,i;
	for(i = start;i <= end;i++)
		res = res * 10 + num[i] - '0';
	return res;
}
int get_max_val(int start,int k)
{
	int sum,i,Maxsum = 0;
	if(k == 1) 
		return get_arr_val(start,N - 1);
	for(i = 0;i <= N - start - k;i++)
	{
		sum = get_arr_val(start, start + i);
		sum *= get_max_val(start + i + 1,k - 1);
		if(sum > Maxsum) 
			Maxsum = sum;
	}
	return Maxsum;
}