#include <iostream>
using namespace std;
int a[100005];
long long temp [100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    temp[0]=a[0];
    for(i=1;i<n;i++)
    {
        temp[i]=temp[i-1]+a[i];
    }
    while(m--)
    {
        long long sum=0;
        int f,x,y;
        cin>>f>>x>>y;
        if(f==1)
        {
            for(i=x-1;i<n;i++)
            {
                temp[i]+=y;
            }
        }else
        {
            sum=temp[y-1]-temp[x-2];
            cout<<sum<<endl;
        }
    }
    return 0;
}
