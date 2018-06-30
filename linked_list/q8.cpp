//remove every kth node
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
Node *deleteK(Node *,int);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Function to get the middle of the linked list*/
int getMiddle(struct Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
    int K;
    cin>>K;
    Node *res = deleteK(head,K);
    Node *temp = res;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
cout<<endl;
    }
    return 0;
}
Node * deleteK(Node *head,int K)
{
    if(K==1)
    {
        return NULL;
    }
    int count = 1;
    Node *current = head;
  while(current!=NULL&&current->next!=NULL)
  {
      Node *prev;
      prev  = current;
      current = current->next;
      count++;
      if(count==K)
      {
          prev->next = current->next;
          current = prev->next;
          prev = prev->next;
          count = 1;
      }
  }
  return head;
}