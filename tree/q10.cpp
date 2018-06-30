//is BST
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

bool isBST(struct node *root)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return true;
    }
    if(root->left!=NULL&&root->right==NULL)
    {
        if(root->data>=root->left->data)
        {
            return true;
        }
    }
    if(root->left==NULL&&root->right!=NULL)
    {
        if(root->data>=root->right->data)
        {
            return true;
        }
    }
    if(root->data>=root->left->data&&root->data>=root->right->data&&isBST(root->left)&&isBST(root->right))
    {
        return true;
    }
    return false;
}

int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(1); 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}