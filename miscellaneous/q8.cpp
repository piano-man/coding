//median in a stream
#include <bits/stdc++.h>
using namespace std;

void med(vector<int> v)
{
    int l = v.size();
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int> >g;
    s.push(v[0]);
    int m = s.top();
    cout << m << "\n";
    int i;
    for(i=1;i<l;i++)
    {
        int ele = v[i];
        if(s.size()>g.size())
        {
            if(ele<m)
            {
                g.push(s.top());
                s.pop();
                s.push(ele);
            }
            else
            {
                g.push(ele);
            }
            m = (s.top()+g.top())/2;
        }
        else if(s.size()==g.size())
        {
            if(ele<m)
            {
                s.push(ele);
                m = s.top();
            }
            else
            {
                g.push(ele);
                m = g.top();
            }
        }
        else if(g.size()>s.size())
        {
            if(ele<m)
            {
                s.push(ele);
            }
            else
            {
                s.push(g.top());
                g.pop();
                g.push(ele);
            }
            m = (g.top()+s.top())/2;
        }
        cout << m << "\n";
    }
   
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    while(n--)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }
    med(v);
	return 0;
}