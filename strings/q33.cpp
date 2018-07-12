//Longest sub-string having frequency of each char less than integer k
#include<bits/stdc++.h>
using namespace std;

int longestsubstr(string s,int k)
{
    int n = s.length();
    int start = 0;
    int freq[26];
    int len = 0;
    memset(len,0,sizeof(len));
    int i;
    for(i=0;i<n;i++)
    {
        char ch = s[i];
        freq[ch]++;
        if(freq<=k)
        {
            len++;
                       
        }

    }   

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
        cout << longestsubstr(s,k);
        cout << "\n";
    }
}