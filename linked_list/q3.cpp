//reverse linked list in groups of given size(3)
//error
#include<stdio.h>
#include<stdlib.h>
/* Link list node */
struct node
{
    int data;
    struct node* next;
}*head;
struct node *reverse (struct node *head, int k);
/* Reverses the linked list in groups of size k and returns the
   pointer to the new head node. */
/* UTILITY FUNCTIONS */
/* Function to push a node */
  void insert()
{
    int n,value,i;
    printf("here");
    scanf("%d",&n);
    struct node *temp;
    for(i=0;i<n;i++)
    {
        printf("enter value");
        scanf("%d",&value);
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
printf(" ");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,value,n;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     printList(head);
     printf("enter k");
     scanf("%d",&k);
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}

struct node *reverse (struct node *head, int k)
{ 
    struct node *current = head;
    struct node *prev;
    int count = 0;
  while(current->next->next!=NULL&&current!=NULL&&current->next!=NULL)
  {
      if(count==0)
      {
        struct node *left = current;
        struct node *middle = current->next;
        struct node *right = current->next->next;
        left->next = right->next;
        right->next = middle;
        middle->next = left;
        current = left->next;
        prev = left;
        head = right;
        count++;

      }
      else{
        struct node*left = current;
        struct node*middle = current->next;
        struct node *right = current->next->next;
        left->next = right->next;
        right->next = middle;
        middle->next = left;
        current = left->next;
        prev->next = right;
        prev = left;
      }

  }
  if(current->next->next==NULL&&current!=NULL&&current->next!=NULL)
    {
    struct node *left = current;
    struct node*right=current->next;
    prev->next = right;
    right->next = left;
    left->next = NULL;
  }

  return head;
}