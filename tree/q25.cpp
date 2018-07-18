//pth common ancestor in BST
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
struct NODE{
	int data;
	struct NODE *left,*right;
};
typedef struct NODE NODE;
NODE *root=NULL;
NODE* insert(int num,NODE *root);
int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec);
int main()
{
    int t,n,num,x,y,temp,p;
    scanf("%d",&t);
	while(t--){
		vector<int> vec;
	    NODE *root = NULL;
		vec.clear();
		scanf("%d %d",&n,&p);
		while(n--){
			scanf("%d",&num);
			root=insert(num,root);
		}
		scanf("%d%d",&x,&y);
		if(x>y){
			temp=x;
			x=y;
			y=temp;
		}
		printf("%d",pthCommonAncestor(x,y,root,p,vec));
	}
    return 0;
}
NODE *insert(int num,NODE *root){
	if(root==NULL){
		NODE *temp=(NODE*)malloc(sizeof(NODE));
		temp->data=num;
		temp->left=temp->right=NULL;
		return temp;
	}else if(root->data>=num)root->left=insert(num,root->left);
	else root->right=insert(num,root->right);
	return root;
}

bool covers(NODE *root,int val)
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

NODE *LCA(NODE *root,int x,int y)
{
    if(!covers(root,x)||!covers(root,y))
    {
        return NULL;
    }
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==x||root->data==y)
    {
        return root;
    }
    int xisleft = covers(root->left,x);
    int yisleft = covers(root->left,y);
    if(xisleft!=yisleft)
    {
        return root;
    }
    if(xisleft)
    {
        return LCA(root->left,x,y);
    }
    else
    {
        return LCA(root->right,x,y);
    }
}

void getdist(NODE *root,NODE *lca,int &len)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->data==lca->data)
    {
        return ;
    }
    len = len+1;
    bool isleft = covers(root->left,lca->data);
    bool isright = covers(root->right,lca->data);
    if(isleft)
    {
        getdist(root->left,lca,len);
    }
    if(isright)
    {
        getdist(root->right,lca,len);
    }
}

int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec){
     NODE *lca = LCA(root,x,y);
     if(lca==NULL)
     {
         return -1;
     }
     if(root->data==lca->data&&p==1)
     {
         return root->data;
     }
     bool isleft = covers(root->left,lca->data);
     bool isright = covers(root->right,lca->data);
     int len = 0;
     getdist(root,lca,len);
     if(len<p-1)
     {
         return -1;
     }
     if(len==p-1)
     {
         return root->data;
     }
     if(len>p-1)
     {
         if(isleft)
         {
             return pthCommonAncestor(x,y,root->left,p,vec);
         }
         if(isright)
         {
             return pthCommonAncestor(x,y,root->right,p,vec);
         }
     }

}