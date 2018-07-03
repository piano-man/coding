//duplicate subtree in binary tree{
#include <bits/stdc++.h>
using namespace std;
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};
struct Node* insert(struct Node* root,char data)
{
    if(root==NULL){
    root= new struct Node;
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
    }
    else if(root->data<data)
    root->right=insert(root->right,data);
    else if(root->data>data)
    root->left=insert(root->left,data);
  return root;
}
struct Node* insertString(struct Node* root,string s, int *j)
{
    if((*j)>=s.length())
    return NULL;
	          if(s[*j]=='(')
	          (*j)++;
	         if(s[*j]!='('&&s[*j]!=')'){
	             
	             char n=0;
	             n = s[*j];
             (*j)++;
	          root=insert(root,n);
	          if(s[*j]==')'){
                root->left=NULL;
              root->right=NULL;
              return root;
	          }
	         }
             if(s[*j]=='(')
	          (*j)++;
	          if(s[*j]==')'){
	          root->left=NULL;
	          }
              else{
	          root->left=insertString(root->left,s,j);
              }
              while(s[*j]==')')
	          (*j)++;
	          if(s[*j]=='(')
	          (*j)++;
	          if(s[*j]==')'){
	          root->right=NULL;
	          (*j)++;
	          }
	          else{

              root->right=insertString(root->right,s,j);
	          }
return root;
}
void print(struct Node* root)
{
    if(root==NULL)
        return;
    print (root->left);
    cout<<root->data<<endl;
    print(root->right);
}
bool dupSub(Node *root);

string dupsubutil(Node *root,unordered_set<string>&subtrees)
{
	string s = "";
	if(root==NULL)
	{
		return s+'$';
	}
	string lsbtr = dupsubutil(root->left,subtrees);
	if(lsbtr.compare("")==0)
	{
		return s;
	}
	string rsbtr = dupsubutil(root->right,subtrees);
	if(rsbtr.compare("")==0)
	{
		return s;
	}

	s = s+root->data+lsbtr+rsbtr;
	if(s.length()>3&&subtrees.find(s)!=subtrees.end())
	{
		return "";
	}
	subtrees.insert(s);
	return s;

}

int main() {
	//code
	int i,j,k,T ,level;
	char s[500];
	   cin>>T;
	   for(i=0;i<T;i++)
	   {
	     // cin>>level;
	      cin>>s;
	      int j=0;
	      struct Node* root=NULL;
	      root=insertString(root,s,&j);
	   
        cout<<dupSub(root)<<endl;
	  
	   }
	return 0;
}



bool dupSub(Node *root)
{
     unordered_set<string> subtrees;
	 string ans = dupsubutil(root,subtrees);
	 if(ans.compare("")==0)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }


}