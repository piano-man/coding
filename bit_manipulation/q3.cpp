//copy set bits in range
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        int x,l,r,y;
        cin >> x >> l >> r >> y;
        vector<int> setbits;
        int j;
        for(j=l;j<=r;j++)
        {
            if((y&(1<<j-1))!=0)
            {
                x = (x|(1<<j-1));
            }
        }
        cout << x << "\n";
    }
}