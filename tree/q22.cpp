//boundary traversal of a binary tree
//failed attemp(wrong code).Can learn a few things from it
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

void leveltraversal(Node *root,map<int,vector<int> > &m,int level)
{
    if(root==NULL)
    {
        return;
    }
    m[level].push_back(root->data);
    leveltraversal(root->left,m,level+1);
    leveltraversal(root->right,m,level+1);
}

void printleft(Node *root,int &level)
{
    if(root==NULL)
    {
        return;
    }
    level++;
    cout << root->data << " ";
    printleft(root->left,level);
}

void goright(Node *root,int &level)
{
    if(root==NULL)
    {
        return;
    }
    level++;
    goright(root->right,level);

}

void printright(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    vector<int> v;
    while(root!=NULL)
    {
        v.push_back(root->data);
        root = root->right;
    }
    int l = v.size();
    int i;
    for(i=l-1;i>=0;i--)
    {
        cout << v[i] << " ";
    }
}

void printBoundary(Node *root)
{

    cout << root->data << " ";
    int leftlevel = 0;
    printleft(root->left,leftlevel);
     int level = 0;
     map<int,vector<int> > m;
     leveltraversal(root,m,level);
     int rightlevel = 0;
     goright(root->right,rightlevel);
          map<int,vector<int> >::iterator it;
     for(it=m.begin();it!=m.end();it++)
     {
         if(it->first>leftlevel)
         {
             if(it->first<=rightlevel&&it->second.size()>1)
             {
                cout << it->second[0] << " ";
             }
             if(it->first>rightlevel)
             {
                 cout << it->second[0] << " ";
             }

         }

     }
     map<int,vector<int> >::reverse_iterator rit;
     for(rit = m.rbegin();rit!=m.rend();rit++)
     {
         if(rit->first>rightlevel)
         {
            int l = rit->second.size();
            if(l!=1)
            {
                cout << rit->second[l-1] << " ";
            }

         }

         

     }
     printright(root->right);

}