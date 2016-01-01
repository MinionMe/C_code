#include <stdio.h>
#include <stdlib.h>

struct Student
{
	int num;
	struct Student *next;
};

struct Student *Createlist(Student *&tail);
struct Student *Mana(Student *head,Student *tail);
int main(void)
{
	struct Student *head,*tail;
	head = Createlist(tail);
	head = Mana(head,tail);
	printf("%d",head->num);
	return 0;
}
struct Student *Createlist(Student*&tail)
{
	int len,i;
	struct Student *head,*p,*q;
	p = q = head = NULL;
	scanf("%d",&len);
	for (i = 1;i <= len;i++)
	{
		p = (struct Student*)malloc(sizeof(struct Student));
		p->num = i;
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
	tail = q;
	q->next = head;
	return head;		
}
struct Student *Mana(Student *p,Student *tail)
{
	Student *q;
	int m,i;
	scanf("%d",&m);
	if (m == 1)
	{
		p = tail;
	}
	else
	{
		for (q = p;p != p->next;p = p->next)
			for (i = 1;i <= m;i++)
			{
				if (i == m)
				{
					q->next = p->next;
					free(p);
					p = q;
				}
				else
				{
					q = p;
					p = p->next;
				}
			}
	}
	return p;
}
