#include <bits/stdc++.h>
using namespace std;

int longest(vector<int> v,int n)
{
    int start = 0,end = 0;
    int currstart = 0;
    int sum = v[0];
    int max = sum;
    int i;
    for(i=1;i<n;i++)
    {
        if(sum+v[i]<sum)
        {
            currstart = i;
            sum = v[currstart];
            if(sum>=max)
            {
                start = currstart;
                end = currstart;
                max = sum;
            }
        }
        else
        {
            sum=sum+v[i];
            if(sum>=max)
            {
                end = i;
                max = sum;
            }
        }
    }
    return max;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
        cin >> n;
	    vector<int> v;
	    int i;
	    for(i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        v.push_back(k);
	    }
	    cout << longest(v,n);
	    cout << "\n";
	}
	return 0;
}