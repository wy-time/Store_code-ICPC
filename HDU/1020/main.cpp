#include <iostream>
#include <cstdio>
#include <string>
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
	int n;
	cin >> n;
	int i;
	wfor(i, 0, n)
	{
		string s;
		// string res = "";
		cin >> s;
		int len = s.size();
		int j;
		char cmp = s[0];
		int cnt = 0;
		wfor(j, 0, len + 1)
		{
			if (cmp == s[j])
				cnt++;
			else
			{
				if (cnt != 1)
					cout << cnt;
				// res += ((char)cnt + '0');
				cout << cmp;
				// res += cmp;
				cnt = 1;
				cmp = s[j];
			}
		}
		cout << endl;
	}
	return 0;
}
