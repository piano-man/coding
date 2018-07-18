//Maximum bitonic subarray sum 
#include<bits/stdc++.h>
using namespace std;

long int maxsum(vector<long int> v,long int n)
{
    long int i;
    long int currsum = 0;
    bool ii1,ii2;
    bool wte1,wte2;
    ii1 = ii2 = wte2 = false;
    wte1 = true;
    long int inc_sum = v[0];
    long int dec_sum  = v[0];
    long int bi_sum = v[0];
    long int max_inc,max_bi;
    long int max_dec = max_inc = max_bi = v[0];
    long int prev = v[0];
    for(i=1;i<n;i++)
    {
        if(v[i]<prev)
        {
            dec_sum+=v[i];
            if(dec_sum>max_dec)
            {
                max_dec = dec_sum;
            }
            prev = v[i];
        }
        else
        {
            prev = v[i];
            dec_sum = prev;
        }
    }
    prev = v[0];
    for(i=1;i<n;i++)
    {
        if(v[i]>prev)
        {
            inc_sum+=v[i];
            if(inc_sum>max_inc)
            {
                max_inc = inc_sum;
            }
            prev = v[i];
        }
        else
        {
            prev = v[i];
            inc_sum = prev;
        }
    }
    prev = v[0];
    for(i=1;i<n;i++)
    {
        if(v[i]>prev&&(wte1||ii1))
        {
            bi_sum+=v[i];
            prev=v[i];
            ii1 = true;
            ii2 = false;
            wte2 = true;
            wte1 = false;
        }
        else if(v[i]<prev&&(ii2||wte2))
        {
            bi_sum+=v[i];
            if(bi_sum>max_bi)
            {
                max_bi = bi_sum;
            }
            prev=v[i];
            ii2 = true;
            ii1 = false;
            wte2 = false;
            wte1 = false;

        }
        else if(v[i]>prev&&!(ii1||wte1))
        {
            bi_sum = prev+v[i];
            prev = v[i];
            ii1 = true;
            ii2 = false;
            wte2 = false;
            wte2 = true;

        }
        else
        {
            prev=v[i];
            bi_sum = prev;
            ii1 = false;
            ii2 = false;
            wte2 = false;
            wte1 = true;
        }

    }
    long int final_max = max(max_inc,max(max_dec,max_bi));
    return final_max;
}

long int main()
{
    long int t;
    cin >> t;
    while(t--)
    {
        long int n;
        cin >> n;
        vector<long int> v;
        long int i;
        for(i=0;i<n;i++)
        {
            long int k;
            cin >> k;
            v.push_back(k);
        }
        cout << maxsum(v,n);
        cout << "\n";
    }
}