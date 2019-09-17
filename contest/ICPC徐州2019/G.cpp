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
struct Palindrome_Automaton
{
	int i, len[N], next[N][26], fail[N], cnt[N], last, cur, S[N], p, n;
	int newnode(int l)
	{
		fo(i, 0, 25)next[p][i] = 0;
		len[p] = l;
		return p++;
	}
	inline void init()
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
	inline void add(int c, int pos)
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
	void count()
	{
		fd(i, p - 1, 0)
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
		// if (!vis[tree.fail[now]])
		// {
		// 	vis[tree.fail[now]] = 1;
		// 	dfs(tree.fail[now], 0);
		// 	vis[tree.fail[now]] = 0;
		// }
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