//balanced tree
//O(N) complexity
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    struct node *left,*right;
};

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
    cout << root->value <<"  ";
    printtree(root->left);
    printtree(root->right);    
}

int max(int l1,int l2)
{
    if(l1>l2)
    {
        return l1;
    }
    else
    {
        return l2;
    }
}

int checkHeight(struct node *root)
{
    if(root==NULL){
        return 0;
    }
    int leftheight = checkHeight(root->left);
    if(leftheight==INT_MIN){
        return INT_MIN;
    }
    int rightheight = checkHeight(root->right);
    if(rightheight==INT_MIN)
    {
        return INT_MIN;
    }
    int val = leftheight-rightheight;
    if(abs(val)>1)
    {
        return INT_MIN;
    }
    else
    {
        return max(leftheight,rightheight) + 1;
    }
}

bool getBalanced(struct node *root)
{
    return checkHeight(root) != INT_MIN;
}

int main()
{
    struct node *root = createTree();
    bool ans = getBalanced(root);
    if(ans==true)
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Unbalanced";
    }

}