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
	if (p == NULL)
		printf("NULL List: ...\n");
	else
	{
		while (p != NULL)
		{
			printf("%d ->", p->data);
			p = p->next;
		}
		printf(" NULL ");
	}
}


// insert at beginning of a node
void insert_beg(NODE **p, int n)
{
	NODE *q;
	q = (NODE *)malloc(sizeof(NODE));
	q->data = n;
	q->next = *p;
	*p = q;
	printf("Your Data Has Been Inserted Sucessfully At The Beginning...\n");
}

// insert at end of a node
void insert_end(NODE **p, int n)
{
	NODE *q, *r;
	q = (NODE *)malloc(sizeof(NODE));
	q->data = n;
	q->next = NULL;
	if (*p == NULL){
		*p = q;
		printf("Your Data Has Been Inserted Sucessfully At The END...\n");
	}
	else
	{
		r = *p;
		while (r->next != NULL)
		{
			r = r->next;
		}
		r->next = q;
		printf("Your Data Has Been Inserted Sucessfully At The END...\n");
	}
}

// function to insert at nth position
void insert_nth(NODE **p, int n, int pos)
{
	NODE *q, *r;
	int i;
	if (pos > (count(*p) + 1))
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
		printf("Your Data Has Been Inserted Sucessfully At Position%4d\n", pos);
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
		printf("Your Data Has Been Inserted Sucessfully At Position%4d\n", pos);
	}
}


/*
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
} */


// function for display the value in reverse
void rev_display(NODE *p)
{
	int x;
	if (p != NULL)
	{
		x = p->data;
		rev_display(p->next);
		printf("%d",x);
	}
}

// function for delete first node
void delete_first(NODE **p)
{
	NODE *r = *p;
	if (*p == NULL)
	{
		printf("NULL List: Deletation not possible...\n");
		return;
	}
	else
	{
		*p = (*p)->next;
		free(r);
		printf("First Node Deleted Sucessfully\n");
	}
}

// function for delte last node
void delete_last(NODE **p)
{
	NODE *r = *p;
	if (*p == NULL)
	{
		printf("NULL List: Deletation not possible...\n");
		return;
	}
	if (r->next == NULL)
	{
		*p == NULL;
		free(r);
		printf("Last Node Deleted Sucessfully\n");
	}
	else
	{
		while (r->next->next != NULL)
		{
			r = r->next;
		}
		free(r->next);
		r->next = NULL;
		printf("Last Node Deleted Sucessfully\n");
	}
}

// function for delete nth node
void delete_nth(NODE **p, int pos)
{
	int i;
	NODE *r, *q;
	r = *p;
	if (pos > count(*p) + 1)
	{
		printf("Invalid position");
		return;
	}
	else if (pos == 1)
	{
		*p = NULL;
		free(r);
		printf("Your Data Has Been Deleted Sucessfully at position %4d\n", pos);
	}
	else
	{
		for (i = 0; i < pos - 2; i++)
		{
			r = r->next;
		}
		q = r->next;
		r->next = r->next->next;
		free(q);
		printf("Your Data Has Been Deleted Sucessfully at position %4d\n", pos);
	}
}


// function for creating a node
void create(NODE **p)
{
	NODE *cur;
    cur = (NODE *)malloc(sizeof(NODE));
    *p = cur;
	char ch;
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
}



int main()
{
	NODE *head = NULL;
	int opt, n, pos;
	printf("====================================");
	printf("\nImplementation of Single Linked List\n");
	printf("====================================\n");
	printf("\n..........Processing ..........\n");
	while (1)
	{
		printf("\n============================");
		printf("\nChoose a option from below");
		printf("\n============================");
		printf("\n 1. Create Single Linked list");
		printf("\n 2. Display the node ");
		printf("\n 3. Insert at Beginning of the node ");
		printf("\n 4. Insert at End of the node ");
		printf("\n 5. Insert at nth position ");
//		printf("\n 6. Insert at proper postion ");
        printf("\n 6. Display the value in reverse ");
        printf("\n 7. Delete first Node ");
        printf("\n 8. Delete last Node ");
        printf("\n 9. Delete Nth Node ");
		printf("\n 10. EXIT \n");
		scanf("%d",&opt);

		switch (opt)
		{

		case 1:
			create(&head);
			break;
		case 2:
			display(head);
			break;

		case 3:
			printf("Enter The Data You Want To Insert:\t");
			scanf("%d", &n);
			insert_beg(&head, n);
			break;

		case 4:
			printf("Enter The Data You Want To Insert At END:\t");
			scanf("%d", &n);
			insert_end(&head, n);
			break;

		case 5:
			printf("Enter The Data You Want to Insert: \t");
			scanf("%d", &n);
			printf("Enter Position You Want to Insert: \t");
			scanf("%d", &pos);
			insert_nth(&head, n, pos);
			break;
			
		/*case 6:
			printf("Enter Any Data You Want to Insert At Proper Position: \t");
			scanf("%d", &n);
			insert_proper(&head, n); 
			printf("Your Data Has Been Inserted Sucessfully At Its Postion: \t");
			break;*/
		case 6:
			rev_display(head);
			break;
		
		case 7:
			delete_first(&head);
			break;
			
		case 8:
			delete_last(&head);
			break;
		
		case 9:
			printf("Enter Position You Want to Delete: \t");
			scanf("%d", &pos);
			delete_nth(&head,pos);
			break;
		case 10:
			printf("Exiting.....");
//			return 0;
			exit(1);
			break;
		default:
			printf("Data Is Incorrect\n");
		}
	}
	return 0;
}
