#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	int number;
	char name[20];
	char gender[20];
	int	 grade;
	int	 order;
	struct Student *next;
};
struct Student *Createlist(int len);
struct Student *Line(Student *head,int len);
struct Student *Delete(Student *head);
void Copy_list(Student *Dst,Student *Src);
void Printlist(Student *head);
int main()
{
	int len;
	struct Student *head;
	scanf("%d",&len);
	head = Createlist(len);
	head = Line(head,len);
	head = Delete(head);
	Printlist(head);
	return 0;
}
struct Student *Createlist(int n)
{
	struct Student *p,*q,*head;
	int i;
	head = p = q = NULL;
	for (i = 0;i < n;i++)
	{
		p = (struct Student*)malloc(sizeof(struct Student));
		scanf("%d %s %s %d",&p->number,&p->name,&p->gender,&p->grade);
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
struct Student *Line(Student *head,int len)
{
	int i,j,re = 0;
	struct Student *p,temp;
	for (i = 1;i < len;i++)
	{
		p = head;
		for (j = 0;j < len - i;j++)
		{
			if (p->grade < p->next->grade)
			{
				Copy_list(&temp,p->next);
				Copy_list(p->next,p);
				Copy_list(p,&temp);
			}
			else if (p->grade == p->next->grade && p->number > p->next->number)
			{
				Copy_list(&temp,p->next);
				Copy_list(p->next,p);
				Copy_list(p,&temp);
			}
			p = p->next;
		}
	}
	p = head;
	p->order = 1;
	while (p)
	{
		if (p->next)
		{
			if (p->next->grade == p->grade)
			{
				re += 1;
				p->next->order = p->order;
			}
			else
			{
				p->next->order = p->order + 1 + re;
				re = 0;
			}
			p = p->next;
		}
		else break;
	}
	return head;
}
struct Student *Delete(Student *head)
{
	int num,i,del[100];
	char temp[20][5];
	struct Student *p,*q;
	scanf("%d",&num);
	for (i = 0;i < num;i++)
	{
		scanf("%s %d",temp + i,del + i);
	}
	for (i = 0;i < num;i++)
	{
		for (p = q = head;p;)
		{
			if (p->order != *(del + i))
			{
				q = p;
				p = p->next;
			}
			else
			{
				if (p == head)
				{
					q = head = p->next;
					free(p);
					p = head;
				}
				else
				{
					q->next = p->next;
					free(p);
					p = q->next;
				}
				continue;
			}
		}
	}
	return head;
}
void Copy_list(Student *Dst,Student *Src)
{
	strcpy(Dst->name,Src->name);
	strcpy(Dst->gender,Src->gender);
	Dst->number = Src->number;
	Dst->grade = Src->grade;
}
void Printlist(Student *head)
{
	struct Student *p;
	p = head;
	while (p)
	{
		printf("%d %s %s %d\n",p->number,p->name,p->gender,p->grade);
		p = p->next;
	}
}