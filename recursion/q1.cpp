//number of paths
#include<bits/stdc++.h>
using namespace std;

int paths(int rows,int columns,int xstart,int ystart)
{

    int count = 0;
    if(xstart==rows-1&&ystart==columns-1)
    {
        return 1;
    }
    if(xstart>=rows||ystart>=columns)
    {
        return 0;
    }
    count = paths(rows,columns,xstart+1,ystart)+paths(rows,columns,xstart,ystart+1);
    return count;
}

int main()
{
    int t;
    cin >> t;
    int i;
    vector<vector<int> >v;
    for(i=0;i<t;i++)
    {
        v.push_back(vector<int>());
    }
    for(i=0;i<t;i++)
    {
        int row,column;
        cin >> row;
        cin >> column;
        v[i].push_back(row);
        v[i].push_back(column);
    }
    for(i=0;i<t;i++)
    {
        int ans = paths(v[i][0],v[i][1],0,0);
        cout << ans << "\n";
    }
}