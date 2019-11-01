#include <iostream>
#include <algorithm> 
#include <vector> 
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
vector<pair<int,int>>no;
vector<pair<int,int>>ok;
const int maxn=10005;
int num[maxn];
int vis[maxn];
int _map[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    int i;
    int cnt=0;
    int cant=0;
    wfor(i,0,m)
    {
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1)
        {
            ok.push_back(make_pair(l,r));
        }else
            no.push_back(make_pair(l,r));
    }
    sort(ok.begin(),ok.end());
    int last=0;
    for(auto k:ok)
    {
        if(k.first>last)
            cnt++;
        wfor(i,k.first,k.second+1)
        {
            num[i]=10000;
            vis[i]=cnt;
            _map[cnt]=num[i];
        }
        last=max(k.second,last);
    }
    sort(no.begin(),no.end());
    for(auto k:no)
    {
        int flag=0;
        if(vis[k.first]==0)
        {
            cnt++;
            vis[k.first]=cnt;
            _map[cnt]=10000;
        }
        wfor(i,k.first+1,k.second+1)
        {
            if(vis[i]==0)
            {
                cnt++;
                vis[i]=cnt;
                _map[cnt]=_map[vis[i-1]]-1;
                flag=1;
            }
            if(_map[vis[i]]<_map[vis[i-1]])
                flag=1;
            if(vis[i]!=vis[i-1]&&flag==0)
            {
                _map[vis[i]]=_map[vis[i-1]]-1;
                flag=1;
            }
            if(flag)
                break;
        }
        if(flag==0)
            cant=1;
    }
    if(cant==1)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        wfor(i,1,n+1)
        {
            if(_map[vis[i]]!=0)
                cout<<_map[vis[i]]<<" ";
            else
                cout<<1<<" ";
        }
    }
    return 0;
}
