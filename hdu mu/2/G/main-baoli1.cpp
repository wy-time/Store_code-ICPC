#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
#define for(i,j,k) for(i=j;i<k;++i)
#define ffor(i,j,k) for(i=j;i>=k;--i)
const int max_n = 1e5 + 20;
int b[max_n];
int a[max_n];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, q;
	while (cin >> n >> q)
	{
		ll ans = 0;
		memset(a, 0, sizeof(a));
		int i;
		for (i, 1, n + 1)
		{
			cin >> b[i];
		}
		string op;
		int x, y;
		int j;
		for (j, 0, q)
		{
			cin >> op >> x >> y;
			if (op[0] == 'a')
			{
				for (i, x, y + 1)
				{
					a[i] += 1;
				}
			} else
			{
				for (i, x, y + 1)
				{
					ans += a[i] / b[i];
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}
