#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int N = 3e5 + 5;
#define ll long long
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
int i, nn;
ll ans;
char s[N];
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 300010//绝对要多开一点，因为回文树会多开两个节点，我就被这坑过一次
#define ll long long
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
int i, nn;
ll ans;
char s[N];
struct Palindrome_Automaton//回文自动机
{
	int i, len[N], next[N][26], fail[N], cnt[N], last, cur, S[N], p, n;
	int newnode(int l)//新建节点
	{
		fo(i, 0, 25)next[p][i] = 0; //新建的节点为p，先消除它的子节点
		cnt[p] = 0;
		len[p] = l;
		return p++;//勿打成++p，因为此节点为p，我们应返回p
	}
	inline void init()//初始化
	{
		p = n = last = 0;
		newnode(0);
		newnode(-1);
		S[0] = -1;
		fail[0] = 1;
	}
	int get_fail(int x)
	{
		while (S[n - len[x] - 1] != S[n])x = fail[x];
		return x;
	}
	inline void add(int c, int pos) //插字符
	{
		c -= 'a';
		S[++n] = c;
		int cur = get_fail(last);
		if (!next[cur][c])
		{
			int now = newnode(len[cur] + 2);
			fail[now] = next[get_fail(fail[cur])][c];
			next[cur][c] = now;
		}
		last = next[cur][c];
		cnt[last]++;
	}
	void count()//统计本质相同的回文串的出现次数
	{
		fd(i, p - 1, 0) //逆序累加，保证每个点都会比它的父亲节点先算完，于是父亲节点能加到所有子孙
		cnt[fail[i]] += cnt[i];
	}
} tree;
int vis[N];
set<int>st;
void dfs(int now, int flag)
{
	int i;
	if (flag == 1)
		ans += st.size() * tree.cnt[now];
	for (i = 0; i < 26; i++)
	{
		int to = tree.next[now][i];
		if (!vis[to])
		{
			vis[to] = 1;
			if (st.count(i) != 0)
				dfs(tree.next[now][i], 1);
			else
			{
				st.insert(i);
				dfs(tree.next[now][i], 1);
				st.erase(i);
			}
			vis[to] = 0;
		}
	}
}
int main()
{
	scanf("%s", &s);
	tree.init();
	nn = strlen(s) - 1;
	fo(i, 0, nn)tree.add(s[i], i);
	tree.count();
	vis[0] = 1;
	dfs(0, 0);
	vis[1] = 1;
	dfs(1, 0);
	printf("%lld\n", ans);
}