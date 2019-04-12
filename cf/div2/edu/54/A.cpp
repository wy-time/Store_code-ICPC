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
	string s;
	cin >> s;
	int len = s.size();
	int i;
	int last = 0;
	wfor(i, 0, len)
	{
		if (s[i] < last)
			break;
		last = s[i];
	}
	if (i != len)
	{
		s = s.erase(i - 1, 1);
	} else
	{
		s = s.erase(len - 1, 1);
	}
	cout << s << endl;
	return 0;
}
