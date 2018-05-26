//reverse linked list in groups of given size
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head;
struct node *reverse (struct node *head, int k);
  void insert()
{
    int n,value,i;
    scanf("%d",&n);
    struct node *temp;
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
struct node *reverse (struct node *head, int k)
{ 
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;
    while(current!=NULL && count<k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(current!=NULL)
    {
        head->next = reverse(current,k);
    }
    
    return prev;
}
int main(void)
{
    int t,k,value,n;
     scanf("%d",&t);
     while(t--)
     {
     insert();
     printList(head);
     scanf("%d",&k);
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}

