#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	int i;
	int ans[1005];
	int vis[1005] = {0};
	wfor(i, 1, n + 1)
	{
		cin >> ans[i];
	}
	int res[1005];
	wfor(i, 1, n + 1)
	{
		memset(vis, 0, sizeof(vis));
		int j = i;
		vis[j]++;
		while (vis[j] != 2)
		{
			j = ans[j];
			vis[j]++;
		}
		res[i] = j;
	}
	wfor(i, 1, n)
	{
		cout << res[i] << " ";
	}
	cout << res[i] << endl;
	return 0;
}
