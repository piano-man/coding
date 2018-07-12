//LCS of '0' K Repeated String 
#include<bits/stdc++.h>
using namespace std;

long long int getlength(string s,long long int n)
{
    long long int i;
    long long int maxlen = 0;
    long long int max = 0;
    char prev = s[0];
    if(prev=='0')
    {
        maxlen=1;
    }
    for(i=1;i<n;i++)
    {
        if(s[i]=='0'&&prev=='0')
        {
            maxlen++;
            if(maxlen>max)
            {
                max = maxlen; 
           }
        }
        else if(s[i]=='0')
        {
            maxlen++;
            if(maxlen>max)
            {
                max = maxlen;
            }
            prev = 0;
        }
        else if(s[i]!=0)
        {
            maxlen = 0;
            prev = s[i];
        }

    }
    return max;
}

long long int LCS(string s,long long int k)
{
    long long int n = s.length();
    string temp="";
    long long int i;
    for(i=0;i<k;i++)
    {
        temp+=s;
    }
    return getlength(temp,n*k);
}

long long int main()
{
    long long int t;
    cin >> t;
    long long int i;
    for(i=0;i<t;i++)
    {
        long long int k;
        cin >> k;
        string s;
        cin >> s;
        cout << LCS(s,k);
        cout << "\n";
    }
}