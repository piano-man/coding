//nearly sorted array(using min-heap)
#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class Minheap{
    int *harr,size;
public:
    Minheap(int *harr,int size);
    void Minheapify(int i);
    int replacemin(int *arr,int i);
    int extractmin();
    int left(int i){return (2*i+1);}
    int right(int i){return (2*i+2);}

};

Minheap::Minheap(int *arr,int s)
{
    size = s;
    harr = arr;
    int i = (size-1)/2;
    for(;i>=0;i--)
    {
        Minheapify(i);
    }
}

void Minheap::Minheapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<size && harr[l]<harr[i])
    {
        smallest = l;
    }
    if(r<size && harr[r]<harr[smallest])
    {
        smallest = r;
    }
    if(smallest!=i)
    {
        swap(&harr[i],&harr[smallest]);
        Minheapify(smallest);
    }

}

int Minheap::replacemin(int *arr,int i)
{
    int ans = harr[0];
    harr[0] = arr[i];
    if(ans<harr[0])
    {
        Minheapify(0);
    }
    return ans;
}

int Minheap::extractmin()
{
    int result = harr[0];
    if(size>1)
    {
        harr[0] = harr[size-1];
        size--;
        Minheapify(0);
    }

    return result;
}

void sortk(int *arr,int n,int k)
{
    int i;
    int *harr;
    for(i=0;i<=k;i++)
    {
        harr[i] = arr[i];
    }
    Minheap hp(harr,k+1);
    int ti;
    for(i=k+1,ti=0;i<n,ti<n;i++,ti++)
    {
        if(i<n)
        {
            arr[ti] = hp.replacemin(arr,i);
        }
        else
        {
            arr[ti] = hp.extractmin();
        }
    }

}

int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortk(arr, n, k);
    int i;
    for(i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}