#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 1e5 + 5;
struct node
{
	ll num;
	ll id;
	bool operator <(const node &other)const
	{
		return num < other.num;
	}
};
node num[maxn];
ll chose[maxn];
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
	ll t;
	cin >> t;
	ll casecnt = 0;
	while (t--)
	{
		casecnt++;
		cout << "Case " << casecnt << ": ";
		ll n;
		cin >> n;
		ll i;
		wfor(i, 0, n)
		{
			cin >> num[i].num;
			num[i].id = i;
			chose[i] = 0;
		}
		sort(num, num + n);
		ll cnt1 = 1, cnt2 = 1, need = 1;
		ll flag = 1;
		wfor(i, 0, n)
		{
			while (cnt1 + cnt2 <= n - i && need < num[i].num)
			{
				cnt1 *= 2ll, cnt2 *= 2ll, need++;
			}
			if (cnt1 + cnt2 > n - i)
			{
				flag = 0;
				break;
			}
			if (cnt1 > 0)
			{
				cnt1--;
				chose[num[i].id] = 1;
			} else
				cnt2--;
			if (cnt1 == 0 && cnt2 == 0)
				break;
		}
		if (flag == 0 || cnt1 > 0 || cnt2 > 0)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			wfor(i, 0, n)
			cout << chose[i];
			cout << endl;
		}
	}
	return 0;
}
