//change all even bits to 0
#include<bits/stdc++.h>
using namespace std;

int newnumber(int n)
{
    int temp = n;
    int i = 0;
    while(i<=32)
    {
        n = n&(~(1<<i));
        i+=2;
//        temp = temp>>i;
    }
    return n;
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
        cout << newnumber(n);
        cout << "\n";
    }
}