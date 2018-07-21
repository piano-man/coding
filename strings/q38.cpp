//String formation from substring
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

void longest(string s)
{
    int n = s.length();
    int lps[n];
    computelps(s,n,lps);
    double mid = ceil(n/2.0);
    if(lps[n-1]>=mid)
    {
        cout << "True";
        return;
    }
    cout << "False";
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    cin >> s;
	    longest(s);
	    cout << "\n";
	}
	return 0;
}