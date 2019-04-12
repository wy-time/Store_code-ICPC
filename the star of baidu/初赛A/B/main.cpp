#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int n, q;
	while (cin >> n >> q)
	{
		deque <int> int_list[n];
		int i;
		// wfor(i, 0, n)
		// {
		// 	int_list[i].clear();
		// }
		wfor(i, 0, q)
		{
			int op;
			read(op);
			if (op == 1)
			{
				int cnt, w, val;
				read(cnt); read(w); read(val);
				if (w == 0)
				{
					int_list[cnt - 1].push_front(val);
				} else
					int_list[cnt - 1].push_back(val);
			} else if (op == 2)
			{
				int cnt, w;
				read(cnt); read(w);
				if (w == 0)
				{
					if (!int_list[cnt - 1].empty())
					{
						int t = int_list[cnt - 1].front();
						cout << t << endl;
						int_list[cnt - 1].pop_front();
					} else
						cout << -1 << endl;
				} else
				{
					if (!int_list[cnt - 1].empty())
					{
						int t = int_list[cnt - 1].back();
						cout << t << endl;
						int_list[cnt - 1].pop_back();
					} else
						cout << -1 << endl;
				}
			} else
			{
				int cnt1, cnt2, w;
				read(cnt1); read(cnt2); read(w);
				if (w == 0)
				{
					while (!int_list[cnt2 - 1].empty())
					{
						int t = int_list[cnt2 - 1].front();
						int_list[cnt1 - 1].push_back(t);
						int_list[cnt2 - 1].pop_front();
					}
				} else
				{
					while (!int_list[cnt2 - 1].empty())
					{
						int t = int_list[cnt2 - 1].back();
						int_list[cnt1 - 1].push_back(t);
						int_list[cnt2 - 1].pop_back();
					}
				}
			}
		}
	}
	return 0;
}
