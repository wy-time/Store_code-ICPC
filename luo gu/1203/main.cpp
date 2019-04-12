#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int len = n;
	s += s;
	string t = s;
	int i;
	int dpl[800] = {0};
	int dpr[800] = {0};
	mfor(i, 2 * len - 1, 1)
	{
		if (s[i] == 'w' || s[i - 1] == 'w' || s[i] == s[i - 1])
		{
			dpr[i - 1] = dpr[i] + 1;
			if (s[i - 1] == 'w')
				s[i - 1] = s[i];
		} else
		{
			if (t[i] == 'w')
			{
				dpr[i - 1] = 1;
			}
		}
	}
	s = t;
	wfor(i, 0, 2 * len - 1)
	{
		if (s[i] == 'w' || s[i + 1] == 'w' || s[i + 1] == s[i])
		{
			dpl[i + 1] = dpl[i] + 1;
			if (s[i + 1] == 'w')
				s[i + 1] = s[i];
		} else
		{
			if (t[i] == 'w')
				dpl[i + 1] =  1;
		}
	}
	int ans = 0;
	ans = max(ans, dpr[0] + dpl[2 * len - 1] + 2);
	wfor(i, 1, len)
	{
		ans = max(ans, dpr[i] + dpl[i + len - 1] + 2);
	}
	if (ans > n)
		ans = n;
	cout << ans << endl;
	return 0;
}
