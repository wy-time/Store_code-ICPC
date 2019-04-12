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
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		if (s.size() == 1 && s[0] == '1')
			cout << "Arena of Valor" << endl;
		else if (s.size() == 1 && s[0] == '2')
			cout << "Clash Royale" << endl;
		else
		{
			int len = s.size();
			if (s[len - 1] == '')
			}
	}
	return 0;
}
