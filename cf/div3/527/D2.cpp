#include <iostream>
#include <cstdio>
#include <stack>
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
	int i;
	ll maxnum = -10000;
	ll t;
	stack<ll> st;
	int last = -1;
	int flag = 0;
	wfor(i, 0, n)
	{
		cin >> t;
		if (!st.empty())
		{
			if (st.top() == t)
			{
				if (flag)
				{
					if (t >= last)
					{
						st.pop();
						last = t;
					} else
					{
						st.push(t);
						flag = 0;
					}
				} else
				{
					st.pop();
					last = t;
					flag = 1;
				}
			} else
			{
				flag = 0;
				st.push(t);
			}
		} else
		{
			flag = 0;
			st.push(t);
		}
		maxnum = max(maxnum, t);
	}
	flag = 0;
	if (st.size() == 1)
	{
		if (st.top() == maxnum)
			flag = 1;
	} else if (st.empty())
		flag = 1;
	if (flag == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
