#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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
const int maxn = 305;
int num[maxn];
int temp[maxn];
struct st
{
    int l;
    int r;
};
st seg[maxn];
vector<int>v, res;
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
    int n, m;
    cin >> n >> m;
    int i;
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    wfor(i, 0, m)
    {
        cin >> seg[i].l >> seg[i].r;
    }
    int ans = *max_element(num, num + n) - *min_element(num, num + n);
    wfor(i, 0, n)
    {
        int minnum = 0x7f7f7f7f;
        memcpy(temp, num, sizeof(num));
        int j;
        wfor(j, 0, m)
        {
            if (seg[j].l > i + 1 || seg[j].r < i + 1)
            {
                int k;
                v.push_back(j);
                wfor(k, seg[j].l - 1, seg[j].r)
                {
                    temp[k]--;
                    minnum = min(minnum, temp[k]);
                }
            }
        }
        if (num[i] - minnum > ans)
        {
            res = v;
            ans = num[i] - minnum;
        }
        v.clear();
    }
    cout << ans << endl;
    cout << res.size() << endl;
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it + 1 << " ";
    }
    return 0;
}
