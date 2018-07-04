//two mirror trees
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
/* Given two trees, return true if they are
 structurally identical */
int areMirror(Node* a, Node* b);
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
     map<int, Node*> map1, map2;
     int n,m;
     scanf("%d%d",&n,&m);
     struct Node *root1 = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (map1.find(n1) == map1.end())
        {
           parent = newNode(n1);
           map1[n1] = parent;
           if (root1 == NULL)
             root1 = parent;
        }
        else
           parent = map1[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        map1[n2]  = child;
     }
     struct Node *root2 = NULL;
     while (m--)
     {
        Node *parent;
        char lr;
        int m1, m2;
        scanf("%d %d %c", &m1, &m2, &lr);
        if (map2.find(m1) == map2.end())
        {
           parent = newNode(m1);
           map2[m1] = parent;
           if (root2 == NULL)
             root2 = parent;
        }
        else
           parent = map2[m1];
        child = newNode(m2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        map2[m2]  = child;
     }
     cout << areMirror(root1, root2) << endl;
  }
  return 0;
}

void mirror(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    Node *temp = root->left;
    root->left  = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
    return;

}

bool areEqual(Node *a,Node *b)
{
    if(a==NULL&&b==NULL)
    {
        return true;
    }
    if((a==NULL&&b!=NULL)||(a!=NULL&&b==NULL))
    {
        return false;
    }
    if(a->data!=b->data)
    {
        return false;
    }
    return areEqual(a->left,b->left)&&areEqual(a->right,b->right);
}

int areMirror(Node* a, Node* b)
{
   mirror(a);
   bool ans = areEqual(a,b);
   if(ans==true)
   {
       return 1;
   }
   return 0;
}