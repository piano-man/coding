//longest increasing subsequence
#include<bits/stdc++.h>
using namespace std;

int longestsubsq(vector<int> v,int n)
{
    vector<int> arr(n,1);
    int i,j;
    int max = 0;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if((v[i]>v[j])&&(arr[i]<arr[j]+1))
            {
 //               cout << "inside";
                arr[i] = arr[j]+1;
                if(arr[i]>max)
                {
                    max = arr[i];
                }
            }
        }
    }
    return max;
}

int main()
{
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
        cout << longestsubsq(v,n);
        cout << "\n";
    }
}