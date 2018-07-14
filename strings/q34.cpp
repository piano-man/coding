//Given a binary string, count number of substrings that start and end with 1
#include<bits/stdc++.h>
using namespace std;

int answer(string s,int n)
{
    vector<int> table(n,0);
    int i,j;
    int sum = 0;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(s[j]=='1'&&s[i]=='1')
            {
                table[i] ++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        sum+=table[i];
    }
    return sum;
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
        cout << answer(s,n);
        cout << "\n";
    }
}