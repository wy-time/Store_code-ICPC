#include <iostream>
#include<algorithm>
#include<cstring>
bool q [1005][1005];
int c[1005][1005];
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(q,true,sizeof(q));
        int n;
        cin>>n;
        int a[1005];
        int b[1005];
        int i;
        long long r=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                c[i][j]=b[i]*a[j];
            }
        }
        if(c[0][0]>c[0][n-1])
        {
            r+=c[0][0];
            q[0][0]=false;
        }else
        {
            r+=c[0][n-1];
            q[0][n-1]=false;
        }
        for(i=1;i<n;i++)
        {
            int max1=-1;
            int x=-1,y=-1;
            for(int j=0;j<n;j++)
            {
                if(q[i][j])
                {
                    if(q[i-1][j]==false)
                        q[i][j]=false;
                    else if(max1<c[i][j])
                    {
                        max1=c[i][j];
                        x=i,y=j;
                    }
                }
            }
            q[x][y]=false;
                r+=max1;
        }
        cout<<r<<endl;
    }
    return 0;
}
