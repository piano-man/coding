//kth smallest number
#include<bits/stdc++.h>
using namespace std;

int kthsmallest(int k)
{
    if(k<0)
    {
        return 0;
    }
    set<int> q3;
    set<int> q5;
    set<int> q7;
    q3.insert(1);
    int i,val=0;
    for(i=0;i<k;i++)
    {
        int v3 = (q3.size()>0)?*q3.begin():INT_MAX;
        int v5 = (q5.size()>0)?*q5.begin():INT_MAX;
        int v7 = (q7.size()>0)?*q7.begin():INT_MAX;
        val = min(v3,min(v5,v7));
        if(val==v3)
        {
            q3.erase(q3.begin());
            q3.insert(3*val);
            q5.insert(5*val);
            q7.insert(7*val);
        }
        else if(val==v5)
        {
            q5.erase(q5.begin());
            q5.insert(5*val);
            q7.insert(7*val);
        }
        else if(val==v7)
        {
            q7.erase(q7.begin());
            q7.insert(7*val);
        }
    }
    return val;
}

int main()
{
    int k;
    cin >> k;
    cout << kthsmallest(k);
}