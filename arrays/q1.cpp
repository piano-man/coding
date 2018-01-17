#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int cases;
    int arr[200];
    cin >> cases;
    int i;
    vector <vector< int > > v;
    for(i=0;i<cases;i++)
    {
        v.push_back( vector<int>() );
    }
    //int *array[cases];
    for (i = 0; i < cases; i++)
    {
        cin >> arr[i];
        int j;
        for(j=0;j<arr[i];j++)
        {
            int n;
            cin >> n;
            v[i].push_back(n);
        }

    }
    for(i=0;i<cases;i++)
    {
        int j;
        int total = INT_MIN;
        int current = 0;
        for(j=0;j<arr[i];j++)
        {
            current = current + v[i][j];
            if(total<current)
            {
                total = current;
            }
            if (current<0)
            {
                current = 0;

            }
        }
        cout << total << endl ; 

    }
}

