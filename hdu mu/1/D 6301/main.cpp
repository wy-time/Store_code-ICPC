/*#include <cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 1e5+9;
struct node
{
    int s, e;
}a[MAXN];
struct rule
{
	bool operator () (const struct node & a,const struct node & b)
	{
		if(a.s == b.s)
        	return a.e > b.e;
    	return a.s < b.s;
	}
};
bool vis[MAXN];
int ans[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        memset(a, 0, sizeof(a));
        int n, m;
        scanf("%d%d", &n, &m);
        fill(ans+1,ans+n+1,1);
        for(int i = 1; i <= m; ++i)
            scanf("%d%d", &a[i].s, &a[i].e);
        sort(a+1, a+m+1, rule());
        fill(ans+1,ans+a[1].s+1,1);
        int cnt = 1;
        for(int i = a[1].s; i <= a[1].e; ++i)
        {
            ans[i] = cnt;
            vis[cnt++] = 1;
        }
        node prev = a[1];
        for(int i = 2; i <= m; ++i)
        {
        	if(a[i].s>=prev.s && a[i].e<=prev.e)
        		continue;
        	prev = a[i];
            if(a[i].s > a[i-1].e)
            {
                cnt = 1;
                memset(vis, 0, sizeof(vis));
                for(int j = a[i].s; j <= a[i].e; ++j)
                {
                    ans[j] = cnt;
                    vis[cnt++] = 1;
                }
            }
            else
            {
                for(int j = a[i-1].s; j < a[i].s; ++j)
                    vis[ans[j]] = 0;
                int ii = 1;
                for(int j = a[i-1].e+1; j <= a[i].e; ++j)
                {
                    while(vis[ii])
                        ii++;
                    ans[j] = ii;
                    vis[ii] = 1;
                }
            }
        }
        for(int i = 1; i <= n; i++)
            printf("%d%c", ans[i], i==n ? '\n' : ' ');
    }

    return 0;
}*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> ends(n, -1);
    for (int i = 0; i < n; ++i) ends[i] = i;
    for (int i = 0; i < m; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      ends[l - 1] = std::max(ends[l - 1], r - 1);
    }
    std::set<int> unused;
    for (int i = 1; i <= n; ++i) {
      unused.insert(i);
    }
    std::vector<int> ret(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
      if (r >= ends[i]) continue;
      while (l < i) {
        unused.insert(ret[l++]);
      }
      while (r < ends[i]) {
        ret[++r] = *unused.begin();
        unused.erase(ret[r]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i) putchar(' ');
      printf("%d", ret[i]);
    }
    puts("");
  }
  return 0;
}
