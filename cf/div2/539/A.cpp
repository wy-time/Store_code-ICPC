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
	int n, v;
	cin >> n >> v;
	int need = n - 1;
	int now = 0;
	int cost = 1;
	int ans = 0;
	if (need >= v)
	{
		while (need)
		{
			need -= v - now;
			ans += cost * (v - now);
			now += v - now;
			cost++;
			now--;
		}
		cout << ans << endl;
	} else
		cout << need << endl;
	return 0;
}
