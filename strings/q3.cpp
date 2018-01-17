//longest palindrome in a string
//try with manachers algorithm
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<climits>
using namespace std;


void longpalin(string s)
{
    int len = s.length();
    int start=0;
    int table[len][len];
    //1 for true 0 for false
    int i , j ;
    int maxlength;
    for(i=0;i<len;i++)
    {
        table[i][i]=1;
        maxlength = 1;
    }
    for(i=0;i<len-1;i++)
    {
        if(s[i]==s[i+1])
        {
            table[i][i+1]==1;
            maxlength=2;
            start = i;
        }
    }
    int sublen;
    for(sublen=3;sublen<len;sublen++)
    {
        for(i=0;i<len-sublen+1;i++)
        {
            j = i+sublen-1;
            if(s[i]==s[j])
            {
                if(table[i+1][j-1]==1)
                {
                    table[i][j]==1;
                    if(sublen>maxlength)
                    {
                        maxlength=sublen;
                        start = i;
                    }
                }
                else{
                    table[i][j]=0;
                }
            }
            else{
                table[i][j]=0;
            }
        
        }
        
    }
    string result = s.substr(start,start+maxlength-1);
    cout << result;

}

int main()
{
    int cases;
    cin >> cases;
    int i;
    vector<string> v;
    for(i=0;i<cases;i++)
    {
        string n;
        cin >> n;
        v.push_back(n);
    }
    for(i=0;i<cases;i++)
    {
        longpalin(v[i]);
    }
}