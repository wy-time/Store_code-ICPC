#include <iostream>
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
const int maxn = 1e6 + 5;
vector<int> G[maxn];
int dep[maxn];
ll maxnum;
void dfs(int now, int dep)
{
	dep[now] = dep;
	maxnum = max(maxnum, dep);
	for (v : G[now])
	{
		dfs(v, dep + 1);
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
	int n;
	cin >> n;
	int i;
	wfor(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	wfor()
	return 0;
}