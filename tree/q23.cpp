//boundary traversal of a binary tree
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
    struct Node* Node = (struct Node*)
                        malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
void printBoundary(Node *root);
int height(struct Node *root)
{
    if(root==NULL)
        return 0;
    int l = 1+height(root->left);
    int r=1+height(root->right);
    if(l>r)
        return l;
    else
        return r;
}
/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    printBoundary(root);
   cout<<endl;
  }
    return 0;
}

void printleft(Node *root)
{
    if(root)
    {
        if(root->left)
        {
            cout << root->data << " ";
            printleft(root->left);
        }
        else if(root->right)
        {
            cout << root->data << " ";
            printleft(root->right);
        }
    }
}

void printleaves(Node *root)
{
    if(root)
    {
        printleaves(root->left);
        if(!root->left&&!root->right)
        {
            cout << root->data << " ";
        }
        printleaves(root->right);
    }
}

void printright(Node *root)
{
    if(root)
    {
        if(root->right)
        {
            printright(root->right);
            cout << root->data << " ";
        }
        else if(root->left)
        {
            printright(root->left);
            cout << root->data << " ";
        }
    }
}

void printBoundary(Node *root)
{
     if(root)
     {
         cout << root->data << " ";
         printleft(root->left);
         printleaves(root->left);
         printleaves(root->right);
         printright(root->right);
     }
}