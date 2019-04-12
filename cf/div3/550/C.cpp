#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
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
	sort(num, num + n);
	vector<int>ans1;
	vector<int>ans2;
	ans1.push_back(num[0]);
	int last = num[0];
	int flag = 0;
	wfor(i, 1, n)
	{
		if (last == num[i])
		{
			if (flag == 1)
			{
				cout << "NO" << endl;
				return 0;
			}
			ans2.push_back(num[i]);
			flag = 1;
		} else
		{
			flag = 0;
			ans1.push_back(num[i]);
		}
		last = num[i];
	}
	cout << "YES" << endl;
	cout << ans1.size() << endl;
	for (auto it : ans1)
	{
		cout << it << " ";
	}
	cout << endl;
	if (!ans2.empty())
	{
		cout << ans2.size() << endl;
		mfor (i, ans2.size() - 1, 0)
		{
			cout << ans2[i] << " ";
		}
		cout << endl;
	} else
	{
		cout << 0 << endl << endl;;
	}
	return 0;
}
