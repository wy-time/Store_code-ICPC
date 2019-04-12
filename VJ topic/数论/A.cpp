#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(ll &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const ll maxn = 5e6 + 5;
ll euler[maxn];
void cal_euler();
int main()
{
	// std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
	// freopen("F:\\Desktop\\question\\out.txt", "w", stdout);
#endif
	ll t;
	// cin >> t;
	read(t);
	ll case_cnt = 0;
	cal_euler();
	// cout << euler[5000000] << endl;
	// int i;
	// wfor(i, 2, maxn)
	// {
	// 	cout << i << "  " << euler[i] << endl;
	// }
	while (t--)
	{
		case_cnt++;
		ll a, b;
		// cin >> a >> b;
		read(a); read(b);
		ll res = euler[b] - euler[a - 1];
		printf("Case %llu: %llu\n", case_cnt, res);
		// cout << "Case " << case_cnt << ": " << res << endl;
	}
	return 0;
}
void cal_euler()
{
	euler[1] = 1;
	ll i, j;
	wfor(i, 2, maxn)
	{
		euler[i] = i;
	}
	wfor(i, 2, maxn)
	{
		if (euler[i] == i)
		{
			for (j = i; j < maxn; j += i)
				euler[j] = euler[j] / i * (i - 1);
		}
	}
	wfor(i, 2, maxn)
	{
		euler[i] = euler[i - 1] + euler[i] * euler[i];
	}
}