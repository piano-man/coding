//nCr mod p
#include <bits/stdc++.h>
using namespace std;

long long int power(long long int x, long long int y,long long int p)
{
    long long int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
long long int modInverse(long long int n,long long int p)
{
    return power(n, p-2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
long long int comb(long long int n, long long int r,long long int p)
{
   // Base case
   if (r==0)
      return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    long long int fac[n+1];
    fac[0] = 1;
    for (long long int i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%p;
 
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}

 int main() {
	long long int t;
	cin >>t;
	long long int i;
	for(i=0;i<t;i++)
	{
	    long long int n,r;
	    long long int p = pow(10,9)+7;
	    cin >> n >> r;
	    cout << comb(n,r,p);
	    cout << "\n";
	}
	return 0;
}