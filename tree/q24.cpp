//minimum distance between two given nodes of a binary tree
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
int findDist(Node* ,int ,int );
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
     int a,b;
     cin>>a>>b;
     cout<<findDist(root,a,b)<<endl;
  }
  }
  return 0;
}
bool covers(Node *root,int val)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==val)
    {
        return true;
    }
    return covers(root->left,val)||covers(root->right,val);
}

Node * LCA(Node* root ,int n1 ,int n2 )
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==n1||root->data==n2)
    {
        return root;
    }
    if(!covers(root,n1)||!covers(root,n2))
    {
        return NULL;
    }
    bool val1left = covers(root->left,n1);
    bool val2left = covers(root->left,n2);
    if(val1left!=val2left)
    {
        return root;
    }
    if(val1left==true)
    {
        return LCA(root->left,n1,n2);
    }
    else
    {
        return LCA(root->right,n1,n2);
    }
}

void getdist(Node *root,int val,int dist,int &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==val)
    {
        ans = dist;
    }
    getdist(root->left,val,dist+1,ans);
    getdist(root->right,val,dist+1,ans);
}

int findDist(Node* root, int a, int b)
{
    Node *lca = LCA(root,a,b);
    int ans1=0,ans2=0,ans3=0;
    getdist(root,a,0,ans1);
    getdist(root,b,0,ans2);
    getdist(root,lca->data,0,ans3);
    return (ans1+ans2-(2*ans3));
}