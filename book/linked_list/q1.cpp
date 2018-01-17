//remove duplicates
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unordered_map>

using namespace std;
struct node
{
    int data;
    struct node* next;
};
void push(struct node** head_ref,int value)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = (*head_ref);
    (*head_ref)= new_node;
}
void removedup(struct node* head,int length)
{
    struct node* prev;
    unordered_map<int,int> hash;
    int i;
    for(i=0;i<length;i++)
    {
        if(hash.find(head->data)!=hash.end())
        {
            prev->next = head->next;
            head=head->next;
        }
        else
        {
            hash[head->data]=head->data;
             prev = head;
             head= head->next;
             
        }
    }
}
void printlist(struct node* ptr)
{
    while(ptr!=NULL)
    {
        cout << ptr->data;
        ptr=ptr->next;
    }
    cout << "\n";

}

int main()
{
    struct node* head = NULL;
    int length;
    cin >> length;
    int i;
    for(i=0;i<length;i++)
    {
        int n;
        cin >> n;
        push(&head,n);
    }
    cout << "original list";
    printlist(head);
    removedup(head,length);
    cout << "modified list";
    printlist(head);
}