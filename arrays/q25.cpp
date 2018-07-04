//largest fibonacci subsequence
#include<bits/stdc++.h>
using namespace std;

void longestsubsq(vector<int> v)
{
    
}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        int n;
        vector<int> v;
        cin >> n;
        int j;
        for(j=0;j<n;j++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        longestsubsq(v);
    }
}