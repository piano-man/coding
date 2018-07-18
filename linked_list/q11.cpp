//delete nodes with greater value on right
#include<bits/stdc++.h>
using namespace std;
struct Node
{
int data;
Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node *compute(Node *head);
int main()
{
    int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}
        Node *result = compute(head);
        print(result);
        cout<<endl;
    }
}

void reverse(Node **headref)
{
    Node *current = *headref;
    Node *prev = NULL;
    Node *next = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headref = prev;
    
}
void dellesser(Node *headref)
{
    Node *current = headref;
    Node *prev  = headref;
    Node *maxnode = current;
    while(current!=NULL)
    {
        Node *temp = current->next;
        if(current->data<maxnode->data)
        {
            prev->next = temp;
            free(current);
            current = prev->next;
        }
        else{
            maxnode = current;
            prev = maxnode;
            current = maxnode->next;
        }
    }
}

Node *compute(Node *head)
{
    reverse(&head);
    dellesser(head);
    reverse(&head);
    return head;
}