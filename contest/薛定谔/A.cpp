#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
ll comb(ll n)
{
	return n * (n - 1) / 2;
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll t;
	cin >> t;
	while (t--)
	{
		map<ll, ll>ma;
		ll n;
		cin >> n;
		ll i;
		ll maxcnt = 0;
		wfor(i, 0, n)
		{
			ll tem;
			cin >> tem;
			if (ma.count(tem) == 0)
			{
				ma.insert(make_pair(tem, 1));
				maxcnt = max(1ll, maxcnt);
			}
			else
			{
				ma[tem]++;
				maxcnt = max(ma[tem], maxcnt);
			}
		}
		map <ll, ll>ma2;
		map<ll, ll>::iterator it;
		it = ma.begin();
		ll temp = (*it).first;
		it++;
		for (; it != ma.end(); it++)
		{
			ll tt = it->first - temp;
			if (ma2.count(tt) == 0)
				ma2.insert(make_pair(tt, 1));
			else
				ma2[tt]++;
			temp = it->first;
		}
		if (maxcnt > 1)
		{
			ll res = 0;
			it = ma.begin();
			for (; it != ma.end(); it++)
			{
				if (it->second > 1)
					res += comb(it->second);
			}
			cout << 0 << " " << res << endl;
		} else
			cout << (ma2.begin())->first << " " << (ma2.begin()->second) << endl;

	}
	return 0;
}
