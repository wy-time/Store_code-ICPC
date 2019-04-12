#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 100005;
struct NODE
{
	int cnt;
	int _next[130];
	int _fail;
	int id;
};
NODE node[maxn];
int num;
void insert_char(char *s, int id);
void node_init(int cnt);
void cal_fail();
int query(int (&ans)[3]);
char ss[10005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	num = 0;
	int i;
	node_init(0);
	wfor(i, 0, n)
	{
		char t[205];
		cin >> t;
		insert_char(t, i + 1);
	}
	cal_fail();
	int m = 0;
	cin >> m;
	int case_cnt = 0;
	int tot = 0;
	int ans[3] = {0};
	while (m--)
	{
		case_cnt++;
		cin >> ss;
		int cnt = query(ans);
		if (cnt != 0)
		{
			cout << "web " << case_cnt << ": ";
			sort(ans, ans + cnt);
			wfor(i, 0, cnt - 1)
			{
				cout << ans[i] << " ";
			}
			cout << ans[i] << endl;
			tot++;
		}
	}
	cout << "total: " << tot << endl;
	return 0;
}
void node_init(int cnt)
{
	node[cnt]._fail = -1;
	node[cnt].cnt = 0;
	memset(node[cnt]._next, -1, sizeof(node[cnt]._next));
}
void insert_char(char *s, int id)
{
	int len = strlen(s);
	int i;
	int p = 0;
	wfor(i, 0, len)
	{
		int t = s[i];
		if (node[p]._next[t] == -1)
		{
			node_init(++num);
			node[p]._next[t] = num;
		}
		p = node[p]._next[t];
	}
	node[p].cnt++;
	node[p].id = id;
}
void cal_fail()
{
	queue<NODE>qu;
	int i;
	wfor(i, 0, 130)
	{
		if (node[0]._next[i] != -1)
		{
			node[node[0]._next[i]]._fail = 0;
			qu.push(node[node[0]._next[i]]);
		}
	}
	while (!qu.empty())
	{
		NODE temp = qu.front();
		qu.pop();
		wfor(i, 0, 130)
		{
			if (temp._next[i] != -1)
			{
				int p = temp._fail;
				while (p != -1)
				{
					if (node[p]._next[i] != -1)
					{
						node[temp._next[i]]._fail = node[p]._next[i];
						break;
					}
					p = node[p]._fail;
				}
				if (p == -1)
					node[temp._next[i]]._fail = 0;
				qu.push(node[temp._next[i]]);
			}
		}
	}
}
int query(int (&ans) [3])
{
	int len = strlen(ss);
	int i;
	int p = 0;
	int cnt = 0;
	wfor(i, 0, len)
	{
		int t = ss[i];
		while (p != 0 && node[p]._next[t] == -1)
			p = node[p]._fail;
		p = node[p]._next[t];
		int temp;
		if (p == -1)
			temp = p = 0;
		else
			temp = p;
		while (temp != 0)
		{
			if (node[temp].cnt != 0)
				ans[cnt++] = node[temp].id;
			temp = node[temp]._fail;
		}
	}
	return cnt;
}