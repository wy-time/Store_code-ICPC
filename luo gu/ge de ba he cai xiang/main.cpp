#include<cstring>
#include <iostream>
#include<cstdlib>
using namespace std;
void prime (int n);
bool slove (int n,int times);
bool a[30000];
int result[4];
int main()
{
    int n;
    cin>>n;
    memset(a,true,sizeof(a));
    a[0]=a[1]=false;
    prime(25000);
    int times=0;
    slove(n,times);
    int i=0;
    for(i=1;i<3;i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<result[i]<<endl;
    return 0;
}
bool slove (int n,int times)
{
    times++;
    if(times==3)
    {
        if(a[n])
        {
            result[times]=n;
            return true;
        }
        else
            return false;
    }
    int i=0;
    for(i=2;i<n;i++)
    {
        if(a[i])
        {
            if(slove(n-i,times))
            {
                result[times]=i;
                return true;
            }

        }
    }
    return false;
}
void prime (int n)
{
    int i=2;
    int j;
    for(i=2;i*i<=n;i++)
    {
        if(a[i])
        {
            for(j=i*2;j<=n;j+=i)
            {
                a[j]=false;
            }
        }
    }
}
