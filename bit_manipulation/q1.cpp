//first set bit
#include<bits/stdc++.h>
using namespace std;

int getposition(int n)
{
    return log2(n&-n)+1;
}

int main()
{
    int n = 18;
    cout << getposition(n);
}