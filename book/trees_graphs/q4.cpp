//first common ancestor
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
struct node
{
    int value;
    struct node *left,*right;
};

bool covers(struct node *root,int val)
{
    if(root==NULL){
        return false;
    }
    if(root->value == val)
    {
        return true;
    }
    return covers(root->left,val)||covers(root->right,val);
}

struct node* createTree()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    cout << "enter value";
    int val;
    cin >> val;
    if(val==0)
    {
        return NULL;
    }
    newnode->value = val;
    newnode->left = createTree();
    newnode->right = createTree();
    return newnode;
} 

void printtree(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout << root->value << "  ";
    printtree(root->left);
    printtree(root->right);    
}

struct node* commonancestor(struct node* root,int val1,int val2)
{
    if(!covers(root,val1)||!covers(root,val2))
    {
        return NULL;
    }
    if(root==NULL||root->value==val1||root->value==val2)
    {
        return root;
    }
    bool val1onleft = covers(root->left,val1);
    bool val2onleft = covers(root->left,val2);
    if(val1onleft!=val2onleft)
    {
        return root;
    }
    if(val1onleft==true)
    {
        return commonancestor(root->left,val1,val2);
    }
    else
    {
        return commonancestor(root->right,val1,val2);
    }
}



int main()
{
    struct node *root = createTree();
    printtree(root);
    int val1,val2;
    cin >> val1;
    cin >> val2;
    struct node *ans = commonancestor(root,val1,val2);
    cout << ans->value;
}