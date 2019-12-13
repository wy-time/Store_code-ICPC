#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
ll can[26];
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
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll i;
	wfor(i, 0, k)
	{
		char c;
		cin >> c;
		can[c - 'a'] = 1;
	}
	ll len = s.size();
	ll tot = len * (len + 1) / 2;
	ll pre = 0;
	wfor(i, 0, len)
	{
		if (can[s[i] - 'a'] == 0)
		{
			tot -= (i + 1 - pre) * (len - i);
			pre = i + 1;
		}
	}
	cout << tot << endl;
	return 0;
}
