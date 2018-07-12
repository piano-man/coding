//longest repeating non-overlapping substring
//DP solution
#include <bits/stdc++.h>
using namespace std;

string longest(string str)
{
    int n = str.length();
    int LCSRe[n+1][n+1];
 
    // Setting all to 0
    memset(LCSRe, 0, sizeof(LCSRe));
 
    int res_length  = 0; // To store length of result
 
    // building table in bottom-up manner
    int i, index = 0;
    for (i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {

            if (str[i-1] == str[j-1] &&
                LCSRe[i-1][j-1] < (j - i))
            {
                LCSRe[i][j] = LCSRe[i-1][j-1] + 1;
 
                if (LCSRe[i][j] > res_length)
                {
                    res_length = LCSRe[i][j];
                    index = max(i, index);
                }
            }
            else
                LCSRe[i][j] = 0;
        }
    }
    if (res_length > 0)
    {
        string res = "";
        for (i = index - res_length + 1; i <= index; i++)
            res.push_back(str[i-1]);
        return res;
    }

 
    return "-1";
}

int main() {
	int t;
	cin >> t;
	int i;
	for(i=0;i<t;i++)
	{
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    cout << longest(s);
        cout << "\n";
	}
	return 0;
}