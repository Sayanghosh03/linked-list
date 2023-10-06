#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct queue{
	int front, rear;
	int arr[SIZE];
}Queue;
int isempty(Queue q)
{
	if(q.front == -1 && q.rear == -1)
	return 1;
	else
	return 0;
}
int isfull(Queue q)
{
	if(q.front == 0 && q.rear == SIZE-1)
	return 1;
	else
	return 0;
}
void enque(Queue *q, int n)
{
	int i,j=0;
	if(q->rear == -1)
	q->front = q->rear = 0;
	else
	if(q->rear == SIZE-1)
	{
		for(i = q->front; i<SIZE; i++)
		q->arr[j++] = q->arr[i];
		q->front = 0;
		q->rear = j;
	}
	else
	q->rear++;
	q->arr[q->rear] = n;
	
}
int deque(Queue *q)
{
	int temp = q->arr[q->front];
	if(q->rear == q->front)
	q->front = q->rear = -1;
	else
	q->front++;
	return temp;
}
void display(Queue q)
{
	int i;
	if(isempty(q))
	{
		puts("Queue is empty");
	}
	else
	{
	for(i = q.front; i<=q.rear;i++)
		printf("%4d",q.arr[i]);
	}
}
int main()
{    
	Queue qt;
	qt.front = qt.rear = -1;
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
			  enque(&qt,num);
			  break;
			case 2:
			  if(isempty(qt))
			  puts("Queue Underflow...");
			  else
			  {
			  	num = deque(&qt);
			  	printf("Popped item = %d",num);
			  }
			  break;
			case 3:
				display(qt);
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}
