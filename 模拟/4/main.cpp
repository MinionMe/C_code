#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Number
{
	int a;
	struct Number *next;
};
char result[100];
struct Number *CreatList();
void AddList(struct Number *head1,struct Number *head2);
void PrintList();
int main()
{
	Number *head1,*head2;
	head1 = CreatList();
	head2 = CreatList();
	AddList(head1,head2);
	PrintList();
	return 0;
}
struct Number *CreatList()
{
	Number *p,*q,*head;
	char str[100];
	int len,i;
	scanf("%s",str);
	len = strlen(str);
	p = q = head = NULL;
	for (i = 0;i < len;i++)
	{
		p = (Number *)malloc(sizeof(struct Number));
		p->a = str[len - i - 1] - '0';
		if (!head)
		{
			head = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
	}
	q->next = NULL;
	return head;
}
void AddList(struct Number *head1,struct Number *head2)
{
	Number *p,*q;
	int temp = 0,i = 0;
	for (p = head1,q = head2;;)
	{
		if (p != NULL && q != NULL)
		{
			p->a = p->a + q->a + temp;
			temp = p->a / 10;
			result[i++] = p->a % 10 + '0';
			p = p->next;
			q = q->next;
		}
		else if (p != NULL && q == NULL)
		{
			p->a = p->a + temp;
			temp = p->a / 10;
			result[i++] = p->a % 10 + '0';
			p = p->next;
		}
		else if (p == NULL && q != NULL)
		{
			q->a = q->a + temp;
			temp = q->a / 10;
			result[i++] = q->a % 10 + '0';
			q = q->next;
		}
		else 
		{
			result[i++] = temp + '0';
			result[i] = '\0';
			break;
		}
	}
}
void PrintList()
{
	int len,i;
	len = strlen(result);
	if (result[len - 1] == '0')
	{
		for (i = len - 2;i >= 0;i--)
		{
			printf("%d",result[i] - '0');
		}
	}
	else
	{
		for (i = len - 1;i >= 0;i--)
		{
			printf("%d",result[i] - '0');
		}
	}

}