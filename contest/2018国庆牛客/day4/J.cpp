#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int people[1005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int i;
	string s, last = "";
	memset(people, -1, sizeof(people));
	wfor(i, 0, m)
	{
		int id;
		cin >> id >> s;
		if (s == last)
		{
			if (people[id] != 0)
				people[id] = 1;
		}
		else
			people[id] = 0;
		last = s;
	}
	int cnt = 0;
	int ans[1005] = {0};
	wfor(i, 1, n + 1)
	{
		if (people[i])
		{
			ans[cnt] = i;
			cnt++;
		}
	}
	wfor(i, 0, cnt - 1)
	{
		cout << ans[i] << " ";
	}
	cout << ans[i] << endl;
	return 0;
}
