#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const int mod = 1e9 + 7;
char s[100005];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	ll ans = 0;
	while (t--)
	{
		cin >> s;
	}
	int len = strlen(s);
	int i;
	wfor(i, 0, len)
	{
		if (s[i] == '0')
		{
			ans++;
			ans %= mod;
		} else if (s[i] == '1')
		{
			ans = ans % mod + (i + 1) * 2 % mod;
			ans %= mod;
		}
	}
	return 0;
}
