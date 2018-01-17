//sort rrays of 0's 1's and 2's
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;

}
int main()
{
    int cases;
    int arr[200];
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
    for(i=0;i<cases;i++)
    {
        int mid = 0,low=0;
        int high = arr[i]-1;
        while(mid<=high)
        {
            switch(v[i][mid])
            {
                case 0:
                    swap(&v[i][low++],&v[i][mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(&v[i][mid],&v[i][high--]);
                    break;
            }
        }

    }
    for(i=0;i<cases;i++)
    {
        int j = arr[i];
        int k;
        for(k=0;k<j;k++)
        {
            cout << v[i][k];
        }
        cout << endl;
    }

    
}