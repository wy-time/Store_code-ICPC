#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 105;
struct EDGE
{
	int _next;
	int _end;
};
int head[maxn];
EDGE edge[maxn * maxn];
int cnt, deep, sum;
void add(int beg, int _end)
{
	edge[++cnt]._next = head[beg];
	edge[cnt]._end = _end;
	head[beg] = cnt;
}
int dfn[maxn], low[maxn], vis[maxn], color[maxn], super[maxn], super_chu[maxn];
void tarjan(int beg);
stack <int> sta;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	int i;
	deep = 0;
	cnt = 0;
	sum = 0;
	wfor(i, 0, n)
	{
		int temp;
		while (cin >> temp)
		{
			if (temp == 0)
				break;
			add(i + 1, temp);
		}
	}
	wfor(i, 1, n + 1)
	{
		if (!dfn[i])
			tarjan(i);
	}
	wfor(i, 1, n + 1)
	{
		for (int j = head[i]; j != 0; j = edge[j]._next)
		{
			if (color[edge[j]._end] != color[i])
			{
				super[color[edge[j]._end]]++;
				super_chu[color[i]]++;
			}
		}
	}
	int ansA = 0;
	int ansB = 0;
	wfor(i, 1, sum + 1)
	{
		if (super[i] == 0)
		{
			ansA++;
		}
		if (super_chu[i] == 0)
			ansB++;
	}
	if (sum != 1)
		ansB = max(ansA, ansB);
	else
		ansB = 0;
	cout << ansA << endl << ansB << endl;
	return 0;
}
void tarjan(int beg)
{
	low[beg] = dfn[beg] = ++deep;
	sta.push(beg);
	vis[beg] = 1;
	int i;
	for (i = head[beg]; i != 0; i = edge[i]._next)
	{
		if (!dfn[edge[i]._end])
		{
			tarjan(edge[i]._end);
			low[beg] = min(low[edge[i]._end], low[beg]);
		} else
		{
			if (vis[edge[i]._end])
				low[beg] = min(dfn[edge[i]._end], low[beg]);
		}
	}
	if (low[beg] == dfn[beg])
	{
		color[beg] = ++sum;
		vis[beg] = 0;
		while (sta.top() != beg)
		{
			int temp = sta.top();
			sta.pop();
			color[temp] = sum;
			vis[temp] = 0;
		}
		sta.pop();
	}
}