#include <string>
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
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	int n;
	string s;
	cin >> n;
	cin >> s;
	int ma[11];
	int i;
	wfor(i, 1, 11)
	{
		cin >> ma[i];
	}
	int len = s.size();
	int flag = 0;
	wfor(i, 0, len)
	{
		if (ma[s[i] - '0'] > s[i] - '0')
		{
			flag = 1;
			s[i] = ma[s[i] - '0'] + '0';
		} else
		{
			if (flag && ma[s[i] - '0'] != s[i] - '0')
				break;
		}
	}
	cout << s << endl;
	return 0;
}
