#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
char ma[2009][2009];
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		ll i, j;
		wfor(i, 0, n )
		wfor(j, 0, m )
		{
			cin >> ma[i][j];
		}
		ll minr = n / 2 ;
		ll minl = m / 2 ;
		ll resr = 0;
		ll resl = 0;
		ll flag = 0;
		wfor(i, 0, n)
		{
			if (flag == -1 )
				break;
			wfor(j, 0, m)
			{
				if (flag == -1)
					break;
				if (ma[i][j] != ma[i][m - 1 - j] || ma[i][j] != ma[n - 1 - i][j])
				{
					if (i == 0 || j == 0)
					{
						flag = -1;
						break;
					}
					flag = 1;
					resr = max(m - 2 * j, resr);
					resl = max(n - 2 * i, resl);
				}
			}
		}
		//cout << resr << resl << endl;
		if (flag == -1)
		{
			cout << 0 << endl;
		} else if (flag == 0)
		{
			cout << ((n - 2) / 2)*((m - 2) / 2) << endl;
		} else
		{
			cout << ((m - 2 - resr) / 2 + 1)*((n - 2 - resl) / 2 + 1) << endl;
		}
	}
	return 0;
}
