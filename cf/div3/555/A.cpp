#include <iostream>
#include <cstdio>
#include <set>
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
	cin >> n;
	set<int>st;
	st.insert(n);
	// int last = n;
	while (n)
	{
		n++;
		while (n % 10 == 0)
		{
			n /= 10;
		}
		if (st.count(n) != 0)
			break;
		st.insert(n);
		// last = n;
	}
	cout << st.size() << endl;
	return 0;
}