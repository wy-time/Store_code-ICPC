#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	char s[55], t[55];
	int ans[27] = {0};
	cin >> s >> t;
	int i;
	wfor(i, 0, n)
	{
		ans[s[i] - 'a']++;
	}
	int flag = 1;
	wfor(i, 0, n)
	{
		int tt = t[i] - 'a';
		if (ans[tt] != 0)
			ans[tt]--;
		else
		{
			flag = 0;
			break;
		}
	}
	int res[10005] = {0};
	int cnt = 0;
	int j;
	if (flag == 1)
	{
		wfor(i, 0, n)
		{
			if (s[i] != t[i] && t[i] != '.')
			{
				int pos = strchr(t, s[i]) - t;
				wfor(j, i, pos)
				{
					res[cnt++] = j + 1;
					char ttt = s[j + 1];
					s[j + 1] = s[j];
					s[j] = ttt;
					if (strcmp(t, s) == 0)
					{
						flag = 2;
						break;
					}
				}
				if (flag == 2)
					break;
				mfor(j, pos - 2, i )
				{
					res[cnt++] = j + 1;
					char ttt = s[j + 1];
					s[j + 1] = s[j];
					s[j] = ttt;
					if (strcmp(t, s) == 0)
					{
						flag = 2;
						break;
					}
				}
				if (flag == 2)
					break;
				t[pos] = '.';
				s[pos] = '.';
				i = -1;
			}
		}
	}
	if (flag == 0)
	{
		cout << -1 << endl;
	} else
	{
		cout << cnt << endl;
		if (cnt != 0)
		{
			wfor(i, 0, cnt - 1)
			{
				cout << res[i] << " ";
			}
			cout << res[i] << endl;
		}
	}
	return 0;
}
