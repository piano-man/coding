//transform strings
#include<bits/stdc++.h>
using namespace std;

int transform(string s1,string s2)
{
    int count1[26];
    int count2[26];
    int count = 0;
    memset(count1,0,sizeof(count1));
    memset(count2,0,sizeof(count2));
    int l1 = s1.length();
    int l2 = s2.length();
    if(l1!=l2)
    {
        return -1;
    }
    int i;
    for(i=0;i<l1;i++)
    {
        count1[s1[i]-'a']++;
        count2[s2[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(count1[i]!=count2[i])
        {
            return -1;
        }
    }
    
    return count;
}

int main()
{
    int t;
    cin >> t;
    int i;
    vector<string> v;
    for(i=0;i<t;i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for(i=0;i<t;i++)
    {
        int ans = transform(v[2*t],v[2*t+1]);
        cout << ans << "\n";
    }
}