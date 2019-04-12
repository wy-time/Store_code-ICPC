#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
    char ch = getchar(); x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const int maxn = 500005;
const int INF = 1e9;
int prime[2005];
int num[maxn];
struct st
{
    int _end;
    int next;
};
st edge[maxn * 2];
int head[40005];
int pos[maxn];
int cnt;
int facnum[maxn];
void add(int beg, int end )
{
    edge[++cnt].next = head[beg];
    edge[cnt]._end = end;
    head[beg] = cnt;
}
void get_prime()
{
    int i;
    wfor(i, 2, 2000)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        int j;
        for (j = 1; j <= prime[0] && prime[j]*i < 2000; j++)
        {
            prime[prime[j]*i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void init()
{
    get_prime();
    int i, j;
    facnum[1] = 2;
    wfor(i, 2, maxn)
    {
        int cnt = 0;
        int t = i;
        for (j = 1; j <= prime[0] && prime[j]*prime[j] <= i; j++)
        {
            while (t % prime[j] == 0)
            {
                cnt++;
                t /= prime[j];
            }
        }
        if (t != 1)
        {
            cnt++;
        }
        facnum[i] = cnt;
    }
}
int x[40005];
int y[40005];
int disx[40005];
int disy[40005];
int vis[40005];
int maching[40005];
int dx;
int dy;
int dis;
bool bfs()
{
    queue<int>qu;
    int i;
    dis = INF;
    memset(disx, -1, sizeof(disx));
    memset(disy, -1, sizeof(disy));
    wfor(i, 0, dx)
    {
        if (maching[x[i]] == -1)
        {
            qu.push(x[i]);
            disx[x[i]] = 0;
        }
    }
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        if (disx[u] > dis)
            break;
        for (i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i]._end;
            if (disy[v] == -1)
            {
                disy[v] = disx[u] + 1;
                if (maching[v] == -1)
                    dis = disy[v];
                else
                {
                    disx[maching[v]] = disy[v] + 1;
                    qu.push(maching[v]);
                }
            }
        }
    }
    return dis != INF;
}
int dfs(int beg)
{
    int i;
    for (i = head[beg]; i; i = edge[i].next)
    {
        int v = edge[i]._end;
        if (vis[v] == -1 && disy[v] == disx[beg] + 1)
        {
            vis[v] = 1;
            if (maching[v] != -1 && disy[v] == dis)
            {
                continue;
            }
            if (maching[v] == -1 || dfs(maching[v]))
            {
                maching[v] = beg;
                maching[beg] = v;
                return 1;
            }
        }
    }
    return 0;
}
int slove()
{
    memset(maching, -1, sizeof(maching));
    int ans = 0;
    while (bfs())
    {
        memset(vis, -1, sizeof(vis));
        int i;
        wfor(i, 0, dy)
        {
            if (maching[x[i]] == -1)
                ans += dfs(x[i]);
        }
    }
    return ans;
}
int main()
{
    // std::ios::sync_with_stdio(false);
    // #ifdef test
    // freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    // #endif
    // #ifdef ubuntu
    // freopen("/home/time/debug/debug/in","r",stdin);
    // freopen("/home/time/debug/debug/out","w",stdout);
    // #endif
    int t;
    // cin>>t;
    read(t);
    init();
    int casecnt = 0;
    while (t--)
    {
        dx = 0;
        dy = 0;
        memset(pos, 0, sizeof(pos));
        memset(head, 0, sizeof(head));
        cnt = 0;
        casecnt++;
        int n;
        // cin>>n;
        read(n);
        int i;
        wfor(i, 0, n)
        {
            // cin >> num[i];
            read(num[i]);
            pos[num[i]] = i + 1;
            if (facnum[num[i]] & 1)
            {
                x[dx++] = pos[num[i]];
            } else
            {
                y[dy++] = pos[num[i]];
            }
        }
        wfor(i, 0, n)
        {
            int j;
            for (j = 1; j <= prime[0] && prime[j]*prime[j] <= num[i]; j++)
            {
                if (num[i] % prime[j] == 0)
                {
                    if (pos[num[i] / prime[j]] != 0)
                    {
                        if (facnum[num[i]] & 1)
                        {
                            add(pos[num[i]], pos[num[i] / prime[j]]);
                            //add(pos[num[i] / prime[j]], pos[num[i]]);
                        } else
                        {
                            //add(pos[num[i]], pos[num[i] / prime[j]]);
                            add(pos[num[i] / prime[j]], pos[num[i]]);
                        }
                    } else if (pos[num[i] / (num[i] / prime[j])] != 0)
                    {
                        int temp = num[i] / (num[i] / prime[j]);
                        if (facnum[num[i]] & 1)
                        {
                            add(pos[num[i]], pos[temp]);
                            //add(pos[temp], pos[num[i]]);
                        } else
                        {
                            //add(pos[num[i]], pos[temp]);
                            add(pos[temp], pos[num[i]]);
                        }
                    }
                }
            }
            if (facnum[num[i]] == 1)
            {
                if (pos[1] != 0)
                {
                    //add(1, num[i]);
                    add(num[i], 1);
                }
            }
        }
        int ans = slove();
        // cout << "Case " << casecnt << ": " << n - ans << endl;
        printf("Case %d: %d\n", casecnt, n - ans);
    }
    return 0;
}
