#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll mod = 100000;
ll mp[100];
ll num;
struct ju_zheng
{
	ll p[105][105];
};
struct NODE
{
	ll cnt;
	ll next[4];
	ll fail;
};
NODE node[105];
void init(ll cnt)
{
	node[cnt].cnt = 0;
	node[cnt].fail = -1;
	memset(node[cnt].next, -1, sizeof(node[cnt].next));
}
void char_insert(char *s)
{
	ll p = 0;
	ll i;
	ll len = strlen(s);
	wfor(i, 0, len)
	{
		ll t = mp[s[i]];
		if (node[p].next[t] == -1)
		{
			init(++num);
			node[p].next[t] = num;
		}
		p = node[p].next[t];
	}
	node[p].cnt = 1;
}
void cal_fail()
{
	queue<NODE>qu;
	ll i;
	wfor(i, 0, 4)
	{
		ll t = node[0].next[i];
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
		wfor(i, 0, 4)
		{
			if (temp.next[i] != -1)
			{
				ll p = temp.fail;
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
ju_zheng ma;
ju_zheng mul(ju_zheng a, ju_zheng b)
{
	ll i, j, k;
	ju_zheng c;
	memset(c.p, 0, sizeof(c.p));
	wfor(i, 0, num)
	{
		wfor(j, 0, num)
		{
			wfor(k, 0, num)
			{
				c.p[i][j] = (c.p[i][j] + a.p[i][k] * b.p[k][j]) % mod;
			}
		}
	}
	return c;
}
ju_zheng ksm(ju_zheng a, ll b)
{
	ll i;
	ju_zheng res;
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
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	mp['A'] = 0;
	mp['C'] = 1;
	mp['G'] = 2;
	mp['T'] = 3;
	init(0);
	num = 0;
	ll n, m;
	cin >> n >> m;
	ll i;
	wfor(i, 0, n)
	{
		char s[15];
		cin >> s;
		char_insert(s);
	}
	ll k;
	cal_fail();
	wfor(i, 0, num)
	{
		wfor(k, 0, 4)
		{
			ll p = i;
			if (node[p].next[k] == -1 && node[p].cnt == 0)
			{
				while (node[p].next[k] == -1 && p != -1)
					p = node[p].fail;
				if (p != -1 && node[node[p].next[k]].cnt == 0)
				{
					ll id = node[p].next[k];
					ma.p[i][id]++;
				} else if (p == -1)
					ma.p[i][0]++;

			} else if (node[i].cnt == 0 && node[i].next[k] != -1 && node[node[i].next[k]].cnt == 0)
			{
				ll id = node[i].next[k];
				ma.p[i][id]++;
			}
		}
	}
	if (num == 0)
	{
		ma.p[0][0] = 4;
		num++;
	}
	ma = ksm(ma, m);
	ll res = 0;
	wfor(i, 0, num)
	{
		res = (res + ma.p[0][i]) % mod;
	}
	cout << res << endl;
	return 0;
}
