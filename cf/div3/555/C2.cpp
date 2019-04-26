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
const int maxn = 2e5 + 5;
int num[maxn];
char ans[maxn];
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
		cin >> num[i];
	}
	int cnt = 0;
	int last = -1;
	int l = 0, r = n - 1;
	while (l <= r)
	{
		if (max(num[l], num[r]) > last)
		{
			if (num[l] != num[r])
			{
				int te = min(num[l], num[r]);
				if (te > last)
				{
					last = te;
					if (num[l] < num[r])
					{
						ans[cnt++] = 'L';
						l++;
					} else
					{
						ans[cnt++] = 'R';
						r--;
					}
				} else
				{
					last = max(num[l], num[r]);
					if (num[l] > num[r])
					{
						ans[cnt++] = 'L';
						l++;
					} else
					{
						ans[cnt++] = 'R';
						r--;
					}
				}
			} else
			{
				int temp = last;
				int tt = l;
				int ccnt = 0;
				int ccnt2 = 0;
				while (tt <= r && num[tt] > last )
				{
					ccnt++;
					last = num[tt];
					tt++;
				}
				last = temp;
				tt = r;
				while (tt >= l && num[tt] > last)
				{
					ccnt2++;
					last = num[tt];
					tt--;
				}
				if (ccnt2 > ccnt)
				{
					while (ccnt2--)
					{
						ans[cnt++] = 'R';
					}
				} else
				{
					while (ccnt--)
					{
						ans[cnt++] = 'L';
					}
				}
			}
		} else
			break;
	}
	cout << cnt << endl;
	wfor(i, 0, cnt)
	{
		cout << ans[i];
	}
	return 0;
}
