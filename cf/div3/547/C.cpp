#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 2e5 + 5;
ll num[maxn];
ll ans[maxn];
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
	ll n;
	cin >> n;
	ll i;
	wfor(i, 0, n - 1)
	{
		cin >> num[i];
	}
	ll a = 1;
	ll co = 0;
	ll last = 0;
	wfor(i, 0, n - 1)
	{
		a++;
		co += num[i] + last;
		last = num[i] + last;
	}
	ll sum = (n * n + n) / 2;
	sum -= co;
	set<int>st;
	if (sum % a != 0 || sum <= 0 || sum / a > n || sum / a < 1)
		cout << -1 << endl;
	else
	{
		a = sum / a;
		st.insert(a);
		int cnt = 0;
		ans[cnt++] = a;
		// cout << a << " ";
		ll la = a;
		int flag = 1;
		wfor(i, 0, n - 1)
		{
			// cout << num[i] + la << " ";
			if (st.count(num[i] + la) == 0 && num[i] + la <= n && num[i] + la >= 1)
			{
				st.insert(num[i] + la);
				ans[cnt++] = num[i] + la;
			}
			else
			{
				flag = 0;
				break;
			}
			la = num[i] + la;
		}
		if (flag == 0)
			cout << -1 << endl;
		else
		{
			wfor (i, 0, cnt)
			{
				cout << ans[i] << " ";
			}
		}
	}
	return 0;
}
