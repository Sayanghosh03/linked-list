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

int main()
{
	NODE *head = NULL;
	int opt, n, pos;
	//head = (NODE *)malloc(sizeof(NODE));
	
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
		printf("\n 6. Insert at proper postion ");
		printf("\n 7. EXIT \n");
		scanf("%1d", &opt);

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
			
		case 6:
			printf("Enter Any Data You Want to Insert At Proper Position: \t");
			scanf("%d", &n);
			insert_proper(&head, n); 
			printf("Your Data Has Been Inserted Sucessfully At Its Postion: \t");
			break;
			
		case 7:
			exit(0);
			
		default:
			printf("Data Is Incorrect\n");
		}
	}
	return 0;
}
