//longest even length substring
#include<bits/stdc++.h>
using namespace std;

void evenlength(string s)
{
    int l = s.length();
    int i,len;
    int max = 0; 
    for(i=0;i<l;i++)
    {
        for(len=2;len<=l;len+=2)
        {
            int j = i+len-1;
            int mid = len/2-1+i;
            int k;
            int suml = 0;
            int sumr = 0;
            for(k=i;k<=mid;k++)
            {
                int val = s[k]-'0';
                suml+=val;
            }
            for(k=mid+1;k<=j;k++)
            {
                int val = s[k]-'0';
                sumr+=val;
            }
            if(suml==sumr)
            {
                if(len>max)
                {
                    max = len;
                }
            }
        }
    }
    cout << max;
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
        evenlength(s);
        cout << "\n";
    }
}