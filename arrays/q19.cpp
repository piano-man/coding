//next larger element
//use stack
#include<bits/stdc++.h>
using namespace std;

void nextlarger(vector<int> v)
{
    map<int,int> m;
    int n = v.size();
    stack<int> s;
    s.push(v[0]);
    int i;
    for(i=1;i<n;i++)
    {
        int next = v[i];
        if(s.empty()==false)
        {
            int ele = s.top();
            while(next>ele)
            {
                s.pop();
                m[ele] = next;
                if(s.empty()==true)
                {
                    break;
                }
                ele = s.top();
            }
            s.push(next);
        }
    }
    while(s.empty()==false)
    {
        int ele = s.top();
        m[ele] = -1;
        s.pop();
    }
    map<int,int>::iterator it;
    for(i=0;i<n;i++)
    {
        it = m.find(v[i]);
        cout << it->second << " ";
    }
    cout << "\n";

}

int main()
{
    int t;
    cin >> t;
    vector<int> size;
    vector<vector<int> > v;
    int i;
    for(i=0;i<t;i++)
    {
        v.push_back(vector<int>());
    }
    for(i=0;i<t;i++)
    {
        int n;
        cin >> n;
        size.push_back(n);
        int j;
        for(j=0;j<n;j++)
        {
            int k;
            cin >> k;
            v[i].push_back(k);
        }
    }
    for(i=0;i<t;i++)
    {
        nextlarger(v[i]);
    } 
}