#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
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
		int n;
		set <int> st;
		int i;
		cin >> n;
		int res = 0;
		wfor(i, 0, 2 * n)
		{
			int a;
			cin >> a;
			if (st.count(a) != 0)
			{
				res = a;
			} else
			{
				st.insert(a);
			}
		}
		cout << res << endl;
	}
	return 0;
}
