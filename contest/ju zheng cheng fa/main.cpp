#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int i,j,k,x;
    int a[100][100];
    int b[100][100];
    int c[100][100];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            cin>>b[i][j];
        }
    }
    k=n;
    x=-1;
    int sum;
    for(i=0;i<n;i++)
    {
        x=-1;
        k=n;
        while(k--)
        {
            sum=0;
            x++;
            for(j=0;j<n;j++)
            {
                sum+=a[i][j]*b[x][j];
            }
            c[i][x]=sum;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<c[i][j]<<endl;
    }
}
