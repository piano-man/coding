//special subsequence of a string
#include<bits/stdc++.h>
using namespace std;

string converttostring(int i,string s)
{
    int l = s.length();
    int j;
    for(j=0;j<l;j++)
    {
        if((i&(1<<j))!=0)
        {
            s[j] = s[j]-'a'+'A';
        }
    }
    return s;
}

string getstring(int i,string s)
{
    int l = s.size();
    int j;
    string temp = "";
    for(j=0;j<l;j++)
    {
        if((i&(1<<j))!=0)
        {
            temp+=(s[j]);
        }
    }
    return temp;
}

set<string> strsubsets(string s)
{
    int l = s.size();
    int i;
    set<string> ans;
    int tot = pow(2,l);
    for(i=0;i<tot;i++)
    {
        string t = getstring(i,s);
        ans.insert(t);
    }
    return ans;
}

void getsubsets(string s)
{
    int i;
    string copy = s;
    int l = s.length();
    set<string> v;
    set<string> super;
    v.insert(s);
    int tot = pow(2,l);
    for(i=0;i<tot;i++)
    {
        string temp = converttostring(i,s);
        v.insert(temp);
    }
    int l1 = v.size();
    set<string>::iterator it;
    for(it=v.begin();it!=v.end();it++)
    {
        set<string> seq = strsubsets(*it);
        set<string>::iterator it2;
        for(it2 = seq.begin();it2!=seq.end();it2++)
        {
            super.insert(*it2);
        }
    }
    cout << super.size()-1 << "\n";
    for(it=super.begin();it!=super.end();it++)
    {
        if(*it!="")
        {
            cout << *it << " ";
        }

    }
}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        string s;
        cin >> s;
        getsubsets(s);
        cout << "\n";
    }
}