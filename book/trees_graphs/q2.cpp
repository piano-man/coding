//minimal tree
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
struct node
{
    int val;
    struct node *left,*right;
};
struct node* createMinTree(vector<int> v1,int start,int end)
{
    if(end<start)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->val = v1[mid];
    newnode->left=createMinTree(v1,start,mid-1);
    newnode->right=createMinTree(v1,mid+1,end);
    return newnode;
}
void printtree(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout << root->val <<"  ";
    printtree(root->left);
    printtree(root->right);
    

}
int main()
{
    int n;
    vector<int> v;
    cin >> n;
    int i;
    for(i=0;i<n;i++)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }
    struct node *root = createMinTree(v,0,n-1);
    printtree(root);
    //cout << root->right->right->val;
    


}