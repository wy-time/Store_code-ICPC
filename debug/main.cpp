#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 100005;// n(?????o(n*ALP)),???n??
const ll ALP = 26;
int vis[maxn];
struct PAM { // ???????????
     ll next[maxn][ALP];// next??,??Trie?
     ll fail[maxn]; // fail??????
     ll cnt[maxn]; // ????????
     ll num[maxn];
     ll len[maxn]; // ?????
     ll s[maxn]; // ???????
     ll last; //??????????????????add
     ll n; // ???????
     ll p; // ????
     ll newnode(ll w) { // ??????w=??
     for (ll i = 0; i < ALP; i++)
        next[p][i] = 0;
        cnt[p] = 0;
        num[p] = 0;
        len[p] = w;
        return p++;
     }
     void init() {
         p = 0;
         newnode(0);
         newnode(-1);
         last = 0;
         n = 0;
         s[n] = -1; // ???????????????????
         fail[0] = 1;
     }
     ll get_fail(ll x) { // ?KMP??????????????
         while (s[n - len[x] - 1] != s[n]) x = fail[x];
         return x;
     }
     void add(ll c) {
         c -= 'a';
         s[++n] = c;
         ll cur = get_fail(last);
         if (!next[cur][c]) {
             ll now = newnode(len[cur] + 2);
             fail[now] = next[get_fail(fail[cur])][c];
             next[cur][c] = now;
             num[now] = num[fail[now]] + 1;
         }
         last = next[cur][c];
         cnt[last]++;
     }
     void count() {
         // ??????????????
         // ???????cnt,??SAM?parent?
         // ??parent????
         for (ll i = p - 1; i >= 0; i--)
             cnt[fail[i]] += cnt[i];
     }
} pam;
ll sun[maxn];
ll ans=0;
int vis2[maxn];
void slove(ll su,ll now)
{
    vis[now]=1;
    vector<int>pre;
    ll t=pam.fail[now];
    while(t>1&&!vis2[t])
    {
        if(t!=su)
        {
            sun[now]++;
            vis2[t]=1;
            pre.push_back(t);
        }
        t=pam.fail[t];
    }
    sun[now]+=sun[su];
    if(su>1)
    {
        sun[now]++;
        vis2[now]=1;
        pre.push_back(now);
    }
    ans+=sun[now];
    ll j;
    wfor(j,0,ALP)
    {
        if(pam.next[now][j]!=0)
            slove(now,pam.next[now][j]);
    }
    for(auto k:pre)
        vis2[k]=0;
    pre.clear();
}
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
    ll t;
    cin>>t;
    ll casecnt=0;
    while(t--)
    {
        casecnt++;
        memset(vis,0,sizeof(vis));
        memset(vis2,0,sizeof(vis2));
        memset(sun,0,sizeof(sun));
        pam.init();
        string s;
        cin>>s;
        ll len=s.size();
        ll i;
        ans=0;
        wfor(i,0,len)
        {
            pam.add(s[i]);
        }
        wfor(i,2,pam.p)
        {
            if(!vis[i])
                slove(0,i);
        }
        cout<<"Case #"<<casecnt<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
