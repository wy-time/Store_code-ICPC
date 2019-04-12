#include <queue>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
struct ju_zheng
{
	ll p[40][40];
};
struct NODE
{
	int cnt;
	int next[26];
	int fail;
};
NODE node[50];
int num;
void init_node(int cnt)
{
	node[cnt].cnt = 0;
	node[cnt].fail = -1;
	memset(node[cnt].next, -1, sizeof(node[cnt].next));
}
void char_insert(char *s)
{
	int p = 0;
	int i;
	int len = strlen(s);
	wfor(i, 0, len)
	{
		int t = s[i] - 'a';
		if (node[p].next[t] == -1)
		{
			init_node(++num);
			node[p].next[t] = num;
		}
		p = node[p].next[t];
	}
	node[p].cnt++;
}
void cal_fail()
{
	int i;
	queue<NODE>qu;
	wfor(i, 0, 26)
	{
		int t = node[0].next[i];
		if (t != -1)
		{
			node[t].fail = 0;
			qu.push(node[t]);
		}
	}
	while (!qu.empty())
	{
		NODE temp = qu.front();
		qu.pop();
		wfor(i, 0, 26)
		{
			if (temp.next[i] != -1)
			{
				int p = temp.fail;
				while (p != -1)
				{
					if (node[p].next[i] != -1)
						break;
					p = node[p].fail;
				}
				if (p != -1)
				{
					node[temp.next[i]].fail = node[p].next[i];
					if (node[node[p].next[i]].cnt != 0)
						node[temp.next[i]].cnt = 1;
				} else
					node[temp.next[i]].fail = 0;
				qu.push(node[temp.next[i]]);
			}
		}
	}
}
ju_zheng mul(ju_zheng a, ju_zheng b)
{
	ju_zheng c;
	memset(c.p, 0, sizeof(c.p));
	int i, j, k;
	wfor(i, 0, num)
	{
		wfor(j, 0, num)
		{
			wfor(k, 0, num)
			{
				c.p[i][j] = (c.p[i][j] + a.p[i][k] * b.p[k][j]);
			}
		}
	}
	return c;
}
ju_zheng ksm(ju_zheng a, ll b)
{
	ju_zheng res;
	memset(res.p, 0, sizeof(res.p));
	int i;
	wfor(i, 0, num)
	{
		res.p[i][i] = 1;
	}
	while (b)
	{
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
ju_zheng ma;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	while (cin >> n >> m)
	{
		memset(ma.p, 0, sizeof(ma.p));
		num = 0;
		char s[10];
		int i;
		init_node(0);
		wfor(i, 0, n)
		{
			cin >> s;
			char_insert(s);
		}
		cal_fail();
		int j;
		wfor(i, 0, num)
		{
			wfor(j, 0, 26)
			{
				if (node[i].next[j] != -1 && node[i].cnt == 0)
				{
					int id = node[i].next[j];
					if (node[id].cnt == 0)
						ma.p[i][id]++;
				} else if (node[i].next[j] == -1 && node[i].cnt == 0)
				{
					int p = i;
					while (p != -1 && node[p].next[j] == -1)
						p = node[p].fail;
					if (p != -1 && node[node[p].next[j]].cnt == 0)
						ma.p[i][node[p].next[j]]++;
					else if (p == -1)
						ma.p[i][0]++;
				}
			}
		}
		wfor(i, 0, num + 1)
		{
			ma.p[i][num] = 1;
		}
		num++;
		ll ans = 0;
		ma = ksm(ma, m);
		wfor(i, 0, num)
		{
			ans = (ans + ma.p[0][i]);
		}
		ans--;
		ju_zheng ma2;
		ma2.p[0][0] = 26, ma2.p[0][1] = 1, ma2.p[1][1] = ma2.p[1][0] = 0;
		ma.p[0][0] = 26, ma.p[0][1] = 0, ma.p[1][0] = 26, ma.p[1][1] = 1;
		num = 2;
		ma = ksm(ma, m - 1);
		ma2 = mul(ma2, ma);
		ll temp = ma2.p[0][0] + ma2.p[0][1] - 1;
		cout << temp - ans << endl;
	}
	return 0;
}
