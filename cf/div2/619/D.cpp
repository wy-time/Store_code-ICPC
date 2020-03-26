#include <iostream>
#include <vector> 
#include <cmath> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
vector<pair<int,char> >ans;
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int n,m,k;
    cin>>n>>m>>k;
    int tot=4*n*m-2*n-2*m;
    if (k>tot)
        cout<<"NO"<<endl;
    else
    {
        int i;
        int now=0;
        wfor(i,0,n-1)
        {
            if(now>=k)
                break;
            if(now+m<=k)
            {
                ans.push_back(make_pair(1,'D'));
                if(m-1>0)
                    ans.push_back(make_pair(m-1,'R'));
                now+=m;
                if(now+m-1<=k)
                {
                    if(m-1>0)
                        ans.push_back(make_pair(m-1,'L'));
                    now+=m-1;
                }else
                {
                    if(k-now>0)
                        ans.push_back(make_pair(k-now,'L'));
                    now=k;
                }
            }else 
            {
                ans.push_back(make_pair(1,'D'));
                now++;
                if(k-now>0)
                    ans.push_back(make_pair(k-now,'R'));
                now=k;
            }
        }
        if(now<k)
        {
            if (now+n-1<=k)
            {
                if(n-1>0)
                    ans.push_back(make_pair(n-1,'U'));
                now+=n-1;
                int i;
                wfor(i,0,m-1)
                {
                    if(now>=k)
                        break;
                    if(now+n<=k)
                    {
                        ans.push_back(make_pair(1,'R'));
                        if(n-1>0)
                            ans.push_back(make_pair(n-1,'D'));
                        now+=n;
                        if(now+n-1<=k)
                        {
                            if(n-1>0)
                                ans.push_back(make_pair(n-1,'U'));
                            now+=n-1;
                        }else
                        {
                            if(k-now>0)
                                ans.push_back(make_pair(k-now,'U'));
                            now=k;
                        }
                    }else
                    {
                        ans.push_back(make_pair(1,'R'));
                        now++;
                        if(k-now>0)
                            ans.push_back(make_pair(k-now,'D'));
                        now=k;
                    }
                }
            }else
            {
                if(k-now>0)
                    ans.push_back(make_pair(k-now,'U'));
                now=k;
            }
        }
        if(now<k)
        {
            ans.push_back(make_pair(k-now,'L'));
        }
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(auto a:ans)
        {
            cout<<a.first<<" "<<a.second<<endl;
        }
    }
    return 0;
}
