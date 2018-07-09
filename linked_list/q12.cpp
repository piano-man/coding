//rotate a linked list(counter-clockwise)
//giving error on gfg
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
}*head;
void rotate(struct node **head_ref, int k);
  void insert()
{
    int n,i,value;
    struct node *temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
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
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,n,value;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     rotate(&head,k);
     printList(head);
     }
     return(0);
}
void rotate(struct node **head_ref, int k)
{ 

  struct node *lenp = *head_ref;
  int len = 0;
  while(lenp!=NULL)
  {
      lenp = lenp->next;
      len++;
  }
  if(k==len)
  {
      return;
  }
  struct node *current = *head_ref;
  struct node *old_head = *head_ref;
  struct node *temp;
  int count = 0;
  while(current!=NULL&&current->next!=NULL)
  {
     current = current->next;
     count++;
     if(count==k-1)
     {
         temp = current->next;
         current->next = NULL;
     }
  }
  *head_ref = temp;
  while(temp->next!=NULL)
  {
      temp = temp->next;
  }
  temp->next = old_head;
}
