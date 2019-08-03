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
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 100005;// n(空间复杂度o(n*ALP)),实际开n即可
const ll ALP = 26;
int vis[maxn];
struct PAM { // 每个节点代表一个回文串
     ll next[maxn][ALP];// next指针,参照Trie树
     ll fail[maxn]; // fail失配后缀链接
     ll cnt[maxn]; // 此回文串出现个数
     ll num[maxn];
     ll len[maxn]; // 回文串长度
     ll s[maxn]; // 存放添加的字符
     ll last; //指向上一个字符所在的节点，方便下一次add
     ll n; // 已添加字符个数
     ll p; // 节点个数
     ll newnode(ll w) { // 初始化节点，w=长度
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
         s[n] = -1; // 开头放一个字符集中没有的字符，减少特判
         fail[0] = 1;
     }
     ll get_fail(ll x) { // 和KMP一样，失配后找一个尽量最长的
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
         // 最后统计一遍每个节点出现个数
         // 父亲累加儿子的cnt,类似SAM中parent树
         // 满足parent拓扑关系
         for (ll i = p - 1; i >= 0; i--)
             cnt[fail[i]] += cnt[i];
     }
} pam;
ll sun[maxn];
ll ans=0;
int vis2[maxn];
void slove(ll su,ll now)
{
    vector<int>pre;
    ll t=pam.fail[now];
    while(t>1&&!vis[t])
    {
        sun[now]++;
        vis[t]=1;
        pre.push_back(t);
        t=pam.fail[t];
    }
    sun[now]+=sun[su];
    ans+=sun[now];
    if(now>1)
    {
        sun[now]++;
        vis[now]=1;
        pre.push_back(now);
    }
    ll j;
    wfor(j,0,ALP)
    {
        if(pam.next[now][j]!=0)
            slove(now,pam.next[now][j]);
    }
    for(auto k:pre)
        vis[k]=0;
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
        /*wfor(i,2,pam.p)
        {
            if(!vis[i])
                slove(0,i);
        }*/
        slove(0,0);
        slove(1,1);
        cout<<"Case #"<<casecnt<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
