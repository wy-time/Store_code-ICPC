#include <iostream>
#include <algorithm>
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
const int maxn = 2e5 + 5;
int A[maxn];
// struct st
// {
// 	int id;
// 	int num;
// };
// int B[maxn];
set<int>B;
int ans[maxn];
int vis[maxn];
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
	wfor(i, 0, n)
	{
		cin >> A[i];
	}
	wfor(i, 0, n)
	{
		int t;
		cin >> t;
		B.insert(t);
		vis[t]++;
	}
	wfor(i, 0, n)
	{
		int need = n - A[i];
		auto pos = B.lower_bound(need);
		if (pos != B.end())
		{
			if (*pos == need)
			{
				ans[i] = 0;
				if (vis[*pos] == 1)
					B.erase(pos);
				else
					vis[*pos]--;
			} else
			{
				if (pos == B.begin())
				{
					ans[i] = (A[i] + *pos) % n;
					if (vis[*pos] == 1)
						B.erase(pos);
					else
						vis[*pos]--;
				} else
				{
					pos--;
					auto t1 = pos;
					pos++;
					if ((A[i] + *pos) % n < (A[i] + *t1) % n)
					{
						ans[i] = (A[i] + *pos) % n;
						if (vis[*pos] == 1)
							B.erase(pos);
						else
							vis[*pos]--;
					} else
					{
						ans[i] = (A[i] + *t1) % n;
						if (vis[*t1] == 1)
							B.erase(t1);
						else
							vis[*t1]--;
					}
				}
			}
		} else
		{
			pos = B.begin();
			ans[i] = (A[i] + *pos) % n;
			if (vis[*pos] == 1)
				B.erase(pos);
			else
				vis[*pos]--;
		}
	}
	wfor(i, 0, n)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
