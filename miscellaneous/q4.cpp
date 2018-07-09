//Power of K in N! where K may be Non Prime
#include<bits/stdc++.h>
using namespace std;

vector<int> getspf(int k)
{
    vector<int> spf(k+1,0);
    spf[1] = 1;
    int i;
    for(i=2;i<=k;i++)
    {
        if(spf[i]==0)
        {
            spf[i] = i;
            int j;
            for(j=2*i;j<=k;j+=i)
            {
                if(spf[j]==0)
                {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

map<int,int> getfactors(int k)
{
    vector<int> spf = getspf(k);
    map<int,int> result;
    while(k!=1)
    {
        result[spf[k]]++;
        k = k/spf[k];
    }
    return result;
}

int findpowinN(int n,int ele)
{
    int x = 0;
    while(n)
    {
        n=n/ele;
        x+=n;
    }
    return x;
}

void getpow(long int n,long int k)
{
    map<int,int> m= getfactors(k);
    map<int,int>::iterator it;
    int ans = INT_MAX;
    for(it=m.begin();it!=m.end();it++)
    {
        int ele = it->first;
        int num = findpowinN(n,ele);
        ans = min(ans,num/it->second);
    }

    cout << ans;

}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        long int n,k;
        cin >> n >> k;
        getpow(n,k);
        cout << "\n";
    }
}