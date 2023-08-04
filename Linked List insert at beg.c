#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// defining a structure with one integer and one address part that is a structure type pointer
typedef struct node
{
   int data;
   struct node *next;
} NODE;

//insert at beginning of a node
void insert_beg(NODE **p, int n)
{
	NODE *q;
	q=(NODE*)malloc(sizeof(NODE));
	q->data=n;
	q-> next = *p;
	*p=q;
}
void insert_end(NODE **p, int n)
{
	NODE *q,*r;
	q=(NODE*)malloc(sizeof(NODE));
	q->data=n;
	q-> next = NULL;
	if(*p==NULL)
	*p=q;
	else
{
	r=*p;
	while(r->next!=NULL)
	{
		r=r->next;
	}
	r->next=q;
 }
}

