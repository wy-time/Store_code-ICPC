#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const ll mod = 1e9 + 7;
ll ksm(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}
ll fac[3000];
ll inv[3000];
void init()
{
	ll i;
	fac[0] = inv[0] = 1;
	fac[1] = inv[1] = 1;
	wfor(i, 2, 3000)
	{
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[2999] = ksm(fac[2999], mod - 2);
	mfor(i, 2998, 2)
	{
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}
}
ll comb(ll a, ll b)
{
	return fac[a] * inv[b] % mod * inv[a - b] % mod;
}
int main()
{
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
// 	freopen("/home/time/debug/debug/in", "r", stdin);
// 	freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
	char s[3000];
	// cin >> s;
	scanf("%s", s);
	vector<int>v[10];
	int len = strlen(s);
	int i;
	wfor(i, 0, len)
	{
		v[s[i] - '0'].push_back(i);
	}
	init();
	int m;
	// cin >> m;
	read(m);
	while (m--)
	{
		ll ans = 0;
		int n;
		int t;
		// cin >> n >> t;
		read(n);
		read(t);
		if (n == 1)
		{
			// cout << 0 << endl;
			printf("0\n");
			continue;
		}
		int x, y;
		y = t % 10;
		t /= 10;
		x = t;
		int pos = 0;
		while (1)
		{
			pos = lower_bound(v[x].begin() + pos, v[x].end(), n - 2) - v[x].begin();
			if (pos >= v[x].size())
				break;
			ll pos2 = lower_bound(v[y].begin(), v[y].end(), v[x][pos]) - v[y].begin();
			if (pos2 >= v[y].size())
				break;
			if (v[y][pos2] == v[x][pos])
				pos2++;
			if (pos2 >= v[y].size())
				break;
			ans = (ans + comb(v[x][pos], n - 2) * (v[y].size() - pos2)) % mod;
			pos++;
		}
		// cout << ans << endl;
		printf("%lld\n", ans);
	}
	return 0;
}