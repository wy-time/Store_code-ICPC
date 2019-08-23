#include <iostream>
#include <string>
#include <stack>
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
const int maxn = 3005;
int ma[maxn][maxn];
int h[maxn][maxn];
int sum[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
// 	freopen("/home/time/debug/debug/in", "r", stdin);
// 	freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
	int n, m;
	cin >> n >> m;
	int i, j;
	string s;
	wfor(i, 1, n + 1)
	{
		cin >> s;
		wfor(j, 1, m + 1)
		{
			ma[i][j] = s[j - 1] - '0';
			if (ma[i][j] == 1)
				sum[i][j] = sum[i][j - 1] + 1;
		}
	}
	wfor(j, 1, m + 1)
	{
		wfor(i, 1, n + 1)
		{
			if (ma[i][j] == 1)
				h[i][j] = h[i - 1][j] + 1;
		}
	}
	int ans = 0;
	wfor(i, 1, n + 1)
	{
		int L[maxn] = {0};
		int R[maxn] = {0};
		stack<pair<int, int>>st;
		wfor(j, 1, m + 1)
		{
			if (ma[i][j] != 1)
			{
				L[j] = -1;
				R[j] = -1;
				while (!st.empty())
				{
					int pos = st.top().first;
					R[pos] = j;
					st.pop();
				}
			} else
			{
				if (!st.empty())
				{
					if (h[i][j] >= st.top().second)
					{
						if (h[i][j] == st.top().second)
							L[j] = -1;
						else
						{
							L[j] = st.top().first;
						}
						st.push(make_pair(j, h[i][j]));
					} else
					{
						int temp = 0;
						while (!st.empty() && h[i][j] < st.top().second)
						{
							int pos = st.top().first;
							R[pos] = j;
							temp = L[pos];
							st.pop();
						}
						if (!st.empty() && h[i][j] != st.top().second)
						{
							L[j] = st.top().first;
						}
						else if (!st.empty())
						{
							L[j] = -1;
						} else
						{
							L[j] = temp;
						}
						st.push(make_pair(j, h[i][j]));
					}
				} else
				{
					L[j] = j - 1;
					st.push(make_pair(j, h[i][j]));
				}
			}
		}
		while (!st.empty())
		{
			int pos = st.top().first;
			R[pos] = j;
			st.pop();
		}
		wfor(j, 1, m + 1)
		{
			if (L[j] != -1)
			{
				if (sum[i][R[j] - 1] - sum[i][L[j]] != sum[i + 1][R[j] - 1] - sum[i + 1][L[j]])
					ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
