//minimum depth of binary tree
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
int minDepth(Node *node);
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
/* Driver program to test size function*/
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
    cout<<minDepth(root)<<endl;
    // cout << endl;
  }
  return 0;
}

int getmin(Node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    if(node->left==NULL&&node->right==NULL)
    {
        return 1;
    }
    int lh = getmin(node->left);
    int rh = getmin(node->left);
    int minheight = min(lh,rh);
    int currheight = 1+minheight;
    return currheight;
}

int minDepth(Node *node)
{
    int ans = getmin(node);
}