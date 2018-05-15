//maximum path
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

int maxsumutil(struct node *root,int &res)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return root->value;
    }

    int ls=maxsumutil(root->left,res);
    int rs=maxsumutil(root->right,res);

    if(root->left&&root->right)
    {
        int temp = ls+rs+root->value;
        if(temp>res)
        {
            res = temp;
        }
        return max(ls+root->value,rs+root->value);
    }
    if(!root->left)
    {
        return rs+root->value;
    }
    if(!root->right)
    {
        return ls+root->value;
    }

    
}

int maxsumpath(struct node *root)
{
    int res = INT_MIN;
    maxsumutil(root,res);
    return res;
}

int main()
{
    struct node *root = createTree();
    //printtree();
    int ans = maxsumpath(root);
    cout << ans;
}
