#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 2005;
const int INF = 1e9;
struct EDGE
{
	int first;
	int flow;
	int cost;
	int _end;
	int next;
};
int num[maxn];
int head[3 * maxn];
EDGE edge[maxn* maxn];
int cnt = -1;
void add(int beg, int _end, int flow, int cost)
{
	edge[++cnt].next = head[beg];
	edge[cnt]._end = _end;
	edge[cnt].flow = flow;
	edge[cnt].cost = cost;
	edge[cnt].first = beg;
	head[beg] = cnt;
}
int vis[3 * maxn];
int dis[3 * maxn];
int pre[3 * maxn];
int sum = 0;
int spfa(int beg, int _end)
{
	queue<int>qu;
	memset(vis, 0, sizeof(vis));
	fill(dis, dis + 3*maxn, INF);
	qu.push(beg);
	vis[beg] = 1;
	dis[beg] = 0;
	while (!qu.empty())
	{
		int temp = qu.front();
		qu.pop();
		vis[temp] = 0;
		for (int i = head[temp]; i != -1; i = edge[i].next)
		{
			int v = edge[i]._end;
			if (edge[i].flow <= 0) continue;
			if (edge[i].cost + dis[temp] < dis[v])
			{
				dis[v] = edge[i].cost + dis[temp];
				pre[v] = i;
				if (!vis[v])
				{
					qu.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	if (dis[_end] == INF)
		return 0;
	return 1;
}
int mfmc(int beg, int _end)
{
	int ans = 0;
	memset(pre, -1, sizeof(pre));
	while (spfa(beg, _end) == 1)
	{
		int t = pre[_end];
		int flow = INF;
		while (t != -1)
		{
			flow = min(edge[t].flow, flow);
			t = pre[edge[t].first];
		}
		t = pre[_end];
		while (t != -1)
		{
			edge[t].flow -= flow;
			edge[t ^ 1].flow += flow;
			ans += flow * edge[t].cost;
			t = pre[edge[t].first];
		}
		sum += flow;
	}
	return ans;
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
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        int n;
        cin >> n>>k;
        int i;
        cnt=-1;
        memset(head, -1, sizeof(head));
        wfor(i,0,n)
        {
            cin>>num[i];
            add(0,i+1,1,0);
            add(i+1,0,0,0);
            add(i+1,2000+i+1,1,0);
            add(2000,i+1,0,0);
            add(2000+i+1,4001,1,-num[i]);
            add(4001,2000+i+1,0,num[i]);
        }
        int j;
        wfor(i,0,n)
        {
            wfor(j,i+1,n)
            {
                if(num[i]<=num[j])
                {
                    add(i+2001,j+1,1,-num[i]);
                    add(j+1,i+2001,0,num[i]);
                }
            }
        }
        add(4002,0,k,0);
        add(0,4002,0,0);
        ll ans=mfmc(4002,4001);
        cout<<-ans<<endl;
    }
    return 0;
}

