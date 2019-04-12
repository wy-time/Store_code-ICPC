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
const int maxn = 2000005;
int _next[maxn], extend[maxn];
void get_next(char *s);
void get_ext(char *s, char *t);
void new_node(int num);
void char_insert(char *s, int bg);
void query(int bg, int ed);
struct NODE
{
	int nextchar[26];
	ll cnt;
	ll val;
};
ll cnt;
NODE node[maxn];
short flag[2][maxn];
char ss[maxn];
char inv[maxn], pre[maxn];
int bg[maxn], ed[maxn];
ll ans;
int main()
{
	// std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cnt = 0;
	scanf("%d", &n);
	int len = 0;
	int i;
	memset(node[0].nextchar, -1, sizeof(node[0].nextchar));
	wfor(i, 0, n)
	{
		int t = 0;
		scanf("%d%s", &t, pre);
		int j;
		// memcpy(ss + len, pre, sizeof(pre));
		bg[i] = len;
		ed[i] = bg[i] + t;
		wfor(j, bg[i], ed[i])
		{
			ss[j] = pre[j - bg[i]];
		}
		ss[j] = '\0';
		len += t;
		wfor(j, 0, t)
		{
			inv[j] = pre[t - 1 - j];
		}
		inv[i] = '\0';
		get_next(inv);
		get_ext(pre, inv);
		wfor(j, 0, t)
		{
			if (extend[j] + j == t)
				flag[0][bg[i] + j] = 1;
		}
		get_next(pre);
		get_ext(inv, pre);
		wfor(j, 1, t)
		{
			if (extend[j] + j == t)
				flag[1][bg[i] + j - 1] = 1;
		}
		wfor(j, bg[i], bg[i] + t / 2)
		{
			flag[1][j] ^= flag[1][ed[i] - (j - bg[i]) - 1];
			flag[1][ed[i] - (j - bg[i]) - 1] ^= flag[1][j];
			flag[1][j] ^= flag[1][ed[i] - (j - bg[i]) - 1];
		}
		char_insert(pre, bg[i]);
	}
	wfor(i, 0, n)
	{
		query(bg[i], ed[i]);
	}
	cout << ans << endl;
	return 0;
}
void get_next(char *s)
{
	int len = strlen(s);
	_next[0] = len;
	int i;
	int a = 0, p = 0;
	wfor(i, 1, len)
	{
		if (i >= p || i + _next[i - a] >= p)
		{
			if (i > p)
				p = i;
			while (p < len && s[p - i] == s[p])
				++p;
			_next[i] = p - i;
			a = i;
		} else
			_next[i] = _next[i - a];
	}
}
void get_ext(char *s, char *t)
{
	int len = strlen(s);
	int len2 = strlen(t);
	int i;
	int p = 0, a = 0;
	wfor(i, 0, len)
	{
		if (i >= p || i + _next[i - a] >= p)
		{
			if (i > p)
				p = i;
			while (p < len && p - i < len2 && s[p] == t[p - i])
				++p;
			extend[i] = p - i;
			a = i;
		} else
			extend[i] = _next[i - a];
	}
}
void new_node(int num)
{
	memset(node[num].nextchar, -1, sizeof(node[num].nextchar));
	node[num].cnt = 0;
	node[num].val = 0;
}
void char_insert(char *s, int bg)
{
	int len = strlen(s);
	int i;
	int p = 0;
	wfor(i, 0, len)
	{
		if (flag[0][bg + i])
			node[p].cnt++;
		if (node[p].nextchar[s[i] - 'a'] == -1)
		{
			new_node(++cnt);
			node[p].nextchar[s[i] - 'a'] = cnt;
		}
		p = node[p].nextchar[s[i] - 'a'];
	}
	node[p].val++;
}
void query(int bg, int ed)
{
	int i;
	int p = 0;
	mfor(i, ed - 1, bg)
	{
		int t = ss[i] - 'a';
		if (node[p].nextchar[t] != -1)
		{
			p = node[p].nextchar[t];
			if (flag[1][i])
				ans += node[p].val;
		}
		else
			break;
	}
	if (i == bg - 1)
	{
		ans += node[p].cnt;
		if (!flag[1][i + 1])
			ans += node[p].val;
	}
}
