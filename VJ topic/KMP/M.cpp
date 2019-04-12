#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	int flag = 1;
// 	if (ch == '-')
// 		flag = -1;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// 	x *= flag;
// }
int _next[105];
void cal_next(string s);
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
		cin >> n;
		int i;
		string s[105];
		int ans = 0;
		wfor(i, 0, n)
		{
			cin >> s[i];
		}
		int len = s[0].size();
		int j, kk, l;
		string temp = s[0];
		wfor(i, 0, len)
		{
			wfor(l, 1, len - i + 1)
			{
				s[0] = temp.substr(i, l);
				cal_next(s[0]);
				int flag = 0;
				wfor(j, 1, n)
				{
					int lent = s[j].size();
					int k = -1;
					int flag2 = 0;
					wfor(kk, 0, lent)
					{
						while (k > -1 && s[0][k + 1] != s[j][kk])
						{
							k = _next[k];
						}
						if (s[0][k + 1] == s[j][kk])
						{
							++k;
						}
						if (k == l - 1)
						{
							flag++;
							flag2 = 1;
							break;
						}
					}
					if (flag2 == 0)
					{
						k = -1;
						mfor(kk, lent - 1, 0)
						{
							while (k > -1 && s[0][k + 1] != s[j][kk])
							{
								k = _next[k];
							}
							if (s[0][k + 1] == s[j][kk])
							{
								++k;
							}
							if (k == l - 1)
							{
								flag++;
								flag2 = 1;
								break;
							}
						}
					}
					if (flag2 == 0)
						break;
				}
				if (flag == n - 1)
					ans = max(ans, l);
				else
					break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
void cal_next(string s)
{
	int k = -1;
	int len = s.size();
	int i;
	_next[0] = -1;
	wfor(i, 1, len)
	{
		while (k > -1 && s[i] == s[k + 1])
			k = _next[k];
		if (s[i] == s[k + 1])
			++k;
		_next[i] = k;
	}
}