#include <iostream>
using namespace std;
int slove(int n);
long long a[1001];
int main()
{
    int n;
    cin>>n;
    slove (n);
    cout<<a[n]+1;
    return 0;
}
int slove(int n)
{
    int i;
    long t=0;
    if(n==1)
    {
        return 0;
    }
    else if(a[n]==0)
    {
        for(i=1; i<=n/2; i++)
        {
            a[n]+=slove(i);
            t++;
        }
        a[n]+=t;
        return a[n];
    }
    else
    {
        return a[n];
    }
}
