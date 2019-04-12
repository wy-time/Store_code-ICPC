#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int edge[105][105];
int cnt[105];
int vis[105];
int ispad2[105][105];
struct st
{
    int num[105];
    int rear;
    st()
    {
        rear = 0;
    }
    void push(int a)
    {
        num[++rear] = a;
    }
    void pop()
    {
        --rear;
    }
};
st v[105];
int nowroom;
int n, m;
int ans = 0x7f7f7f7f;
void slove(int now)
{
    if (nowroom >= ans)
        return;
    if (now > n)
    {
        ans = min(ans, nowroom);
        return ;
    }
    if (nowroom == 0)
    {
        vis[now] = ++nowroom;
        v[nowroom].push(now);
        slove(now + 1);
        return ;
    } else
    {
        if (cnt[now] == 0)
        {
            vis[now] = 1;
            v[1].push(now);
            slove(now + 1);
            return ;
        }
        int i;
        int ispad[105] = {0};
        wfor(i, 1, now)
        {
            if (edge[i][now] == 1)
            {
                ispad[vis[i]] = 1;
                if (!ispad2[now][i])
                {
                    cnt[now]--;
                    ispad2[now][i] = 1;
                }
                continue;
            }
            else
            {
                int t = vis[i];
                if (ispad[t])
                    continue;
                int flag = 1;
                int siz = v[t].rear;
                int j;
                wfor(j, 1, siz + 1)
                {
                    int it = v[t].num[j];
                    if (edge[now][it] == 1)
                    {
                        if (!ispad2[now][it])
                        {
                            cnt[now]--;
                            ispad2[now][it] = 1;
                        }
                        ispad[t] = 1;
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    vis[now] = t;
                    v[t].push(now);
                    if (cnt[now] == 0)
                    {
                        slove(now + 1);
                        return ;
                    }
                    slove(now + 1);
                    v[t].pop();
                    vis[now] = 0;
                } else
                {
                    continue;
                }
            }
        }
        vis[now] = ++nowroom;
        v[nowroom].push(now);
        slove(now + 1);
        if (cnt[now] == 0)
            return;
        v[nowroom].pop();
        vis[now] = 0;
        nowroom--;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    cin >> n >> m;
    int i;
    wfor(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
        cnt[b]++;
        cnt[a]++;
    }
    // ans = 2;
    slove(1);
    cout << ans << endl;
    return 0;
}
