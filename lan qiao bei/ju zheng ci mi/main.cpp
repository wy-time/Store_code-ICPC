#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,j,k;
    int a[35][35],b[35][35],c[35][35];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }
    if(m!=0)
    {
        m-=1;
        while(m--)
        {
            for(i=0;i<n;i++)
            {
                for(k=0;k<n;k++)
                {
                    int sum=0;
                    for(j=0;j<n;j++)
                    {
                        sum+=a[i][j]*b[j][k];
                    }
                    c[i][k]=sum;
                }
            }
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    a[i][j]=c[i][j];
                }
            }
        }
    }else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=0;
            }
        }
        for(i=0;i<n;i++)
        {
            a[i][i]=1;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<a[i][j]<<endl;
    }
    return 0;
}
