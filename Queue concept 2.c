#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;
int isempty(Node *q)
{
    if(q == NULL)
        return 1;
    else
        return 0;
}
void enque (Node **q, int n)
{
    Node *newnode,*r;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = n;
    if(isempty(*q))
    {
        newnode->next = newnode;
        *q = newnode;
    }
    else
    {
        r = *q;
        newnode->next = r->next;
        r->next = newnode;
        *q = newnode;
    }
}
int deque (Node **q)
{
    Node *r,*temp;
    temp = (*q)->next;
    int data = (*q)->next->data;

    if((*q)->next == *q)
        *q =NULL;
    else
    {
        (*q)->next = (*q)->next->next;
    }
    free(temp);
    return(data);
}
void display(Node *q)
{
    if(isempty(q))
    {
        printf("Queue is empty...\n");
        return;
    }
    else {
        printf("Elements are:\n");
        Node* r = q->next;
        do
        {
            printf("%d\t",r->data);
            r= r->next;

        } while(r != q->next);
    }
}
int main()
{
    Node *tail = NULL;
    int opt,num;
    while(1)
    {
        printf("\n====================================\n");
        printf("Implementation of Queue:\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT");
        printf("===============================\n");
        printf("PLEASE ENTER YOUR CHOICE:\t\n");
        scanf("%d",&opt);

        switch(opt)
        {
        case 1:
            printf("Enter any number:\t");
            scanf("%d",&num);
            enque(&tail,num);
            break;
        case 2:
            if(isempty(tail))
                puts("Stack Underflow...");
            else
            {
                num = deque(&tail);
                printf("Popped item = %d",num);
            }
            break;
        case 3:
            display(tail);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}