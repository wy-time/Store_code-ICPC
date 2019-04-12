#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
ll ans[200005];
int main()
{
	std::ios::sync_with_stdio(false);
	ll n, k, m;
	cin >> n >> k >> m;
	ll cnt = 0;
	int i;
	if (m % (n - 1) == 0)
	{
		cnt = m / (n - 1);
		wfor(i, 0, cnt)
		{
			if (i % 2 == 0)
				cout << n << " ";
			else
				cout << 1 << " ";
		}
	} else
	{

	}
	return 0;
}
