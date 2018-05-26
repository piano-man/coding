//detect and remove loop in linked list
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
void push(struct node **head_ref, int new_data)
{
    struct node *new_node =
        (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int detectloop(struct node *list);
int main()
{
    int t, n, c, x, i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        struct node *head = NULL;
        struct node *temp;
        struct node *s;
        scanf("%d", &x);
        push(&head, x);
        s = head;
        for (i = 1; i < n; i++)
        {
            scanf("%d", &x);
            push(&head, x);
        }
        scanf("%d", &c);
        if (c > 0)
        {
            c = c - 1;
            temp = head;
            while (c--)
                temp = temp->next;
            s->next = temp;
        }
        int g = detectloop(head);
        if (g)
            printf("True");
        else
            printf("False");
    }
    return 0;
}

int detectloop(struct node *head)
{
    struct node *current = head;
    struct node*slow = head;
    struct node *fast = head;
    while(fast&&fast->next)
    {
        if(slow==fast)
        {
            break;
        }
        slow = current->next;
        fast = current->next->next;
    }
    if(slow==fast)
    {
        slow = head;
        while(slow->next!=fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}