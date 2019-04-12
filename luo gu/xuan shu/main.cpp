#include <iostream>
using namespace std;
int a[25];
int n,k;
void slove (int i,int times,int sum);
bool isprime(int t);
int cnt=0;
int main()
{
    cin>>n>>k;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        slove(i,0,a[i]);
    }
    cout<<cnt;
    return 0;
}
void slove (int i,int times,int sum)
{
    times++;
    if(times==k-1)
    {
        for(i+=1;i<n;i++)
        {
            int t=sum+a[i];
            if(isprime(t))
            {
                cnt++;
            }

        }
    }else
    {
        for(i+=1;i<n;i++)
        {
            int t=sum+a[i];
            slove(i,times,t);
        }
    }
}
bool isprime(int t)
{
    int i;
    bool q=true;
    for(i=2;i*i<=t;i++)
    {
        if(t%i==0)
        {
            q=false;
            break;
        }
    }
    return q;
}
