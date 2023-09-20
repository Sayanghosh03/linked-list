#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct stack{
	int top;
	int arr[SIZE];
	
}Stack;
int isempty(Stack s)
{
	if(s.top == -1)
	return 1;
	else
	return 0;
}
int isfull(Stack s)
{
	return(s.top == SIZE -1);
}
void push(Stack *s,int n)
{ 
    s->top++;
	s->arr[s->top] = n;
	
}
int pop (Stack *s)
{
	return s->arr[s->top--];
}
int peek(Stack s)
{
	return s.arr[s.top];
}
void display(Stack s)
{
	int i;
	for(i = 0; i<SIZE-1;i++)
	{
		printf("%4d",s.arr[i]);
	}
}

int main()
{
	Stack st;
	st.top = -1;
	int opt,n;
	printf("IMPLEMENTATION OF STACK USING ARRAY");
	printf("====================================");
	printf("\n1.Push Element into Stack\n");
	printf("\n2.Pop Element from Stack\n");
	printf("\n3.Peek Element in Stack\n");
	printf("\n4.Display Element in Stack");
	scanf("%d",&opt);
	while (1)
	{
	switch(opt){
		case 1:
			printf("\nEnter any number");
			scanf("%d",&n);
			if(isfull(st)){
			puts("stack overflow");
			break;
		}
			else{
			push(&st,n);
			break;
		}
		case 2:
			if(isempty(st))
			puts("stack underflow");
			else
			{
				n = pop(&st);
				printf("popped item = %d",n);
			}
			break;
		case 3:
			printf("Top item is %d ",peek(st));
			break;
		case 4:
			exit (0);
	}
}
	return 0;
	
}
