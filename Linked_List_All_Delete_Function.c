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
	if(p==NULL)
	printf("NULL List: Display not possible:");
while (p != NULL)
{
	printf("%d ->", p->data);
	p = p->next;
}
printf(" NULL ");
}



// function for delete first node 
void delete_first(NODE **p){
NODE*r = *p;
if(*p == NULL){
	printf("NULL List: Deletation not possible...\n");
	return;
}
else {
	*p = (*p)->next;
	free(r);
	printf("First Node Deleted Sucessfully\n");
	
}
}


// function for delte last node 
void delete_last(NODE **p){
NODE *r = *p;
if(*p == NULL){
	printf("NULL List: Deletation not possible...\n");
	return;
}
if(r->next == NULL){
	*p == NULL;
	free(r);
	printf("First Node Deleted Sucessfully\n");
}
else{
	while(r->next->next != NULL){
		r = r->next;
	}
		free(r->next);
		r->next = NULL;
	printf("First Node Deleted Sucessfully\n");
}
}



// function for delete nth node
void delete_nth(NODE **p, int pos){
	int i;
	NODE *r,*q;
	r = *p;
	if(pos>count(*p)+1){
		printf("Invalid position");
		return;
	}
	else if(pos == 1){
		*p = NULL;
		free(r);
	printf("Your Data Has Been Deleted Sucessfully at position %4d\n",pos);
	}
	else{
		for(i=1;i<=pos-1;i++){
			r= r->next;
		}
			q= r->next;
			r->next = r->next->next;
			free(q);
			printf("Your Data Has Been Deleted Sucessfully at position %4d\n",pos);
		
	}	
}




//function for reverse physically
void rev_physically(NODE **p){
	NODE *prev, *cur, *nxt;
	prev = NULL;
	cur = *p;
	nxt = cur->next;
	cur->next = NULL;
	while(nxt!=NULL){
		prev = cur;
		cur = nxt;
		nxt = cur->next;
		cur->next = prev;
	}
	*p = cur;
	
}




//function for display the value in reverse
void rev_display(NODE *p){
//	int x;
	if(p!= NULL){
//		x = p->data;
		rev_display(p->next);
//		printf("%d",x);
		printf("%d",p->data);
	}
}



//function for creating a node 
void create(NODE **p)
{
NODE *cur;
//cur = (NODE *)malloc(sizeof(NODE));
cur = *p;
//*p = cur;
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
head = (NODE *)malloc(sizeof(NODE));
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
	printf("\n 2. Display the Node ");
	printf("\n 3. Delete  First Node ");
	printf("\n 4. Delete Last node ");
	printf("\n 5. Delete Nth Position of a Node ");
	printf("\n 6. EXIT \n");
	scanf("%1d", &opt);
	

	switch (opt)
	{

	case 1:
		create(&head);
		break;
	case 2:
		printf("%d",head);
//		display(head);
		break;
    case 3:
    	delete_first(&head);
    	break;
    case 4:
    	delete_last(&head);
    	break;
    case 5:
    	printf("Enter the Postion of the Node You Want to Delete\t");
    	scanf("%d",&pos);
    	delete_nth(&head,pos);
    	break;
    	case 6:
    		exit(0);
    		
    default: printf("Please Choose Correct Option\n");
}
}
return 0;
}
