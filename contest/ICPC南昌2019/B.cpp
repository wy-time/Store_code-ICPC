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
const int maxn = 1005;
struct node
{
	int _end;
	int _next;
	int w;
};
node edge[2 * maxn * maxn];
int head[maxn];
int cnt;
void add(int beg, int end, int w)
{
	edge[++cnt]._next = head[beg];
	edge[cnt].w = w;
	edge[cnt]._end =
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
	cin >> t;
	while (t--)
	{
		int n, m, s, k, c;
		cin >> n >> m >> s >> k >> c;
	}
	wfor(i, 0, m)
	{
		int u, v;
		cin >> u >> v;

	}
	return 0;
}
