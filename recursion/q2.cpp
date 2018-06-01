//combintional sum
//unable to print only unique results
#include<bits/stdc++.h>
using namespace std;

void getans(vector<vector<int> >&result,vector<int>&temp,int sum,int i,vector<int>v,int size)
{
    if(sum==0)
    {
        result.push_back(temp);
        return;
    }
    if(sum<0)
    {
        return;
    }
    while(i<size&&sum-v[i]>=0)
    {
        int val = v[i];
        sum=sum-v[i];
        temp.push_back(v[i]);
        i++;
        getans(result,temp,sum,i,v,size);
        sum = sum + val;
        temp.pop_back();
    }
}

vector<vector<int> > combinations(vector<int> v,int sum,int size)
{
    vector<vector<int> >result;
    vector<int> temp;
    sort(v.begin(),v.end());
    getans(result,temp,sum,0,v,size);
    return result;
}

int main()
{
    int t;
    cin >> t;
    vector<int> size;
    vector<vector<int> >input;
    vector<int> sum;
    int i;
    for(i=0;i<t;i++)
    {
        input.push_back(vector<int>());
    }
    for(i=0;i<t;i++)
    {
        int s;
        cin >> s;
        size.push_back(s);
        int j;
        for(j=0;j<s;j++)
        {
            int n;
            cin >> n;
            input[i].push_back(n);
        }
        int m;
        cin >> m;
        sum.push_back(m);
    }
    for(i=0;i<t;i++)
    {
        vector<vector<int> >res = combinations(input[i],sum[i],size[i]);
        int l = res.size();
        if(l==0)
        {
            cout << "Empty";
            continue; 
        }
        vector< vector<int> >::iterator new_end = unique (res.begin (), res.end ());
        for (vector< vector<int> >::iterator it = res.begin (); it != new_end; ++it)
        {
            cout << "(";
        for (vector<int>::iterator j = it->begin (), j_end = it->end (); j != j_end; ++j)
        {
            cout << *j << " ";
        }
        cout << ")";
        }


        // int j;
    //     for(j=0;j<l;j++)
    //     {
    //         int l2 =  res[j].size();
    //         int k;
    //         cout << "(";
    //         for(k=0;k<l2;k++)
    //         {
    //             cout << res[j][k] << " ";
    //         }
    //         cout << ")";

    //     }
    //     cout << "\n";
    // }
}
}