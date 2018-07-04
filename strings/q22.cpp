//k-palindrome
#include <bits/stdc++.h>
using namespace std;
bool is_k_palin(string s,int k);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}

int palindrome(string s)
{
    int n = s.length();
    int table[n][n];
    int i;
    for(i=0;i<n;i++)
    {
        table[i][i] = 1;
    }
    for(i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            table[i][i+1] = 2;
        }
        else
        {
            table[i][i+1]=1;
        }
    }
    int sublen;
    for(sublen = 3;sublen<=n;sublen++)
    {
        for(i=0;i<n-sublen+1;i++)
        {
            int j = i+sublen-1;
            if(s[i]==s[j])
            {
                table[i][j] = table[i+1][j-1]+2;
            }
            else
            {
                table[i][j] = max(table[i+1][j],table[i][j-1]);
            }
        }
    }
    return table[0][n-1];
}

bool is_k_palin(string s,int k)
{
    int len = palindrome(s);
    int l = s.length();
    if(l-len<=k)
    {
        return true;
    }
    return false;
}