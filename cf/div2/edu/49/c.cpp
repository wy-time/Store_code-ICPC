// #include <iostream>
// #ifdef test
// #include <cstdio>
// #endif
// using namespace std;
// #include <algorithm>
// #include <cmath>
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// struct st
// {
// 	int id;
// 	int n;
// 	int cnt;
// };
// struct rule
// {
// 	bool operator()(const st &a , const st &b)
// 	{
// 		if (a.id == b.id)
// 		{
// 			if (a.cnt == b.cnt)
// 				return a.n > b.n;
// 			else
// 				return a.cnt > b.cnt;
// 		} else
// 			return a.id > b.id;
// 	}
// };
// st num[10005];
// int main()
// {
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// 	int t;
// 	cin >> t;
// 	int p;
// 	wfor(p, 0, t)
// 	{
// 		int n;
// 		cin >> n;
// 		int i;
// 		wfor(i, 0, n)
// 		{
// 			int k;
// 			cin >> k;
// 			if (num[k].id < p)
// 			{
// 				num[k].id = p;
// 				num[k].cnt = 0;
// 			}
// 			num[k].n = k;
// 			num[k].cnt++;
// 		}
// 		sort(num, num + 10005, rule());
// 		if (num[0].cnt >= 4) {

// 			cout << num[0].n << " " << num[0].n << " " << num[0].n << " " << num[0].n << endl;
// 			continue;
// 		}
// 		int res1 = 0, res2 = 0;
// 		int min_n = 0x3f3f3f;
// 		wfor(i, 0, n)
// 		{
// 			if (num[i + 1].n != 0 && num[i + 1].cnt >= 2 && num[i + 1].id == p)
// 			{
// 				int temp = abs(num[i].n - num[i + 1].n);
// 				if (temp < min_n)
// 				{
// 					min_n = temp;
// 					res1 = num[i].n;
// 					res2 = num[i + 1].n;
// 				}
// 			} else
// 				break;
// 		}
// 		cout << res1 << " " << res1 << " " << res2 << " " << res2 << endl;
// 	}
// 	return 0;
// }
#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int id[10005];
int vis[10005];
int ans[20005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	int i;
	wfor(i, 1, t + 1)
	{
		int n;
		cin >> n;
		int cnt = 0;
		while (n--)
		{
			int k;
			cin >> k;
			if (id[k] < i)
			{
				id[k] = i;
				vis[k] = 0;
			}
			vis[k]++;
			if (vis[k] == 2 || vis[k] == 4)
				ans[cnt++] = k;
		}
		sort(ans, ans + cnt);
		int j;
		double min_n = 0x3f3f3f;
		int out1, out2;
		wfor(j, 0, cnt - 1)
		{
			double temp = 2 * (ans[j] + ans[j + 1]);
			temp *= temp;
			temp /= (ans[j] * ans[j + 1]);
			if (min_n > temp)
			{
				min_n = temp;
				out1 = ans[j];
				out2 = ans[j + 1];
			}
		}
		cout << out1 << " " << out1 << " " << out2 << " " << out2 << endl;
	}
	return 0;
}
