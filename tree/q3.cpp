//balanced tree
//O(NlogN) complexity
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

int getLevel(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int level = 1+ max(getLevel(root->left),getLevel(root->right));
    return level;
}

bool getBalanced(struct node *root)
{
    int l1 = getLevel(root->left);
    int l2 = getLevel(root->right);
    int ans = l2-l1;
    if(ans>1||ans<-1)
    {
        return false;
    }
    else
    {
        return getBalanced(root->left)&&getBalanced(root->right);
    }
}

int main()
{
    struct node *root = createTree();
    bool a = getBalanced(root);
    if(a==true)
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Unbalanced";
    }
}


