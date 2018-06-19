//connect nodes on the same level
#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  struct Node *nextRight;
};
void connect(struct Node *p);
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void printSpecial(Node *root)
{
   if (root == NULL)
     return;
   Node *node = root;
   while (node != NULL)
   {
      printf("%d ", node->data);
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
     connect(root);
     printSpecial(root);
     printf("");
     inorder(root);
     printf("");
  }
  return 0;
}
void connect(Node *p)
{
   queue<Node *> q;
   q.push(p);
   q.push(NULL);
   while(!q.empty())
   {
       Node *temp = q.front();
       q.pop();
       if(temp!=NULL)
       {
           temp->nextRight = q.front();
           if(temp->left)
           {
               q.push(temp->left);
           }
           if(temp->right)
           {
               q.push(temp->right);
           }
       }
       else if(!q.empty())
       {
           q.push(NULL);
       }
   }
}