#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[30][30],b[30][30];
    int i,j,k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }
    int sum[30]= {0};
    if(m==0)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                a[i][j]=0;
        }
        for(i=0; i<n; i++)
            a[i][i]=1;
    }
    else if(m==1)
    {
    }
    else
    {
        m-=1;
        while(m--)
        {
            for(i=0; i<n; i++)
            {
                for(k=0; k<n; k++)
                {
                    sum[k]=0;
                    for(j=0; j<n; j++)
                    {
                        sum[k]+=a[i][j]*b[j][k];
                    }
                }
                for(k=0; k<n; k++)
                    a[i][k]=sum[k];
            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<a[i][j]<<endl;
    }
    return 0;
}
