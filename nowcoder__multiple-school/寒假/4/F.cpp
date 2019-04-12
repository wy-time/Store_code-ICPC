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
const int maxn = 1e5 + 5;
int pre[maxn];
int findx(int x)
{
	int t = x;
	while (t != pre[t])
		t = pre[t];
	int i = x, j;
	while (pre[i] != t)
	{
		j = pre[i];
		pre[i] = t;
		i = j;
	}
	return t;
}
void join(int a, int b)
{
	int a1 = findx(a);
	int b1 = findx(b);
	pre[b1] = a1;
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
	int n, m;
	cin >> n >> m;
	int i;
	wfor(i, 0, n)
	{
		pre[i] = i;
	}
	wfor(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		if (findx(u) == find())
			join(u, v);
	}
	return 0;
}
