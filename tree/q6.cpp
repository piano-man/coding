//maximum path sum(any node to any node)
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

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

int maxsumutil(struct node *root,int &res)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return root->value;
    }

    int ls = maxsumutil(root->left,res);
    int rs = maxsumutil(root->right,res);

    int temp = ls+rs+root->value;

    int lfs,rfs;
    lfs = (ls+root->value<ls)?ls:ls+root->value;
    rfs = (rs+root->value<rs)?rs:rs+root->value;

    int a1 = max(res,lfs);
    int a2 = max(a1,rfs);
    res = max(a2,ls+rs+root->value);
    return max(rs+root->value,ls+root->value);
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
    int ans = maxsumpath(root);
    cout << ans;
}