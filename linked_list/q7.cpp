//add number formed by two lists 
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
 struct Node* addTwoLists (struct Node* first, struct Node* second);
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("");
}
void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {   
        temp=Node;
        Node = Node->next;
        free(temp);
    } 
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }
		 res = addTwoLists(first, second);
	    printList(res);
if(first)
freeList(first);
if(second)
freeList(second);
if(res)
freeList(res);
   }
   return 0;
}

Node*  addTwoLists(Node* first, Node* second){
  int counter = 0;
  struct Node *head = newNode(-100);
  struct Node *current = head;
  while(first||second)
  {
      int val;
      if(first&&second)
      {
          val = first->data+second->data+counter;
          counter = val/10;
          current->next = newNode(val%10);
          current = current->next;
          first = first->next;
          second = second->next;
      }
      else{
          if(first==NULL)
          {
            val = 0+second->data+counter;
            second = second->next;   
          }
          else if(second==NULL)
          {
              val = 0+first->data+counter;
              first = first->next;
          }
          current->next = newNode(val%10);
          current = current->next;
          counter = val/10;
      }
      
  }
  return head->next;
}