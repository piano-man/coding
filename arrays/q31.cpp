//longest alternating subsequence
#include<bits/stdc++.h>
using namespace std;

int getlongest(vector<int> v,int n)
{
    int las[n][2];
    int m = 0;
    int i,j;
    for(i=0;i<n;i++)
    {
        las[i][0] = las[i][1] = 1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(v[i]>v[j])
            {
                las[i][0] = max(las[i][0],las[j][1]+1);
                if(las[i][0]>m)
                {
                    m = las[i][0];
                }
            }
            else if(v[i]<v[j])
            {
                las[i][1] = max(las[i][1],las[j][0]+1);
                if(las[i][1]>m)
                {
                    m = las[i][1];
                }
            }
        }
    }
    return m;
}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        int n;
        cin >> n;
        int j;
        vector<int> v;
        for(j=0;j<n;j++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        cout << getlongest(v,n);
        cout << "\n";
    }

}