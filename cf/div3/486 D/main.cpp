#include <iostream>
#include<map>
#include<cstdio>
using namespace std;
typedef long long ll;
ll ans[3];
typedef map<ll,ll>map1;
map1 ma;
int main()
{
    std::ios::sync_with_stdio(false);
    /*if(freopen("d.in","r+",stdin)==NULL)
    {
        cout<<"FUCK"<<endl;
        return 0;
    }*/
    ll n=1000;
    cin>>n;
    ll i;
    for(i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        ma.insert(make_pair(t,1));
    }
    ll minx=(ma.begin())->first;
    ll maxx=(--ma.end())->first;
    ll res=0;
    for(auto it=ma.begin();it!=ma.end();it++)
    {
        if(res==3)
            break;
        ll temp=(*it).first;
        for(i=0;;i++)
        {
            ll t=temp-(1LL<<i);
            if(ma.count(t))
            {
                if(res<2)
                {
                    res=2;
                    ans[0]=temp;
                    ans[1]=t;
                }
                if(ma.count(t-(1LL<<i)))
                {
                    res=3;
                    ans[0]=temp;
                    ans[1]=t;
                    ans[2]=t-(1LL<<i);
                    break;
                }
            }
            if(t<minx)
                break;
        }
        if(res==3)
            break;
        for(i=0;;i++)
        {
            ll t=temp+(1LL<<i);
            if(ma.count(t))
            {
                if(res<2)
                {
                    res=2;
                    ans[0]=temp;
                    ans[1]=t;
                }
                if(ma.count(t+(1LL<<i)))
                {
                    res=3;
                    ans[0]=temp;
                    ans[1]=t;
                    ans[2]=t+(1LL<<i);
                    break;
                }
            }
            if(t>maxx)
                break;
        }
    }
    if(res==0)
    {
        //printf("%d\n%lld",1,maxx);
        cout<<1<<endl<<maxx<<endl;
    }else
    {
        cout<<res<<endl;
        for(i=0;i<res-1;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<ans[i]<<endl;
    }
    return 0;
}
