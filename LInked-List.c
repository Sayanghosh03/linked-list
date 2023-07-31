#include <stdio.h>
#include <stdlib.h>

// defining a structure with one integer and one address part that is a structure type pointer
typedef struct node
{
   int data;
   struct node *next;
} NODE;

int main()
{
   NODE *head = NULL, *cur;
   head = (NODE *)malloc(sizeof(NODE));
   cur = head;
   while (1)
   {
      printf("Enter any data");
      scanf("%d", &cur->data);
      printf("ener");
   }

   return 0;
}
