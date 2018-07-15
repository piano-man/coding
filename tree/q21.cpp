//Count BST nodes that lie in a given range 
#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node * right, * left;
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
int getCountOfNode(Node *root, int l, int h);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        int l,r;
        cin>>l>>r;
        cout<<getCountOfNode(root,l,r)<<endl;
    }
}

int getcount(Node *root,int l,int h,int &count)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data>=l&&root->data<=h)
    {
        count++;
    }
    getcount(root->left,l,h,count);
    getcount(root->right,l,h,count);

}

int getCountOfNode(Node *root, int l, int h)
{
  int count = 0;
  getcount(root,l,h,count);
  return count;   
}