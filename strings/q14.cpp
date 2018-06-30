//reverse words in a string
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void orderreverse(string s)
{
    vector<char> v;
    int n = s.length();
    int i,j;
    for(i=n-1;i>=0;i--)
    {
        v.push_back(s[i]);
    }
    //cout << v[0];
    list<char> dq;
    for(i=0;i<=n;i++)
    {
        if(i!=n)
        {
            if(v[i]!=' ')
            {
                //cout << v[i];
                dq.push_back(v[i]);
            }
            else
            {
                //cout << "in here";
                while(!dq.empty())
                {
                    //cout << "in here";
                    cout << dq.back();
                    dq.pop_back();
                }
                cout << " ";
            }
        }
        else{
                while(!dq.empty())
                {
                    //cout << "in here";
                    cout << dq.back();
                    dq.pop_back();
                }
        }

    }

}

int main()
{
    string s = "i like this program very much";
    int n = s.length();
    orderreverse(s);
}