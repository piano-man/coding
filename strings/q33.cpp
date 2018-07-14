//Longest sub-string having frequency of each char less than integer k
#include<bits/stdc++.h>
using namespace std;

int longestsubstr(string s,int k)
{
    int n = s.length();
    int start = -1;
    int freq[26];
    int currlen = 0;
    int maxlen = 0;
    memset(freq,0,sizeof(freq));
    int i = 0;
    while(i<n)
    {
        char ch = s[i]-'a';
        freq[ch]++;
        if(freq[ch]<=k)
        {
            cout << "inside";
            currlen++;
            if(currlen>maxlen)
            {
                cout << "here";
                maxlen = currlen;
            }
            i++;           
        }
        else if(freq[ch]>k)
        {
            while(freq[ch]>k)
            {
                start++;
                char c = s[start]-'a';
                freq[c]--;
            }
            currlen = currlen-(start+1);
            i++;
        }

    }
    return maxlen+1;   

}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;
        cout << longestsubstr(s,k);
        cout << "\n";
    }
}