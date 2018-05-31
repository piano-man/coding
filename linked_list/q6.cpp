//intersection point of 2 linked lists
#include<iostream>
#include<stdio.h>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
int intersectPoint(struct Node* head1, struct Node* head2);
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
/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
int intersectPoint(Node* head1, Node* head2)
{
    int count1 = 0;
    int count2 = 0;
    struct node*p1 = head1;
    struct node*p2 = head2;
    struct node*current = head1;
    while(current!=NULL)
    {
        count1++;
        current = current->next;
    }
    current = head2;
    while(current!=NULL)
    {
        count2++;
        current = current->next;
    }
    if(count1>count2)
    {
        int diff = count1-count2;
        while(diff!=0)
        {
            p1 = p1->next;
            diff--;
        }
    }
    else if(count2 > count1)
    {
        int diff = count2 - count1;
        while(diff!=0)
        {
            p2 = p2->next;
            diff--;
        }
    }
    while(p1->next&&p2->next)
    {
        if(p1->next==p2->next)
        {
            return p1->next->data;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
}