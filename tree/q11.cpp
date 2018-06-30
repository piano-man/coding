//max diff between node and ancestor
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int maxDiff(Node *root);
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
   
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
          {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
          }
        else
        parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
         }
   cout<<maxDiff(root)<<endl;
 }
  return 0;
}

int maxdiff(Node *root,int &max)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return root->data;
    }
    int val = root->data;
    int minl = maxdiff(root->left,max);
    int minr = maxdiff(root->right,max);
    int m = min(minl,minr);
    int diff = val-m;
    if(diff>max)
    {
        max = diff;
    }
    return min(val,m);
}

int maxDiff(Node* root)
{
    int max = INT_MIN;
    int ans = maxdiff(root,max);
    return max;
}
