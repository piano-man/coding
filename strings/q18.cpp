//word boggle
//can't find error
#include<bits/stdc++.h>
using namespace std;

void printwords(vector<string> v,vector<char> v1)
{
    int count[26];
    int check = 0;
    vector<int> temp(26);
    memset(count,0,sizeof(count));
    int l = v1.size();
    int i;
    for(i=0;i<l;i++)
    {
        count[v1[i]-'A']++;
    }
    int l1 = v.size();
    for(i=0;i<l1;i++)
    {
        copy(count,count+26,temp.begin());
        string s = v[i];
        int l2 = s.length();
        int j;
        int flag=0;
        for(j=0;j<l2;j++)
        {
            if(temp[s[j]-'A']!=0)
            {
                temp[s[j]-'A']--;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout << s << " ";
            check++;
        }
    }
    if(check==0)
    {
        cout << -1;
    }
}
int main()
{
    int t;
    cin >> t;
    int i;
    vector<vector<string> >v;
    vector<vector<char> > v1;
    for(i=0;i<t;i++)
    {
        v.push_back(vector<string>());
        v1.push_back(vector<char>());
    }
    for(i=0;i<t;i++)
    {
        int n;
        cin >> n;
        int j;
        for(j=0;j<n;j++)
        {
            string s;
            cin >> s;
            v[i].push_back(s);
        }
        int n1,n2;
        cin >> n1 >> n2;
        int tot = n1*n2;
        for(j=0;j<tot;j++)
        {
            char ch;
            cin >> ch;
            v1[i].push_back(ch);
        }
    }
    for(i=0;i<t;i++)
    {
        printwords(v[i],v1[i]);
    }
}