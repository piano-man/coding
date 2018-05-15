//spiral order traversal
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

int spiralassist(list<struct node*> queue,bool level)
{
    if(queue.front()==NULL&&queue.back()==NULL)
    {
        return 0;
    }
    int l = queue.size();
    vector<struct node*> v;
    int i;
    for(i=0;i<l;i++)
    {
        struct node *curr = queue.front();
        if(curr!=NULL)
        {
            cout << curr->value;
            v.push_back(curr);
        }
        queue.pop_front();
    }
    int l2 = v.size();
    if(level==false)
    {
        for(i=l2-1;i>=0;i--)
        {
            queue.push_back(v[i]->right);
            queue.push_back(v[i]->left);
        }
        level=true;
    }
    else if(level==true)
    {
        for(i=0;i<l2;i++)
        {
            queue.push_back(v[i]->left);
            queue.push_back(v[i]->right);
        }
        level = false;        
    }
    return spiralassist(queue,level);


}

void spiralorder(struct node *root)
{
    cout << root->value;
    bool level = false;
    list<struct node*> queue;
    queue.push_back(root->left);
    queue.push_back(root->right);
    spiralassist(queue,level);
}

int main()
{
    struct node *root = createTree();
    printtree(root);
    spiralorder(root);
}