#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const int maxn = 1000005;
// struct st
// {
// 	int father;
// 	int deep;
// 	st() {}
// 	st(int a, int b)
// 	{
// 		father = a;
// 		deep = b;
// 	}
// };
vector<int> v[maxn];
int vis[maxn];
int len[maxn];
// struct EGDE
// {
// 	int the_end;
// 	int w;
// 	int next;
// };
// EGDE edge[maxn];
// int head[maxn];
// void add(int beg, int the_end, int w);
int cnt;
int res_max;
// void dfs(int beg, int res);
int slove(int t);
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	int i;
	wfor(i, 0, n - 1)
	{
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	int j;
	wfor(i, 1, n + 1)
	{
		int len1 = v[i].size();
		wfor(j, 0, len1)
		{
			if (!vis[v[i][j]])
				len[i]++;
		}
		vis[i] = 1;
	}
	memset(vis, 0, sizeof(vis));
	int len1 = v[1].size();
	wfor(i, 0, len1)
	{
		vis[1] = 1;
		res_max = max(res_max, slove(v[1][i]));
	}
	// memset(vis, 0, sizeof(vis));
	// wfor(i, 1, n + 1)
	// {
	// 	int len1 = v[i].size();
	// 	wfor(j, 0, len1)
	// 	{
	// 		if (!vis[v[i][j]])
	// 			add(i, v[i][j], len[v[i][j]]);
	// 	}
	// 	vis[i] = 1;
	// }
	// dfs(1, 0);
	cout << res_max + 1 << endl;
	return 0;
}
int slove(int t)
{
	int len1 = v[t].size();
	int i;
	vis[t] = 1;
	wfor(i, 0, len1)
	{
		if (!vis[v[t][i]])
		{
			len[t] += slove(v[t][i]);
		}
	}
	return len[t];
}
// void add(int beg, int the_end, int w)
// {
// 	edge[++cnt].next = head[beg];
// 	edge[cnt].w = w;
// 	edge[cnt].the_end = the_end;
// 	head[beg] = cnt;
// }
// void dfs(int beg, int res)
// {
// 	int i;
// 	if (head[beg] == 0)
// 	{
// 		res_max = max(res_max, res);
// 		return ;
// 	}
// 	for (i = head[beg]; i != 0; i = edge[i].next)
// 	{
// 		res += edge[i].w;
// 		dfs(edge[i].the_end, res);
// 		res -= edge[i].w;
// 	}
// }