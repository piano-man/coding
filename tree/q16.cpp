//is a subtree or not
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}

bool areidentical(struct node *root1,struct node *root2)
{
    if(root1==NULL&&root2==NULL)
    {
        return true;
    }
    if(root1==NULL||root2==NULL)
    {
        return false;
    }
    if(root1->data!=root2->data)
    {
        return false;
    }
    return areidentical(root1->left,root2->left)&&areidentical(root1->right,root2->right);
}

bool issubtree(struct node *root1,struct node *root2)
{
    if(root2==NULL)
    {
        return true;
    }
    if(root1==NULL)
    {
        return false;
    }
    if(areidentical(root1,root2))
    {
        return true;
    }
    return issubtree(root1->left,root2)||issubtree(root1->right,root2);
}

int main()
{

    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(5);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(610);
 
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);

    if(issubtree(T,S))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

}