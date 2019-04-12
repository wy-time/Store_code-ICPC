#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int i;
	wfor(i, 0, t)
	{
		ll a;
		cin >> a;
		cout << a*(a - 1) / 2 << endl;
	}
	return 0;
}
