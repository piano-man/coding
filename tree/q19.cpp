//nodes that don't have a sibling
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
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Computes the number of nodes in a tree. */
void printSibling(Node *);
/* Driver program to test size function*/
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
   printSibling(root);
   cout<<endl;
  }
  return 0;
}

int printanswer(Node *node,int &flag,vector<int> &v)
{
   if(node==NULL)
   {
       return -1;
   }
   if((node->left==NULL&&node->right!=NULL))
   {
       flag=1;
       v.push_back(node->right->data);
       printanswer(node->right,flag,v);
   }
   else if((node->left!=NULL&&node->right==NULL))
   {
       flag=1;
       v.push_back(node->left->data);
       printanswer(node->left,flag,v);
   }
   else
   {
       printanswer(node->left,flag,v);
       printanswer(node->right,flag,v);
   }
   if(flag==0)
   {
       return -1;
   }
   return 0;
}

void printSibling(Node* node)
{
    int flag = 0;
    vector<int> v;
    int ans = printanswer(node,flag,v);
    if(ans==-1)
    {
        cout << -1;
    }
    else
    {
        sort(v.begin(),v.end());
        int l = v.size();
        int i;
        for(i=0;i<l;i++)
        {
            cout << v[i] << " ";
        }
    }

}