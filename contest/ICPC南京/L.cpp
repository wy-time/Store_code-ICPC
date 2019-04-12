#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, t, n, m, k, d[100000 + 10][11];
const ll INF = 0x7f7f7f7f7f;
typedef pair<ll, ll> pii;
vector<pii> G[200000 + 10];
bool visit[100000 + 10][11];
struct Node
{
    ll id;
    ll level;
    ll dis;
    Node(ll a, ll b, ll c)
    {
        id = a, level = b, dis = c;
    }
};
struct rule
{
    bool operator()(const Node a, const Node b)
    {
        return a.dis > b.dis;
    }
};
void dij();
int main()
{
    ll a, b, c;
    int case_c;
    scanf("%d", &case_c);
    while (case_c--)
    {
        scanf("%lld%lld%lld", &n, &m, &k);
        s = 0; t = n - 1;
        for (int i = 0; i < n; i++)
            G[i].clear();
        for (int i = 0; i < m; i++)
        {
            scanf("%lld%lld%lld", &a, &b, &c);
            a -= 1;
            b -= 1;
            G[a].push_back(make_pair(b, c));
            //G[b].push_back(make_pair(a, c));
        }
        memset(visit, 0, sizeof(visit));
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j <= k; j++)
                d[i][j] = INF;
        dij();
        ll ans = d[t][0];
        for (ll i = 0; i <= k; i++)
        {
            ans = min(ans, d[t][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
void dij()
{
    priority_queue<Node, vector<Node>, rule> pq;
    d[s][0] = 0;
    pq.push(Node(s, 0, 0));
    while (!pq.empty())
    {
        Node temp = pq.top();
        pq.pop();
        ll x = temp.id;
        ll leve = temp.level;
        if (visit[x][leve] == true)
            continue;
        else
        {
            visit[x][leve] = true;
            vector<pii>::iterator it;
            for (it = G[x].begin(); it != G[x].end(); it++)
            {
                ll y = (*it).first;
                ll u = (*it).second;
                if (u + d[x][leve] < d[y][leve])
                {

                    d[y][leve] = u + d[x][leve];
                    pq.push(Node(y, leve, d[y][leve]));
                }
                if (leve < k)
                {
                    if (d[x][leve] < d[y][leve + 1])
                    {
                        d[y][leve + 1] = d[x][leve];
                        pq.push(Node(y, leve + 1, d[y][leve + 1]));
                    }
                }
            }
        }
    }
}
