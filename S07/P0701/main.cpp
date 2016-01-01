#include<stdio.h>
#include<string.h>

int judge(char a[]);
int main()
{
	char letters[21],suffix1[4] = "es",suffix2[4] = "ies",suffix3[4] = "s";

	gets(letters);
	switch (judge(letters))
	{
		case 1:strcat(letters,suffix1);break;
		case 2:strcpy(letters + strlen(letters) - 1,suffix2);break;
		case 3:strcat(letters,suffix3);break;
	}
	puts(letters);
	return 0;
}

int judge(char a[])
{
	int n;
	n=strlen(a)-1;
	if (n==0)
	{
		if (a[n]=='s'||a[n]=='x'||a[n]=='z')
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
	else
	{	
		if (a[n]=='s'||a[n]=='x'||a[n]=='z'||(a[n]=='h'&&(a[n-1]=='c'||a[n-1]=='s')))
		{
			return 1;
		}
		else if (a[n]=='y'&&!((a[n-1]=='a')||a[n-1]=='e'||a[n-1]=='i'||a[n-1]=='o'||a[n-1]=='u'))
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
}

