#include <iostream>
// #ifdef test
#include <cstdio>
// #endif
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int num[100005];
int _next[100005];
int res[100005];
int c_id[100005];
int c_num[100005];
inline void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
int main()
{
	// std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int t;
	read(t);
	while (t--)
	{
		int n, m;
		read(n); read(m);
		register int i;
		int max_n = 0;
		memset(_next, 0, sizeof(_next));
		wfor(i, 1, n + 1)
		{
			read(num[i]);
		}
		max_n = num[1];
		res[1] = 1;
		int last_id = 1;
		_next[last_id] = 0;
		c_id[1] = 1;
		int c_id_cnt = 2;
		c_num[1] = num[1];
		int c_num_cnt = 2;
		wfor(i, 2, n + 1)
		{
			if (num[i] > max_n)
			{
				max_n = num[i];
				res[i] = res[i - 1] + 1;
				c_id[c_id_cnt++] = i;
				c_num[c_num_cnt++] = num[i];
				_next[last_id] = i;
				last_id = i;
			} else
				res[i] = res[i - 1];
		}
		int out = res[n];
		wfor(i, 0, m)
		{
			out = res[n];
			int pos, x;
			// cin >> pos >> x;
			read(pos); read(x);
			if (_next[pos] == 0 && c_id[c_id_cnt - 1] != pos)
			{
				if (num[pos] < x)
				{
					int t_id = upper_bound(c_id + 1, c_id + c_id_cnt, pos) - c_id;
					if (num[c_id[t_id - 1]] < x)
					{
						out += 1;
						int id = c_id[t_id - 1];
						id = _next[id];
						if (id != 0)
						{
							int tt = upper_bound(c_num + 1, c_num + c_num_cnt, x) - c_num;
							int ttt = lower_bound(c_num + 1, c_num + c_num_cnt, num[id]) - c_num;
							out -= (tt - ttt);
						}
					}
				}
			} else
			{
				if (num[pos] > x)
				{
					int t_id = lower_bound(c_id + 1, c_id + c_id_cnt, pos) - c_id;
					int t_max = x;
					if (num[c_id[t_id - 1]] >= x)
					{
						out -= 1;
						t_max = num[c_id[t_id - 1]];
					}
					register int j;
					int t_end = t_id + 1 < c_id_cnt ? c_id[t_id + 1]  : n + 1;
					wfor(j, pos + 1, t_end)
					{
						if (num[j] > t_max)
						{
							out++;
							t_max = num[j];
						}
					}
				}
				else if (num[pos] < x)
				{
					int id = pos;
					id = _next[id];
					if (id != 0)
					{
						int tt = upper_bound(c_num + 1, c_num + c_num_cnt, x) - c_num;
						int ttt = lower_bound(c_num + 1, c_num + c_num_cnt, num[id]) - c_num;
						out -= (tt - ttt);
					}
				}
			}
			printf("%d\n", out);
		}
	}
	return 0;
}
