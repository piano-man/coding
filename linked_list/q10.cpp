//Delete nodes having greater value on right 
//can't find error
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
    cout << "executing";
    int T;
	cin>>T;
	while(T--)
	{
        cout << "here too";
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
		for(int i=0;i<K;i++){
            cout << "in here";
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
        cout << "here";
        Node *result = compute(head);
        print(result);
        cout<<endl;
    }
}
void recurse(vector<int>&v,Node *head)
{
    cout << "in here";
    if(head==NULL)
    {
        return;
    }
    int max = INT_MIN;
    Node *current;
    while(head!=NULL)
    {
        if(head->data>max)
        {
            max = head->data;
            current  = head;
        }
    }
    v.push_back(current->data);
    recurse(v,current->next);
}

Node* compute(Node *head)
{
    cout << "in here";
    vector<int> v;
    recurse(v,head);
    int l = v.size();
    int i;
    cout << v[0];
    Node *root = newNode(v[0]);
    Node *current = root;
    for(i=1;i<l;i++)
    {
        current->next = newNode(v[i]);
        current = current->next;
        cout << v[i];
    }
    current->next=NULL;
    return root;
}