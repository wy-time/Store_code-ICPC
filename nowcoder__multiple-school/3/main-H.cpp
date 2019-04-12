#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
bool prime[10000005];
typedef  struct
{
	ll pri;
	ll num;
} NODE;
NODE node[700000];
int main()
{
	std::ios::sync_with_stdio(false);
	memset(prime, true, sizeof(prime));
	ll n;
	cin >> n;
	const int max_n = n + 100;
	prime[0] = prime[1] = false;
	ll i;
	for (i = 2; i <= max_n; i++)
	{
		if (prime[i])
		{
			for (ll j = i * 2; j <= max_n; j += i)
			{
				prime[j] = false;
			}
		}
	}
	ll cnt = 0;
	wfor(i, 2, n + 1)
	{
		if (prime[i])
		{
			node[cnt].pri = i;
			node[cnt++].num = n / i;
		}
	}
	ll res = 0;
	wfor(i, 0, cnt)
	{
		res += node[i].num * i * 2;
	}
	cout << res << endl;
	return 0;
}
