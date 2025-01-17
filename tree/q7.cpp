// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
Node *newNode(int k)
{
    return new Node(k);
}
// Method that prints the bottom view.
void bottomView(Node *root);
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}

void leveltraversal(struct Node* root,map<int,int> &ans,int level)
{
    if(root==NULL)
    {
        return;
    }
    ans[level] = root->data;
    leveltraversal(root->left,ans,level-1);
    leveltraversal(root->right,ans,level+1);
    return;
}
void bottomView(Node *root)
{
   map<int,int> m;
   int level = 0;
   leveltraversal(root,m,level);
   map<int,int>::iterator it;
   for(it=m.begin();it!=m.end();it++)
   {
       cout << it->second <<" ";
   }
   cout << "\n";
}
