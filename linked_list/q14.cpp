// add two numbers represented as linked lists
//assuming numbers are in the same order as the linked lists
//segmentation fault somewhere
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
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
//if(res)
//freeList(res);
   }
   return 0;
}

int getsize(Node *root)
{
    int size = 0;
    while(root!=NULL)
    {
        size++;
        root = root->next;
    }
    return size;
}

Node* addsamesize(Node *first,Node *second,int &carry)
{
    if(first==NULL)
    {
        return NULL;
    }
    int sum;
    Node *result = (Node*)malloc(sizeof(Node));
    result->next = addsamesize(first->next,second->next,carry);
    sum = first->data+second->data+carry;
    carry = sum/10;
    result->data = sum%10;
    return result;

    
}

void addcarrytoremaining(Node *head,Node *first,Node **result,int &carry)
{
    if(head!=first)
    {
        int sum;
        addcarrytoremaining(head->next,first,result,carry);
        sum = head->data+carry;
        carry = sum/10;
        push(result,sum%10);
    }
}

Node*  addTwoLists(Node* first, Node* second){
  if(!first)
  {
      return second;
  }
  if(!second)
  {
      return first;
  }
  int size1 = getsize(first);
  int size2 = getsize(second);
  if(size1==size2)
  {
      int carry = 0;
      Node *result = addsamesize(first,second,carry);
  }
  else
  {
      if(size1>size2)
      {
          Node *head  = first;
          int diff = size1-size2;
          while(diff)
          {
              first = first->next;
              diff--;
          }
          int carry = 0;
          Node *result = addsamesize(first,second,carry);
          addcarrytoremaining(head,first,&result,carry);
          return result;
      }
  }
}