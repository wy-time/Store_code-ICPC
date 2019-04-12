#include <iostream>
#include <cstdio>
#include <cstring>
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
	int ans[4][15];
	int ma[256];
	ma['J'] = 11;
	ma['Q'] = 12;
	ma['K'] = 13;
	while (t--)
	{
		memset(ans, 0, sizeof(ans));
		char s[4];
		int i;
		wfor(i, 0, 51)
		{
			cin >> s;
			if (s[1] >= '0' && s[1] <= '9')
			{
				if (s[2] == '\0')
					ans[s[0] - 'A'][s[1] - '0'] = 1;
				else
					ans[s[0] - 'A'][10] = 1;
			} else
			{
				int t = ma[s[1]];
				ans[s[0] - 'A'][t] = 1;
			}
		}
		int j;
		int res1, res2;
		wfor(i, 0, 4)
		{
			wfor(j, 1, 14)
			{
				if (ans[i][j] == 0)
				{
					res1 = i;
					res2 = j;
					break;
				}
			}
		}
		cout << (char)(res1 + 'A');
		if (res2 >= 10)
		{
			if (res2 == 0)
				cout << 10 << endl;
			else if (res2 == 11)
				cout << "J" << endl;
			else if (res2 == 12)
				cout << "Q" << endl;
			else
				cout << "K" << endl;
		} else
			cout << (char)(res2 + '0') << endl;
	}
	return 0;
}
