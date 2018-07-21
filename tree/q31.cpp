//diagonal traversal of binary tree
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
void diagonalPrint(Node *root);
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
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
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
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     diagonalPrint(root);
     cout<<endl;
  }
  }
  return 0;
}
void levelorder(Node *root,map<int,vector<int> >&m,int level)
{
    if(root)
    {
        m[level].push_back(root->data);
        levelorder(root->left,m,level+1);
        levelorder(root->right,m,level);

    }
}

void diagonalPrint(Node *root)
{
   int level = 0;
   map<int,vector<int> >m;
   levelorder(root,m,level);
   map<int,vector<int> >::iterator it;
   for(it = m.begin();it!=m.end();it++)
   {
       int l = it->second.size();
       int i;
       for(i=0;i<l;i++)
       {
           cout << it->second[i] << " ";
       }
   }
}