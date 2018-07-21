//longest prefix suffix
#include <bits/stdc++.h>
using namespace std;

void computelps(string s,int n,int *lps)
{
    int i=1;
    int len = 0;
    lps[0] = 0;
    int ans = 0;
    while(i<n)
    {
        if(s[len]==s[i])
        {
            len++;
            lps[i] = len;
            i++;

        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int longest(string s)
{
    int n = s.length();
    int lps[n];
    computelps(s,n,lps);
    return lps[n-1];
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    cin >> s;
	    cout << longest(s);
	    cout << "\n";
	}
	return 0;
}