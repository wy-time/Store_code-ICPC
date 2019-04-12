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
// ll cal(ll now, ll n);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll n, d;
	cin >> n >> d;
	if (n == 1 || n == 0 || d == 0)
		cout << 0 << endl;
	else
	{
		ll right = 0;
		ll left = (2ll << (n - 2)) - 1;
		if (n - 2 - d >= 0)
		{
			if ()
			}
		cout << left - right << endl;
	}
	return 0;
}
// ll cal(ll now, ll n)
// {
// 	ll ans = 0;
// 	if (now <= n - d)
// 	{
// 		ans++;
// 		ans += cal(now + 1, n);
// 		ans += cal(now + 1, n - d);
// 	}
// 	return ans;
// }
