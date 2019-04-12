#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	ll n, m, q;
	cin >> n >> m >> q;
	string s;
	char t[1005];
	cin >> s;
	cin >> t;
	ll ans[1005] = {0};
	ll pos = s.find(t);
	while (pos != string::npos)
	{
		ans[pos + 1] = 1;
		// ans[pos + m - 1] = 1;
		pos = s.find(t, pos + 1);
	}
	ll sum[1005] = {0};
	sum[1] = ans[1];
	ll i;
	wfor(i, 2, 1005)
	{
		sum[i] = sum[i - 1] + ans[i];
	}
	while (q--)
	{
		ll l, r;
		cin >> l >> r;
		ll res = 0;
		if (r + 1 >= m)
		{
			res = sum[r - m + 1] - sum[l - 1];
		}
		if (res < 0)
			res = 0;
		cout << res << endl;
	}
	return 0;
}
