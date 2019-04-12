#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 500005;
struct NODE
{
	int cnt;
	int _next[26];
	int _fail;
};
NODE node[maxn];
void node_init(int cnt);
void insert_char(char *s);
void query();
void cal_fail();
char ss[1000005];
int num;
int ans;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		num = 0;
		ans = 0;
		node_init(0);
		int n;
		cin >> n;
		char tt[60];
		int i;
		wfor(i, 0, n)
		{
			cin >> tt;
			insert_char(tt);
		}
		cal_fail();
		cin >> ss;
		query();
		cout << ans << endl;
	}
	return 0;
}
void node_init(int cnt)
{
	memset(node[cnt]._next, -1, sizeof(node[cnt]._next));
	node[cnt]._fail = -1;
	node[cnt].cnt = 0;
}
void insert_char(char *s)
{
	int p = 0;
	int len = strlen(s);
	int i;
	wfor(i, 0, len)
	{
		int t = s[i] - 'a';
		if (node[p]._next[t] == -1)
		{
			node_init(++num);
			node[p]._next[t] = num;
		}
		p = node[p]._next[t];
	}
	node[p].cnt++;
}
void cal_fail()
{
	queue<NODE>qu;
	int i;
	wfor(i, 0, 26)
	{
		if (node[0]._next[i] != -1)
		{
			int t = node[0]._next[i];
			node[t]._fail = 0;
			qu.push(node[t]);
		}
	}
	while (!qu.empty())
	{
		NODE temp = qu.front();
		qu.pop();
		wfor(i, 0, 26)
		{
			if (temp._next[i] != -1)
			{
				int p = temp._fail;
				while (p != -1 && node[p]._next[i] == -1)
				{
					p = node[p]._fail;
				}
				if (p == -1)
				{
					node[temp._next[i]]._fail = 0;
				} else if (node[p]._next[i] != -1)
					node[temp._next[i]]._fail = node[p]._next[i];
				qu.push(node[temp._next[i]]);
			}
		}
	}
}
void query()
{
	int len = strlen(ss);
	int i;
	int p = 0;
	wfor(i, 0, len)
	{
		int t = ss[i] - 'a';
		while (p != 0 && node[p]._next[t] == -1)
			p = node[p]._fail;
		p = node[p]._next[t];
		int temp;
		if (p != -1)
			temp = p;
		else
		{
			temp = p = 0;
		}
		while (temp != 0 && node[temp].cnt != -1)
		{
			ans += node[temp].cnt;
			node[temp].cnt = -1;
			temp = node[temp]._fail;
		}
	}
}