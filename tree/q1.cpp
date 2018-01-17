//lowest commom ancestor
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct node
{
    int key;
    struct node *left,*right,*parent;
};

node *newnode(int k)
{
    node *temp = new node;
    temp->key = k;
    temp->left=NULL
    temp->right=NULL;
    temp->parent=NULL:
}
void lca(struct node*root,int n1,int n2)
{
    map<Node *,bool> ancestors;
    while(n1!=NULL)
    {
        
    }

}

int main()
{
    node *root = newnode(5);
    root->left=newnode(4);
    root->left->parent=root;
    root->right=newnode(6);
    root->right->parent=root;
    root->left->left=newnode(3);
    root->left->left->parent = root->left
    root->right->right=newnode(7);
    root->right->right->parent = root->right;
    root->right->right->right=newnode(8);
    root->right->right->right->parent = root->right->right;
    lca(root,7,8);
}
