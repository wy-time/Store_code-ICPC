#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
void cal_next(string s);
int _next[70];
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
		int m;
		cin >> m;
		string s[12];
		int i;
		wfor(i, 0, m)
		{
			cin >> s[i];
		}
		int j, kk, l;
		int len = s[1].size();
		string ans = "";
		int k = -1;
		string temp = s[0];
		wfor(i, 0, len)
		{
			s[0] = temp;
			s[0] = s[0].substr(i);
			cal_next(s[0]);
			wfor(l, 0, len - i)
			{
				int flag = 0;
				wfor(kk, 1, m)
				{
					k = - 1;
					wfor(j, 0, len)
					{
						while (k > -1 && s[0][k + 1] != s[kk][j])
							k = _next[k];
						if (s[0][k + 1] == s[kk][j])
							++k;
						if (k == l)
						{
							flag++;
							break;
						}
					}
				}
				if (flag == m - 1)
				{
					0
					if ((int)ans.size() < l + 1)
						ans = s[0].substr(0, l + 1);
					else if ((int)ans.size() == l + 1)
						ans = min(s[0].substr(0, l + 1), ans);

				}
				else
					break;
			}
		}
		if (ans.size() >= 3)
			cout << ans << endl;
		else
			cout << "no significant commonalities" << endl;
	}
	return 0;
}
void cal_next(string s)
{
	int i;
	int len = s.size();
	int k = -1;
	_next[0] = -1;
	wfor(i, 1, len)
	{
		if (k > -1 && s[i] != s[k + 1])
			k = _next[k];
		if (s[i] == s[k + 1])
			++k;
		_next[i] = k;
	}
}