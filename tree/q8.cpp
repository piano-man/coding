//diameter of a binary tree
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int diameter(struct Node * tree);

int finddiameter(struct Node *node,int &len)
{
    if(node==NULL)
    {
        return 0;
    }
    if(node->left==NULL&&node->right==NULL)
    {
        return 1;
    }
    int ls = finddiameter(node->left,len);
    int rs = finddiameter(node->right,len);
    if(ls&&rs)
    {
        int temp = ls+rs+1;
        if(temp>len)
        {
            len = temp;
        }
    }
    return max(ls+1,rs+1);
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
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
     cout << diameter(root) << endl;
  }
  return 0;
}
int diameter(Node* node)
{
    int len = INT_MIN;
   int ans = finddiameter(node,len);
   return len;
}