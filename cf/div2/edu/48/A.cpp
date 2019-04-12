#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll i;
	ll sum = 0;
	ll sump = 0;
	wfor(i, 0, n)
	{
		ll a;
		cin >> a;
		sum += a;
		ll out = sum / m;
		out -= sump;
		cout << out << " ";
		sump += out;
	}
	return 0;
}
