//minimum shift for longest common prefix(kmp algorithm)
#include<bits/stdc++.h>
using namespace std;

void computelps(string pat,int *lps,int m)
{
    int i=1;
    lps[0] = 0;
    int len = 0;
    while(i<m)
    {
        if(pat[len]==pat[i])
        {
            len++;
            i++;
            lps[i] = len;
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

int kmpmatch(string pat,string str,int m,int n)
{
    int lps[m];
    computelps(pat,lps,m);
    int pat_ind = 0,str_ind = 0;
    int start = INT_MIN;
    int len = 0;
    while(pat_ind<m&&str_ind<n)
    {
        if(pat[pat_ind]==str[str_ind])
        {
            pat_ind++;
            str_ind++;
            if(pat_ind>len)
            {
                len = pat_ind;
            }
            start = str_ind-pat_ind;
        }
        else
        {
            if(pat_ind!=0)
            {
            pat_ind = lps[pat_ind-1];
            }
            else
            {
                str_ind++;
            }

        }
    }
    return start;
}

int longestprefix(string s1,string s2)
{
    int ori = s2.length();
    s2 = s2+s2;
    int m = s1.length();
    int n = s2.length();
    // for(sublen = 1;sublen<=n;sublen++)
    // {
    //     for(i=0;i<n-sublen+1;i++)
    //     {
    //         string test = s1.substr(i,sublen);
    //         int ans = s2.find(test);
    //         if(ans!=-1)
    //         {
    //             if(sublen>max)
    //             {
    //                 max = sublen;
    //                 start = ans;
    //             }
    //         }
            
    //     }
    // }
    return kmpmatch(s1,s2,m,n)%ori;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    cout << longestprefix(s1,s2); 
}