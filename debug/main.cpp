#include <iostream>
#include <algorithm>
#include <cmath>
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
struct st
{
    int first;
    int second;
    st() {}
    st(int a, int b)
    {
        first = a;
        second = b;
    }
    bool operator <(const st a)const
    {
        return first < a.first;
    }
};
int leng[5005];
st v[10005];
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
    int t;
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        memset(leng, 0, sizeof(leng));
        int num[105] = {0};
        int n;
        cin >> n;
        int i;
        wfor(i, 0, n)
        {
            cin >> num[i];
        }
        int maxnum = 0;
        wfor(i, 0, n)
        {
            int j;
            int temp = num[i];
            leng[temp] = max(leng[temp], 1);
            maxnum = max(maxnum, temp);
            wfor(j, i + 1, n)
            {
                temp ^= num[j];
                leng[temp] = max(leng[temp], j - i + 1);
                maxnum = max(maxnum, temp);
            }
        }
        wfor(i, 0, maxnum + 1)
        {
            if (leng[i] != 0)
            {
                v[cnt++] = st(i, leng[i]);
            }
        }
        int m;
        cin >> m;
        while (m--)
        {
            int x;
            cin >> x;
            int pos = upper_bound(v, v + cnt, st(x, 1)) - v;
            if (pos == cnt)
            {
                cout << v[pos - 1].second << endl;
                continue;
            }
            else if (pos == 0)
            {
                cout << v[pos].second << endl;
                continue;
            }
            if (abs(v[pos].first - x) < abs(v[pos - 1].first - x))
                cout << v[pos].second << endl;
            else if (abs(v[pos].first - x) > abs(v[pos - 1].first - x))
                cout << v[pos - 1].second << endl;
            else
            {
                cout << max(v[pos].second, v[pos - 1].second) << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
