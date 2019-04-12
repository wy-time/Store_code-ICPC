#include <iostream>
using namespace std;
int a[1005][1005];
int r[1005][1005];
int main()
{
    int n;
    cin>>n;
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i+1;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        r[n-1][i]=a[n-1][i];
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<i+1;j++)
        {
            r[i][j]=max(r[i+1][j]+a[i][j],r[i+1][j+1]+a[i][j]);
        }
    }
    cout<<r[0][0];
}
