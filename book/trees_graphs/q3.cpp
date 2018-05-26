//list of depths
#include<bits/stdc++.h>
#include<iostream>


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

void leveltraversal(struct node * root,vector<vector<int> > &v,int level)
{
    if(root==NULL)
    {
        return;
    }
    int temp = root->value;
    v[level].push_back(temp);
    leveltraversal(root->left,v,level+1);
    leveltraversal(root->right,v,level+1);
    return;
}

int main()
{   
    //tree creation
    struct node *root = createTree();
    printtree(root);
    //traversal
    vector<vector<int> > v;
    int max = 1000;
    int i;
    for(i=0;i<1000;i++)
    {
        v.push_back(vector<int>());
    }
    int level = 0;
    leveltraversal(root,v,level);
    //cout << v[2].size();
    
}
