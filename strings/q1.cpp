//longest common prefix
#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;


int findmin(vector<string> v)
{
    int min = INT_MAX;
    int s = v.size();
    int i;
    for(i=0;i<s;i++)
    {
        if(v[i].length()<min)
        {
            min = v[i].length();
        }

    }
    return min;

}

int allcontainprefix(vector<string> v,int n,string ref,int start,int end)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=start;j<=end;j++)
        {
        if(v[i][j]!=ref[j])
        {
            return (false);
        }
        }

    }
    return (true);


}

string findprefix(vector<string> v,int min,int cases)
{

        string str = v[0];
        int n = v.size();
        int low = 0;
        string prefix;
        int high = min-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int k;
            for(k=0;k<=mid;k++)
            {
                if(allcontainprefix(v,n,v[0],low,mid))
                {
                    prefix = prefix+v[0].substr(low,mid-low+1);
                    low=mid+1;

                }
                else
                {
                    high = mid-1;
                }
            }


        }
        return prefix;
    

}

int main()
{
    int cases;
    int arr[200];
    cin >> cases;
    int i;
    vector<vector<string> > v;
    for (i = 0; i < cases; i++)
    {
        v.push_back(vector<string>());
    }
    //int *array[cases];
    for (i = 0; i < cases; i++)
    {
        cin >> arr[i];
        int j;
        for (j = 0; j < arr[i]; j++)
        {
            string n;
            cin >> n;
            v[i].push_back(n);
        }
    }
    for(i=0;i<cases;i++)
    {
        int min = findmin(v[i]);
        string s1 = findprefix(v[i],min,cases);
        cout << s1 << endl;
        

    }


}