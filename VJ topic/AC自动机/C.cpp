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
struct NODE
{
	int _next[130];
	int cnt;
	int id;
	int _fail;
};
NODE node[50005];
char ss[1000][55];
char longs[2000005];
void char_insert(char *s, int id);
void init_node(int cnt)
{
	node[cnt].cnt = 0;
	node[cnt].id = -1;
	node[cnt]._fail = -1;
	memset(node[cnt]._next, -1, sizeof(node[cnt]._next));
}
void query(char *s);
int num;
void cal_fail();
int show[1005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	while (cin >> n)
	{
		memset(show, 0, sizeof(show));
		int i;
		num = 0;
		init_node(0);
		wfor(i, 0, n)
		{
			cin >> ss[i];
			char_insert(ss[i], i);
		}
		cal_fail();
		cin >> longs;
		query(longs);
		wfor(i, 0, n)
		{
			if (show[i] != 0)
				cout << ss[i] << ": " << show[i] << endl;
		}
	}
	return 0;
}
void char_insert(char *s, int id)
{
	int len = strlen(s);
	int p = 0;
	int i;
	wfor(i, 0, len)
	{
		int t = s[i];
		if (node[p]._next[t] == -1)
		{
			init_node(++num);
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
		int t = node[0]._next[i];
		if (t != -1)
		{
			node[t]._fail = 0;
			qu.push(node[t]);
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
						break;
					p = node[p]._fail;
				}
				if (p != -1)
					node[temp._next[i]]._fail = node[p]._next[i];
				else
					node[temp._next[i]]._fail = 0;
				qu.push(node[temp._next[i]]);
			}
		}
	}
}
void query(char *s)
{
	int len = strlen(s);
	int i;
	int p = 0;
	wfor(i, 0, len)
	{
		int t = s[i];
		while (p != 0 && node[p]._next[t] == -1)
			p = node[p]._fail;
		p = node[p]._next[t];
		int temp;
		if (p != -1)
			temp = p;
		else
			temp = p = 0;
		while (temp != 0)
		{
			if (node[temp].cnt != 0)
			{
				show[node[temp].id]++;
			}
			temp = node[temp]._fail;
		}
	}
}
