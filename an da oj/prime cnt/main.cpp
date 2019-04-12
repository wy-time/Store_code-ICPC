#include <iostream>
using namespace std;
bool isprime(int n);
int a[900005];
int slove(int n);
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        int cnt=0;
        int i;
        for(i=m;i<=n;i++)
        {
            if(isprime(i))
                cnt++;
        }
        /*if(isprime(m))
        {
            cnt++;
        }
        if(isprime(n))
        {
            cnt++;
        }
        cnt+=slove(n)-slove(m);*/
        cout<<cnt<<endl;;
    }
    return 0;
}
/*int slove(int n)
{
    int cnt=0;
    if(n==1)
        return 0;
    if(a[n]==0)
    {
        if(isprime(n))
            cnt++;
        cnt+=slove(n-1);
        a[n]=cnt;
    }else
    {
        cnt=a[n];
    }
    return cnt;
}*/
bool isprime(int n)
{
    int i;
    bool right=true;
    if(n==1)
    {
        right=false;
    }
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            right=false;
            break;
        }
    }
    return right;
}
