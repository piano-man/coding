//can't find the error(contiguous sub array)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int cases;
    int arr[200];
    int sumarr[200];
    cin >> cases;
    int i;
    vector<vector<int> > v;
    for (i = 0; i < cases; i++)
    {
        v.push_back(vector<int>());
    }
    //int *array[cases];
    for (i = 0; i < cases; i++)
    {
        cin >> arr[i];
        cin >> sumarr[i];
        int j;
        for (j = 0; j < arr[i]; j++)
        {
            int n;
            cin >> n;
            v[i].push_back(n);
        }
    }
    /*for(i=0;i<cases;i++)
    {
        int j = arr[i];
        int k;
        for(k=0;k<j;k++)
        {
            cout << v[i][k];
        }
        cout << endl;
    }*/
    for (i = 0; i < cases; i++)
    {
        int sum = sumarr[i];
        int j;
        int curr_sum = v[i][0];
        int start = 0;

        for (j = 1; j < arr[i]; j++)
        {
            while (curr_sum > sum && start < j - 1)
            {
                curr_sum = curr_sum - v[i][start];
                start++;
            }

            if (curr_sum == sum)
            {
                cout << start << endl;
                cout << start << endl;
                continue;
            }
            if(j<arr[i])
            {
                curr_sum+=v[i][j];
            }
            if(j==arr[i])
            {
                cout << -1 << endl;
            }
        }
    }
}
