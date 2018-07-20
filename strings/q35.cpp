//count occurences of anagrams
#include<bits/stdc++.h>
using namespace std;

int getoccurence(string s,string p)
{
    map<char,int> m1;
    map<char,int> m2;
    int n = s.length();
    int len = p.length();
    int i;
    for(i=0;i<len-1;i++)
    {
        m1[s[i]]++;
    }
    for(i=0;i<len;i++)
    {
        m2[p[i]]++;
    }
    int occ = 0;
    int k;
    for(i=0;i<n-len+1;i++)
    {
        int flag=0;
        int j = i+len-1;
        m1[s[j]]++;
        for(k=0;k<len;k++)
        {
            if(m1.find(p[k])==m1.end())
            {
                flag = 1;
            }
            else
            {
                if(m1[p[k]]!=m2[p[k]])
                {
                    flag = 1;
                }
            }
        }
        if(flag==0)
        {
            occ++;
        }
        m1[s[i]]--;

    }
    return occ;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s,p;
        cin >> s;
        cin >> p;
        cout << getoccurence(s,p);
        cout << "\n";
    }
}