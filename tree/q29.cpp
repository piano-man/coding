//array to bst
//refer to q2 in book section
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *left,*right;
};
struct node* createMinTree(vector<int> v1,int start,int end)
{
    if(end<start)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->val = v1[mid];
    newnode->left=createMinTree(v1,start,mid-1);
    newnode->right=createMinTree(v1,mid+1,end);
    return newnode;
}
void printtree(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout << root->val << "  ";
    printtree(root->left);
    printtree(root->right);
    

}
int main() {
	int t;
    cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int> v;
	    int i;
	    for(i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        v.push_back(k);
	    }
	    struct node* root = createMinTree(v,0,n-1);
	    printtree(root);
	    cout << "\n";
	}
	return 0;
}