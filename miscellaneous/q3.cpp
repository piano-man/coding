//first unit digit in a product
#include <bits/stdc++.h>
using namespace std;

int Modulo(string x,int y)
{
    int mod = 0;
    int l = x.length();
    int i;
    for(i=0;i<l;i++)
    {
        mod = (mod*10+(x[i]-'0'))%y;
    }
    return mod;
}

int xraisedy(string x,string y)
{
    int l1 = x.length();
    int l2 = y.length();
    if(l1==1&&l2==1&&x[l1-1]=='0'&&y[l2-1]=='0')
    {
        return 1;
    }
    if(l2==1&&y[l2-1]=='0')
    {
        return 1;
    }
    if(l1==1&&x[l1-1]=='0')
    {
        return 0;
    }
    int e = (Modulo(y,4)==0)?4:Modulo(y,4);
    int base = x[l1-1]-'0';
    int ans = pow(base,e);
    return ans%10;
}

int main() {
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        string a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f ;
        int n1,n2,n3;
        n1 = xraisedy(a,b);
        n2 = xraisedy(c,d);
        n3 = xraisedy(e,f);
        int ans = (n1*n2*n3)%10;
        cout << ans;
        cout << "\n";
    }
	return 0;
}