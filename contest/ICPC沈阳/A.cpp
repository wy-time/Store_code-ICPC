#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int ans[100005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a, b;
		cin >> a >> b;
		int i;
		wfor(i, 0, a)
		{
			cin >> ans[i];
		}
		sort(ans, ans + a);
		int last = 1;
		wfor(i, 0, a)
		{
			int t = ans[i] - last;
			int _max = t * m;
			int _min = t;
			if (_max + (last - 1) >= n)
			{
				cout << "Ritsuka" << endl;
				break;
			} else if (n - _min - (last + 1) < m)
			{
				cout << "Gudako" << endl;
				break;
			}
			last++;
		}
	}
	return 0;
}
