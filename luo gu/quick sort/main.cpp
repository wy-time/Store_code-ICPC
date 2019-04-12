#include <iostream>
using namespace std;
void quicksort(int*a,int up,int down);
int main()
{
    int n;
    cin>>n;
    int a[100005];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int up=0,down=n-1;
    quicksort(a,up,down);
    for(i=0;i<n-1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[i]<<endl;
    return 0;
}
void quicksort(int*a,int up,int down)
{
    int i,j;
    int mid=(up+down)/2;
    i=up,j=down;
    int k=a[mid];
    while(i<=j)
    {
        while(a[i]<k)
            i++;
        while(a[j]>k)
            j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if(up<j)
        quicksort(a,up,j);
    if(down>i)
        quicksort(a,i,down);
}

