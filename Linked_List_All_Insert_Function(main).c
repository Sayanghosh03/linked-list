#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// defining a structure with one integer and one address part that is a structure type pointer
typedef struct node
{
	int data;
	struct node *next;
} NODE;

// function for counting the number of node
int count(NODE *p)
{
	int c = 0;
	while (p != NULL)
	{
		c++;
		p = p->next;
	}
	return c;
}
// function for displaying the node
void display(NODE *p)
{
	while (p != NULL)
	{
		printf("%d ->", p->data);
		p = p->next;
	}
	printf(" NULL ");
}

// insert at beginning of a node
void insert_beg(NODE **p, int n)
{
	NODE *q;
	q = (NODE *)malloc(sizeof(NODE));
	q->data = n;
	q->next = *p;
	*p = q;
}

// insert at end of a node
void insert_end(NODE **p, int n)
{
	NODE *q, *r;
	q = (NODE *)malloc(sizeof(NODE));
	q->data = n;
	q->next = NULL;
	if (*p == NULL)
		*p = q;
	else
	{
		r = *p;
		while (r->next != NULL)
		{
			r = r->next;
		}
		r->next = q;
	}
}
// function to insert at nth position
void insert_nth(NODE **p, int n, int pos)
{
	NODE *q, *r;
	int i;
	if (pos > count(*p) + 1)
	{
		puts("Invalid Position");
		return;
	}
	q = (NODE *)malloc(sizeof(NODE));
	q->data = n;
	if (pos == 1)
	{
		q->next = *p;
		*p = q;
	}
	else
	{
		r = *p;
		for (i = 0; i < pos - 2; i++)
		{
			r = r->next;
		}
		q->next = r->next;
		r->next = q;
	}
}
// function for insert at proper position
void insert_proper(NODE **p, int n)
{
	NODE *q, *r, *prev;
	r = *p;
	q = (NODE *)malloc(sizeof(NODE));
	q->data = n;
	if (*p == NULL || n < r->data)
	{
		q->next = *p;
		*p = q;
	}
	else
	{
		while (r != NULL)
		{
			if (n < r->data)
				break;
			prev = r;
			r = r->next;
		}
		q->next = r;
		prev->next = q;
	}
}
int main()
{
	NODE *head = NULL, *cur;
	char ch;
	int opt, n, pos;
	cur = (NODE *)malloc(sizeof(NODE));
	head = cur;
	printf("====================================");
	printf("\nImplementation of Single Linked List\n");
	printf("====================================\n");
	while (1)
	{
		printf("Enter any data:... ");
		scanf("%d", &cur->data);
		printf("continue?(Y/N)...");
		fflush(stdin);
		scanf("%c", &ch);
		if (toupper(ch) == 'Y')
		{
			cur->next = (NODE *)malloc(sizeof(NODE));
			cur = cur->next;
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
		printf("\n 4. Insert at nth position ");
		printf("\n 5. Insert at proper postion ");
		printf("\n 6. EXIT \n");
		scanf("%d", &opt);

		switch (opt)
		{

		case 1:
			display(head);
			break;

		case 2:
			printf("Enter The Data You Want To Insert:\t");
			scanf("%d", &n);
			insert_beg(&head, n);
			printf("Your Data Has Been Inserted Sucessfully At The Beginning...\n");
			break;

		case 3:
			printf("Enter The Data You Want To Insert At END:\t");
			scanf("%d", &n);
			insert_end(&head, n);
			printf("Your Data Has Been Inserted Sucessfully At The END...\n");
			break;

		case 4:
			printf("Enter The Data You Want to Insert: \t");
			scanf("%d", &n);
			printf("Enter Position You Want to Insert: \t");
			scanf("%d", &pos);
			insert_nth(&head, n, pos);
			printf("Your Data Has Been Inserted Sucessfully At Position%4d\n", pos);
			break;
		case 5:
			printf("Enter Any Data You Want to Insert At Proper Position: \t");
			scanf("%d", &n);
			insert_proper(&head, n);
			printf("Your Data Has Been Inserted Sucessfully At Its Postion: \t");
			break;
		case 6:
			exit(0);
		default:
			printf("Data Is Incorrect\n");
		}
	}
	return 0;
}
