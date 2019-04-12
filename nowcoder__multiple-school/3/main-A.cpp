#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
struct INFO
{
	int p, a, c, ;
	int know;
} info[40];
//int vis[40];
int n;
// struct st
// {
// 	int v;
// 	string s;
// 	st()
// 	{
// 		string init(38, '0');
// 		v = 0;
// 		s = init;
// 	}
// };
// st
int dp[40][40][40][40];
ll res[40][40][40][40];
//int res[4000][80];
//int dfs(int sum, int aim, int p, int a, int c, int m);
int P, A, C, M;
int step;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	register int i;
	wfor(i, 1, n + 1)
	{
		int q, w, e, r, t;
		cin >> q >> w >> e >> r >> t;
		info[i].p = q; info[i].a = w; info[i].c = e; info[i].m = r; info[i].know = t;
	}
	cin >> P >> A >> C >> M;
	register short j, k, l, _;
	wfor(i, 1, n + 1)
	{
		for (j = P; j >= info[i].p; --j)
		{
			for (k = A; k >= info[i].a; --k)
			{
				for (l = C; l >= info[i].c; --l)
				{
					for (_ = M; _ >= info[i].m; --_)
					{
						if (dp[j][k][l][_] < dp[j - info[i].p][k - info[i].a][l - info[i].c][_ - info[i].m] + info[i].know)
						{
							dp[j][k][l][_] = dp[j - info[i].p][k - info[i].a][l - info[i].c][_ - info[i].m] + info[i].know;
							res[j][k][l][_] = res[j - info[i].p][k - info[i].a][l - info[i].c][_ - info[i].m] | (1LL << i);
						}
						//dp[j][k][l][_].s = dp[j - info[i].p][k - info[i].a][l - info[i].c][_ - info[i].m].s;
						//dp[j][k][l][_].s[i - 1] = '1';
						//res[dp[j][k][l][_]][i] = 1;
					}
				}
			}
		}
	}
	//cout << dp[P][A][C][M].v << endl;
	//string temp = dp[P][A][C][M].s;
	//int len = temp.size();
	//cout << temp << endl;
	int cnt = 0;
	//int last = dp[P][A][C][M];
	wfor(i, 0, n)
	{
		if (res[P][A][C][M] & (1LL << (i + 1)))
			cnt++;
	}
	cout << cnt << endl;
	wfor(i, 0, n)
	{
		if (res[P][A][C][M] & (1LL << (i + 1)))
			cout << i << " ";
	}
	//dfs(0, ans, 0, 0, 0, 0);
	/*cout << step << endl;
	if (step != 0)
	{
		wfor(i, 0, step - 1)
		{
			cout << res[i] << " ";
		}
		cout << res[i] << endl;
	}*/
	return 0;
}
/*int dfs(int sum, int aim, int p, int a, int c, int m)
{
	int i;
	if (p > P || a > A || c > C || m > M)
		return 0;
	if (sum == aim && p <= P && a <= A && c <= C && m <= M)
	{
		return 1;
	}
	wfor(i, 0, n)
	{
		if (!vis[i])
		{
			vis[i] = true;
			p += info[i].p;
			a += info[i].a;
			c += info[i].c;
			m += info[i].m;
			sum += info[i].know;
			res[step++] = i;
			if (!dfs(sum, aim, p, a, c, m))
			{
				step--;
				vis[i] = false;
				p -= info[i].p;
				a -= info[i].a;
				c -= info[i].c;
				m -= info[i].m;
				sum -= info[i].know;
			} else
				return 1;
		}

	}
	return 0;
}*/