//sort a stack
#include <bits/stdc++.h>
using namespace std;
class SortedStack
{
  public:
    stack<int> s;
    void sort();
};
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("");
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */
void sortedinsert(stack<int> &s, int ele)
{
    if (s.empty() || ele > s.top())
    {
        s.push(ele);
    }
    else
    {
        int temp = s.top();
        s.pop();
        sortedinsert(s, ele);
        s.push(temp);
    }
}

void finalsort(stack<int> &s)
{
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();
        finalsort(s);
        sortedinsert(s, temp);
    }
}

void SortedStack::sort()
{
    finalsort(s);
}