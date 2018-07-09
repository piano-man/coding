//Find unit digit in a product
//gives time limit error.refer q3 for efficient solution
#include <bits/stdc++.h>
using namespace std;

int xraisedy(int x,int y)
{
    int res = 1;
    int i;
    for(i=0;i<y;i++)
    {
        res = (res*x)%10;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f ;
        long long int n1,n2,n3;
        n1 = xraisedy(a,b);
        n2 = xraisedy(c,d);
        n3 = xraisedy(e,f);
        int ans = n1*n2*n3;
        cout << (ans%10);
        cout << "\n";
    }
	return 0;
}