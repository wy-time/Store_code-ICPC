#include <iostream>
#include <cstdio>
#include <cstring>
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
ll ans[maxn];
int vis[maxn];
int main()
{
	// std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		ans[0] = 0;
		int i;
		int cnt = 1;
		vis[0] = 1;
		wfor(i, 1, maxn)
		{
			ans[i] = (ans[i - 1] + n) % m;
			if (!vis[ans[i]])
			{
				vis[ans[i]] = 1;
				cnt++;
			}
			else
				break;
		}
		printf("%10d%10d    ", n, m);
		if (cnt == m)
			printf("%s\n", "Good Choice");
		else
			printf("%s\n", "Bad Choice");
		printf("\n");
	}
	return 0;
}
