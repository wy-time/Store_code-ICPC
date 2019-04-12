#include <iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll ans[100005];
ll temp[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=0; i<n; i++)
    {
        cin>>ans[i];
    }
    if(n!=1&&n!=2)
    {
        ll cha=ans[0]-ans[1];
        int canuse=1;
        for(i=1; i<n-1; i++)
        {
            ll temp=ans[i]-ans[i+1];
            if(temp!=cha)
            {
                canuse=0;
                break;
            }
        }
        if(canuse)
        {
            cout<<0;
            return 0;
        }
    }else
    {
        cout<<0;
        return 0;
    }
    ll a[3]= {ans[0]-1,ans[0]+1,ans[0]};
    ll t=ans[0]-ans[1];
    t*=-1;
    ll d[5]= {t,t+1,t+2,t-1,t-2};
    int cnt=0;
    int res=0x7f7f7f;
    for(i=0; i<3; i++)
    {
        temp[0]=a[i];
        for(int j=0; j<5; j++)
        {
            if(i!=2)
                cnt++;
            for(int k=1; k<n; k++)
            {
                temp[k]=temp[k-1]+d[j];
                if(ans[k]!=temp[k])
                {
                    if(abs(ans[k]-temp[k])==1)
                        cnt++;
                    else
                    {
                        cnt=0;
                        break;
                    }
                }
            }
            if(cnt!=0)
            {
                res=min(res,cnt);
            }
        }
    }
    if(res!=0x7f7f7f)
        cout<<res;
    else
        cout<<-1;
    return 0;
}
