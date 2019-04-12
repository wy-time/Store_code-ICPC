#include <iostream>
#include <cstdio>
#include <algorithm>
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
struct rule
{
	bool operator()(const string &a, const string &b)
	{
		return a.size() < b.size();
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	string s[205];
	while (t--)
	{
		int n;
		cin >> n;
		int i;
		wfor(i, 0, n)
		{
			cin >> s[i];
		}
		sort(s, s + n, rule());
		string tem = s[0];
		int flag = 1;
		wfor(i, 1, n)
		{
			if (s[i].find(tem) == string::npos)
			{
				flag = 0;
				break;
			}
			tem = s[i];
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
