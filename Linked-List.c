#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// defining a structure with one integer and one address part that is a structure type pointer
typedef struct node
{
   int data;
   struct node *next;
} NODE;
// Displaying all nodes
void display(NODE *p)
{
   while (p != NULL)
   {
      printf("%d", p->data);
      p = p->next;
   }
   printf("NULL");
}
int main()
{
   NODE *head = NULL, *cur;
   char ch;
   head = (NODE *)malloc(sizeof(NODE));
   cur = head;
   while (1)
   {
      printf("Enter any data");
      scanf("%d", &cur->data);
      printf("Continue? (Y/N)");
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
   display(head);

   return 0;
}
