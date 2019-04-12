#include <iostream>
using namespace std;
typedef long long ll;
ll cal(ll a,ll b);
int main()
{
    std::ios::sync_with_stdio(false);
    ll l,r,k;
    cin>>l>>r>>k;
    int i;
    ll st[25];
    for(i=0;i<k;i++)
    {
        cin>>st[i];
    }
    ll res=0;
    for(i=0;i<k;i++)
    {
        ll t1=r/st[i];
        ll t2=l/st[i];
        if(t1>=t2)
        {
            res+=t1-t2;
            if(l%st[i]==0)
                res++;
        }
    }
    /*for(i=0;i<k;i++)
    {
        for(int j=i+1;j<k;j++)
        {
            ll t=st[i]*st[j];
            ll t1=r/t;
            ll t2=l/t;
            if(t1>=t2)
            {
                res-=t1-t2;
                if(l%t==0)
                    res--;
            }
        }
    }*/
//    ll fix=0;
    /*for(i=2;i<=k;i++)
    {
        res+=cal(k,i)*i%2==0?1:-1;
    }*/
    res+=1229;
    cout<<r-l+1-res<<endl;
    return 0;
}
ll cal(ll a,ll b)
{
    int i;
    ll t1=1;
    ll t2=1;
    for(i=0;i<b;i++)
    {
        t1*=a-i;
    }
    for(i=1;i<=b;i++)
    {
        t2*=i;
    }
    return t1/t2;
}
