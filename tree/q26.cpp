//tilt of binary tree
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int val;
	struct Node *left, *right;
};
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->val = data;
	temp->left = temp->right = NULL;
	return temp;
}
int tiltTree(Node* root);
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
     cout<<tiltTree(root)<<endl;
  }
  return 0;
}

void getsum(Node *root,int &sum)
{
    if(root==NULL)
    {
        return;
    }
    sum+=root->val;
    getsum(root->left,sum);
    getsum(root->right,sum);
}

void getTilt(Node *root,int &sum)
{
    if(root==NULL)
    {
        return ;
    }
    int ls=0,rs=0;
    getsum(root->left,ls);
    getsum(root->right,rs);
    int tilt = abs(ls-rs);
    sum+=tilt;
    getTilt(root->left,sum);
    getTilt(root->right,sum);
}

int tiltTree(Node* root)
{
    int tilt = 0;
    getTilt(root,tilt);
    return tilt;
}