#include <iostream>
#include <algorithm>
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
const int maxn = 5005;
int numa[maxn];
int num1[maxn];
int num2[maxn];
int num0[maxn];
int n;
int ans[maxn];
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
    cin >> n;
    int i;
    int sum1 = 0, sum2 = 0;
    string a;
    cin >> a;
    wfor(i, 0, n)
    {
        sum1 += a[i] - '0';
        numa[i] = a[i] - '0';
    }
    int cnt0, cnt1, cnt2 = 0;
    cnt0 = cnt1 = cnt2 = 0;
    cin >> a;
    wfor(i, 0, n)
    {
        int t = a[i] - '0';
        sum2 += t;
        if (numa[i] + t == 0)
        {
            num0[cnt0++] = i + 1;
        } else if (numa[i] + t == 1)
            num1[cnt1++] = i + 1;
        else
            num2[cnt2++] = i + 1;
    }
    int cha = max(sum1, sum2);
    int need0, need1, need2;
    need0 = need1 = need2 = 0;
    int flag = 1;
    if (cha % 2 == 0)
    {
        if (cha / 2 <= cnt2)
            need2 = cha / 2;
        else
        {
            int need = cha - cnt2 * 2;
            need2 = cnt2;
            if (need <= cnt1)
            {
                need1 = need;
            } else
                flag = 0;
        }
    } else
    {
        if (cha / 2 <= cnt2)
        {
            need2 = cha / 2;
            if (cnt1 >= 1)
                need1 = 1;
            else
                flag = 0;
        } else
        {
            need2 = cnt2;
            int need = cha - cnt2 * 2;
            if (need <= cnt1)
            {
                need1 = need;
            } else
                flag = 0;
        }
    }
    if (flag == 1)
    {
        if (need1 + need2 < n / 2)
        {
            int need = n / 2 - (need1 + need2);
            if (need <= cnt0)
            {
                need0 = need;
            } else
            {
                need0 = cnt0;
                need -= cnt0;
                if ((cnt1 - need1) / 2 >= need)
                {
                    need1 += need * 2;
                    need2 -= need;
                } else
                    flag = 0;
            }

        }
        if (need1 + need2 + need0 > n / 2)
        {
            flag = 0;
        }
        wfor(i, 0, need1)
        {
            ans[num1[i]] = 1;
        }
        wfor(i, 0, need2)
        {
            ans[num2[i]] = 1;
        }
        wfor(i, 0, need0)
        {
            ans[num0[i]] = 1;
        }
        if (flag == 1)
        {
            if (sum1 < sum2)
            {
                wfor(i, 1, n + 1)
                {
                    if (ans[i] == 1)
                    {
                        cout << i << " ";
                    }
                }
            } else
            {
                wfor(i, 1, n + 1)
                {
                    if (ans[i] == 0)
                    {
                        cout << i << " ";
                    }
                }
            }
        } else
            cout << -1 << endl;
    } else
        cout << -1 << endl;
    return 0;
}
