#include <iostream>
#include <map>
#include <string>
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
const int maxn = 10005;
int num[maxn];
struct st
{
    int s;
    int mod;
    st() {}
    st(int a, int b)
    {
        s = a;
        mod = b;
    }
    bool operator <(const st &oth)const
    {
        if (s == oth.s)
        {
            return mod > oth.mod;
        } else
            return s > oth.s;
    }
};
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
    int n, m, k;
    cin >> n >> m >> k;
    int t = n / m;
    n -= t * m;
    int i;
    map<st, int>st1;
    int flag = 1;
    int len = 0;
    int pos;
    wfor(i, 0, maxn)
    {
        n *= 10;
        num[i] = n / m;
        n -= num[i] * m;
        if (flag)
        {
            if (st1.count(st(num[i], n)) == 0)
                st1.insert(make_pair(st(num[i], n), i));
            else
            {
                flag = 0;
                pos = st1[st(num[i], n)];
                len = i - pos;
            }
        }
    }
    if (len != 0)
    {
        if (k >= pos + 1)
        {
            k -= pos;
            int need = k % len;
            if (need == 0)
            {
                cout << num[pos + len - 1] << num[pos + len] << num[pos + len + 1] << endl;
            } else
                cout << num[pos + need - 1] << num[pos + need] << num[pos + need + 1] << endl;
        } else
        {
            cout << num[k - 1] << num[k] << num[k + 1] << endl;
        }
    } else if (k + 1 > maxn)
    {
        cout << 0 << 0 << 0 << endl;
    } else
        cout << num[k - 1] << num[k] << num[k + 1] << endl;
    return 0;
}
