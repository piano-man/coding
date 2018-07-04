//trie tree insert and delete
#include<bits/stdc++.h>
using namespace std;

struct trienode
{
    struct trienode *children[26];
    bool end;
};


struct trienode* getnode()
{
    struct trienode *temp = new trienode;
    temp->end=false;
    int i;
    for(i=0;i<26;i++)
    {
        temp->children[i] = NULL;
    }
    return temp;
}


void insert(struct trienode *root,string key)
{
    struct trienode *temp = root;
    int i;
    for(i=0;i<key.length();i++)
    {
        int index = key[i]-'a';
        if (!temp->children[index])
        {
            temp->children[index]=getnode();
        }
        temp=temp->children[index];
    }
    temp->end = true;
}

bool search(string key,struct trienode *root)
{
    struct trienode *temp = root;
    int n = key.length();
    int i ;
    for(i=0;i<n;i++)
    {
        int index = key[i]-'a';
        if(!temp->children[index])
        {
            return false;
        }
        temp = temp->children[index];
    }
    return (temp->end);
}

int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    struct trienode *root = getnode();
    int i;
    for(i=0;i<n;i++)
    {
        insert(root,keys[i]);
    }
    search("a",root)? cout << "Yes\n" :
                         cout << "No\n";

}