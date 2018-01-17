//largest number formed
#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include<algorithm>
using namespace std;


int compare(int n1,int n2)
{
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    string s3 = s1.append(s2);
    string s4 = s2.append(s1);
    if(s3.compare(s4)>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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

    for(i=0;i<cases;i++)
    {
        sort(v[i].begin(),v[i].end(),compare);
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