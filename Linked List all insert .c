#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// defining a structure with one integer and one address part that is a structure type pointer
typedef struct node
{
   int data;
   struct node *next;
} NODE;


// function for displaying the node 
void display(NODE *p)
{
	while(p != NULL)
	{
		printf("%d ->", p->data);
		p = p->next;
	}
	printf (" NULL ");
}

//insert at beginning of a node
void insert_beg(NODE **p, int n)
{
	NODE *q;
	q=(NODE*)malloc(sizeof(NODE));
	q->data=n;
	q-> next = *p;
	*p=q;
}

//insert at end of a node 
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

int main()
{
	NODE *head= NULL, *cur;
	char ch;
	int opt,n;
	head = (NODE *)malloc(sizeof(NODE));
	cur = head;
	while(1)
	{
		printf("Enter any data:... ");
		scanf("%d",&cur->data);
		printf("continue?(Y/N)...");
		fflush(stdin);
		scanf("%c", &ch);
		if(toupper(ch)=='Y')
		{
			cur->next =(NODE*)malloc(sizeof(NODE));
			cur=cur->next;
		}
		else
		{
			cur->next = NULL;
			break;
		}
	}
	printf("\n..........Processing ..........\n");
	while (1)
	{
	printf("\n============================");
	printf("\nChoose a option from below");
	printf("\n============================");
	printf("\n 1. Display the node ");
	printf("\n 2. Insert at Beginning of the node ");
	printf("\n 3. Insert at End of the node ");
	printf("\n 4. EXIT \n");
	scanf("%d", &opt);
	
	switch(opt){
	
	case 1: {
		display(head);
	    break;
	}
	case 2: {
		printf ("Enter The Data You Want To Insert:\t");
		scanf("%d",&n);
		insert_beg(&head,n);
		printf("Your Data Has Been Inserted Sucessfully At The Beginning...\n");
		break;
	}
	
}
	
}
	return 1;
}




