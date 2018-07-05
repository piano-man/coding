//phone directory using trie
#include<bits/stdc++.h>
using namespace std;

struct trienode
{
    struct trienode* children[26];
    bool end;
};

struct trienode* newnode()
{
    struct trienode *temp = new trienode;
    int i;
    for(i=0;i<26;i++)
    {
        temp->children[i] = NULL;
    }
    temp->end = false;
    return temp;
}

void insert(struct trienode *root,string s)
{
    struct trienode* temp = root;
    int l = s.length();
    int i;
    for(i=0;i<l;i++)
    {
        int index = s[i]-'a';
        if(!temp->children[index])
        {
            temp->children[index] = newnode();
        }
        temp = temp->children[index];
    }
    temp->end = true;
}

void dfs(struct trienode* root,string s1)
{

    if(root->end==true)
    {
        cout << s1 << " ";
    }
    int i;
    for(i=0;i<26;i++)
    {
        if(!root->children[i])
        {
            continue;
        }
        char present = i+'a';
        string s2(1,present);
        string s3 = s1+s2;
        struct trienode*temp = root->children[i];
        dfs(temp,s3);
    }
}

int dfsearch(struct trienode *root,string s1)
{

    int l1 = s1.length();
    int i;
    for(i=0;i<l1;i++)
    {
        int index = s1[i]-'a';
        if(!root->children[index])
        {
            return 0;
        }
        root = root->children[index];
    }
    dfs(root,s1);
    cout << "\n";
}

void search(struct trienode *root,string s1)
{
    int l = s1.length();
    int i;
    string prefix = "";
    for(i=0;i<l;i++)
    {
        prefix+=s1[i];
        int ans = dfsearch(root,prefix);
        if(ans==0)
        {
            cout << 0;
            cout << "\n";
        }
    }

}

int main() {
	int t;
	cin >> t;
	int i;
	for(i=0;i<t;i++)
	{
	    struct trienode *root = newnode();
	    int n;
	    cin >> n;
	    int j;
	    for(j=0;j<n;j++)
	    {
	        string s;
	        cin >> s;
	        insert(root,s);
	    }
	    string s1;
	    cin >> s1;
	    search(root,s1);
	}
	return 0;
}