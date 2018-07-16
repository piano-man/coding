//Day of the week
#include<bits/stdc++.h>
using namespace std;

string getDay(int d,int m,int y)
{
    int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
    if(m<3)
    {
        y--;
    }
    string s;
    int day = ((y+y/4-y/100+y/400+t[m-1]+d)%7);
    switch(day)
    {
        case 0:
            return "Sunday";
            break;
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
    }       
}

int main()
{
    int t;
    cin >> t;
    int i;
    for(i=0;i<t;i++)
    {
        int d,m,y;
        cin >> d >> m >> y;
        cout << getDay(d,m,y);
        cout << "\n";
    }
}