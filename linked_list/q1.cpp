//find middle element in linked list
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

void push(struct node** head_ref,int value)
{
    struct node* new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next = (*head_ref);
    (*head_ref)=new_node; 

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

void printMiddle(struct node* ptr)
{
    int count = 0;
    struct node* mid = ptr;
    struct node* prevmid = ptr;
    while(ptr!=NULL)
    {
        if(count%2!=0)
        {
            prevmid = mid;
            mid = mid->next;
        }
        ptr=ptr->next;
        count++;
    }
    cout << count << "\n";
    if(count%2==0)
    {
        cout << prevmid->data;
    }
    else
    {

    
    cout << mid->data;
    }
}


int main()
{
    int length;
    cin >> length;
    int i;
    struct node* head = NULL;
    for(i=0;i<length;i++)
    {
        int n;
        cin >> n;
        push(&head,n);

    }
    printlist(head);
    printMiddle(head);

}