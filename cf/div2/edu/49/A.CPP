#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	char s[105];
	while (t--)
	{
		int n;
		cin >> n;
		cin >> s;
		int i;
		int flag = 1;
		wfor(i, 0, n / 2)
		{
			if (s[i] - 1 != s[n - i - 1] - 1 && s[i] + 1 != s[n - i - 1] + 1 && s[i] + 1 != s[n - i - 1] - 1 && s[i] - 1 != s[n - i - 1] + 1)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
