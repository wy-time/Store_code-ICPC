#include <iostream>
#include<algorithm>
using namespace std;
const int MAX1=200000;
long long ans[500000];
int main()
{
    std::ios::sync_with_stdio(false);
    long long i;
    long long cnt=2;
    ans[0]=4;
    ans[1]=7;
    long long po[12]= {10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000};
    for(i=3; i<MAX1; i++)
    {
        long long lnum=0;
        bool first=true;
        long long ttt=0;
        long long t=i;
        bool isbreak=false;
        while(t)
        {
            if(t&1)
            {
                if(first)
                {
                    lnum=4;
                    first=false;
                }
                else
                {
                    lnum=4*po[ttt]+lnum;
                    ttt++;
                }
                t>>=1;
            }
            else
            {
                t>>=1;
                if(!(t&1))
                {
                    isbreak=true;
                    break;
                }
                if(first)
                {
                    lnum=7;
                    first=false;
                }
                else
                {
                    lnum=7*po[ttt]+lnum;
                    ttt++;
                }
                t>>=1;
            }
        }
        if(!isbreak)
        {
            ans[cnt]=lnum;
            cnt++;
        }
    }
    sort(ans,ans+cnt);
    for(i=0;i<cnt;i++)
    {
        if(ans[i]<=0)
            ans[i]=44444444444;
        else
            break;
    }
    sort(ans,ans+cnt);
    long long l,r;
    cin>>l>>r;
    for(i=0; i<cnt; i++)
    {
        if(l<=ans[i])
            break;
    }
    long long temp=i;
    long long result=0;
    while(l<=r)
    {
        if(ans[temp]<=r)
        {
            result+=(ans[temp]-l+1)*ans[temp];
            l=ans[temp]+1;
            temp++;
        }
        else
        {
            result+=ans[temp]*(r-l+1);
            l=r+1;
        }
    }
    cout<<result;
    return 0;
}
