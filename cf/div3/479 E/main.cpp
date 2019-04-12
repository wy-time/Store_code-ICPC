#include <iostream>
#include <vector>
using namespace std;
vector <int> ma[200005];
int deg[200005];
int isjudge[200005];
int findcircle(int x,int beg,int last);
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        if(a!=b)
        {
            ma[a].push_back(b);
            ma[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
    }
    int res=0;
    for(i=1; i<=n; i++)
    {
        if(!isjudge[i])
        {
            if(deg[i]==2)
            {
                if(findcircle(i,i,-1))
                    res++;
            }
        }
        isjudge[i]=1;
    }
    cout<<res;
    return 0;
}
int findcircle(int x,int beg,int last)
{
    if(x==beg&&isjudge[x])
        return 1;
    for(auto i=ma[x].begin();i!=ma[x].end();i++)
    {
        if(!isjudge[*i]&&*i!=last)
        {
            isjudge[*i]=1;
            if(deg[*i]==2)
            {
                if(findcircle(*i,beg,x))
                {
                    return 1;
                }
                else
                    return 0;
            }
        }
    }
    return 0;
}/*
#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 11;

int n, m;
int deg[N];
bool used[N];
vector<int> comp;
vector<int> g[N];

void dfs(int v)
{
    used[v] = true;
    comp.push_back(v);

    for (auto to : g[v])
        if (!used[to])
            dfs(to);
}
int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
        ++deg[x];
        ++deg[y];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            comp.clear();
            dfs(i);
            bool ok = true;
            for (auto v : comp) ok &= deg[v] == 2;
            if (ok) ++ans;
        }
    }

    printf("%d\n", ans);

    return 0;
}*/
