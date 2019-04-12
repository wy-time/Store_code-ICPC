#include <iostream>
using namespace std;
int ans[7000000];
int main()
{
    std::ios::sync_with_stdio(false);
    int ng,n;
    cin>>ng>>n;
    int cnt=0;
    int max1=-1;
    int p1=-1;
    int p2=-1;
    while(ng--)
    {
        int ns,s,a,b,mod;
        cin>>ns>>s>>a>>b>>mod;
        ans[cnt]=s;
        if(ans[cnt]>=max1)
        {
            if(ans[cnt]>=max1)
            {
                max1=ans[cnt];
                p2=p1=cnt;
            }else
                p2=cnt;
        }
        while(ns--)
        {
            int temp=(ans[cnt]*a+b)%mod;
            cnt++;
            if(temp==0)
                ans[cnt]=mod;
            else
                ans[cnt]=temp;
            if(ans[cnt]>max1)
        }
        cnt++;
    }

    return 0;
}
