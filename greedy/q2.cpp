//largest number formed
#include<bits/stdc++.h>
using namespace std;

void getnumber(int n,int s)
{
    int i;
    int flag = 0;
    for(i=0;i<n;i++)
    {
        if(9*n<s || (s==0&&flag==0))
        {
            cout << -1;
            return;
        }
        if(s>=9)
        {
            cout << 9;
            s = s-9;
            flag=1;
        }
        else
        cout << s;
    }
    cout << "\n";
}

int main()
{
    int t,i;
    cin >> t;
    vector<int> digits;
    vector<int> sum;
    for(i=0;i<t;i++)
    {
        int n,s;
        cin >> n;
        cin >> s;
        digits.push_back(n);
        sum.push_back(s);
    }
    for(i=0;i<t;i++)
    {
         getnumber(digits[i],sum[i]);
    }
}