#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 3000005;
set<pair<int, int>>vis;
struct st
{
    int sum;
    int l;
    int r;
    st() {}
    st(int a, int b)
    {
        l = a;
        r = b;
    }
};
struct rule
{
    bool operator ()(const st&a, const st &b)
    {
        if (a.sum == b.sum)
        {
            if (a.r - a.l == b.r - b.l)
            {
                return a.l < b.l;
            }
            return a.r - a.l < b.r - b.l;
        }
        return a.sum < b.sum;
    }
};
st sum[maxn];
int num[2000];
vector<st>ans;
int check(st x, st y)
{
    int l = max(x.l, y.l);
    int r = min(x.r, y.r);
    if (l <= r)
    {
        return 0;
    }
    return 1;
}
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    int n;
    cin >> n;
    int i;
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    int j;
    int cnt = 0;
    wfor(i, 0, n)
    {
        int temp = 0;
        wfor(j, i, n)
        {
            temp += num[j];
            sum[cnt].sum = temp;
            sum[cnt].l = i;
            sum[cnt++].r = j;
        }
    }
    sort(sum, sum + cnt, rule());
    int maxxnt = 0;
    vector<st>temp;
    int tempcnt = 1;
    wfor(i, 0, cnt)
    {
        temp.clear();
        vis.clear();
        int j;
        st now = sum[i];
        vis.insert(make_pair(now.l, now.r));
        temp.push_back(now);
        tempcnt = 1;
        wfor(j, i + 1, cnt)
        {
            if (now.sum == sum[j].sum)
            {
                int flag = 1;
                auto it = vis.insert(make_pair(sum[j].l, sum[j].r));
                if (it.first != vis.begin())
                {
                    auto preit = --it.first;
                    it.first++;
                    if (it.first != vis.end())
                    {
                        auto freit = ++it.first;
                        it.first--;
                        if (check(st(preit->first, preit->second), st(sum[j].l, sum[j].r)) != 1 || check(st(freit->first, freit->second), st(sum[j].l, sum[j].r)) != 1)
                        {
                            vis.erase(it.first);
                            flag = 0;
                        }
                    } else
                    {
                        if (check(st(preit->first, preit->second), st(sum[j].l, sum[j].r)) != 1)
                        {
                            vis.erase(it.first);
                            flag = 0;
                        }
                    }
                } else
                {
                    auto freit = ++it.first;
                    if (check(st(sum[j].l, sum[j].r), st(freit->first, freit->second)) != 1)
                    {
                        vis.erase(it.first);
                        flag = 0;
                    }
                    it.first--;
                }
                if (flag)
                {
                    tempcnt++;
                    temp.push_back(sum[j]);
                    now = sum[j];
                }
            } else
            {
                if (maxxnt < tempcnt)
                {
                    ans.clear();
                    ans = temp;
                    maxxnt = tempcnt;
                }
                i = j - 1;
                break;
            }
        }
        if (maxxnt < tempcnt)
        {
            ans.clear();
            ans = temp;
            maxxnt = tempcnt;
        }
    }
    if (maxxnt < tempcnt)
    {
        ans.clear();
        ans = temp;
        maxxnt = tempcnt;
    }
    cout << maxxnt << endl;
    for (auto it : ans)
    {
        cout << it.l + 1 << " " << it.r + 1 << endl;
    }
    return 0;
}