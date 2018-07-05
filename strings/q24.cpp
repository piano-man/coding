//non-repeating character
#include<bits/stdc++.h>
using namespace std;

int getrepeating(string s,int n)
{
    unordered_map<char,int> m;
    vector<char> order;
    int i;
    for(i=0;i<n;i++)
    {
        m[s[i]]++;
        order.push_back(s[i]);
    }
    for(i=0;i<n;i++)
    {
        char c = order[i];
        int count = m[c];
        if(count==1)
        {
            return c;
        }
    }
    return -1;

}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = getrepeating(s,n);
        if(ans==-1)
        {
            cout << -1;
        }
        else
        {
            cout << char(ans);
        }
        cout << "\n";
    }
}