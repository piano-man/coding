//pairwise swap of linked list elements
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

void create(struct node** head_ref,int data,struct node** current_ref)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    //struct node* current = *current_ref;
    new_node->next=NULL;
    new_node->data=data;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        *current_ref = new_node;
    }
    else
    {
        (*current_ref)->next = new_node;
        *current_ref=new_node;
    }
}
void display(struct node* ptr)
{
    while(ptr!=NULL)
    {
        int vl = ptr->data;
        cout << vl;
        ptr=ptr->next;

    }

}

void pairWiseSwap(struct node **head)
{
    // If linked list is empty or there is only one node in list
    if (*head == NULL || (*head)->next == NULL)
        return;
 
    // Initialize previous and current pointers
    struct node *prev = *head;
    struct node *curr = (*head)->next;
 
    *head = curr;  // Change head before proceeeding
 
    // Traverse the list
    while (true)
    {
        struct node *next = curr->next;
        curr->next = prev; // Change next of current as previous node
 
        // If next NULL or next is the last node
        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }
 
        // Change next of previous to next next
        prev->next = next->next;
 
        // Update previous and curr
        prev = next;
        curr = prev->next;
    }
}

int main()
{

    struct node *head=NULL;
    struct node*current = NULL;
    int len;
    cin >> len;
    int i;
    for(i=0;i<len;i++)
    {
        int n;
        cin >> n;
        create(&head,n,&current);
    }
    display(head);
    cout << "\n";
    pairWiseSwap(&head);
    display(head);

}