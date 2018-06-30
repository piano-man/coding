//rightmost different bit
#include<bits/stdc++.h>
using namespace std;
int getposition(int n)
{
    return log2(n&-n)+1;
}

int diffbit(int m,int n)
{
    int rel = m^n;
    return getposition(rel);

}

int main()
{
    int m  = 11;
    int n  = 9;
    int ans = diffbit(m,n);
    cout << ans;
}