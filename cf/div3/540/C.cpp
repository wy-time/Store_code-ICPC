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
int countt[1006];
struct st
{
    int num;
    int cnt;
    st() {}
    st(int a, int b)
    {
        num = a;
        cnt = b;
    }
    bool operator < (const st &a)const
    {
        return this->cnt < a.cnt;
    }
};
int ans[25][25];
int findx()
{
    int i;
    wfor(i, 0, 1005)
    {
        if (countt[i] == 2 || countt[i] == 3)
        {
            return i;
        }
    }
    wfor(i, 0, 1005)
    {
        if (countt[i] % 2 == 0 && countt[i] != 0)
        {
            return i;
        }
    }
    wfor(i, 0, 1005)
    {
        if (countt[i] % 2 != 0)
        {
            return i;
        }
    }
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
    if (n == 1)
    {
        int t;
        cin >> t;
        cout << "YES" << endl;
        cout << t << endl;
        return 0;
    }
    int i;
    wfor(i, 0, n * n)
    {
        int t;
        cin >> t;
        countt[t]++;
    }
    int flag = 1;
    int j;
    wfor(i, 0, n)
    {
        if (flag == 0)
            break;
        wfor(j, 0, n)
        {
            if (flag == 0)
                break;
            if (ans[i][j] != 0)
                continue;
            if (n - 1 - i != i && n - j - 1 != j)
            {
                int k;
                if (*max_element(countt, countt + 1005) < 4)
                {
                    flag = 0;
                    break;
                } else
                {
                    wfor(k, 0, 1005)
                    {
                        if (countt[k] >= 4)
                            break;
                    }
                    ans[i][j] = k;
                    ans[n - 1 - i][j] = k;
                    ans[i][n - 1 - j] = k;
                    ans[n - 1 - i][n - 1 - j] = k;
                }
                countt[k] -= 4;
            } else if (n - 1 - i != i)
            {
                int k;
                if (*max_element(countt, countt + 1005) < 2)
                {
                    flag = 0;
                    break;
                } else
                {
                    k = findx();
                    ans[i][j] = k;
                    ans[n - 1 - i][j] = k;
                }
                countt[k] -= 2;
            } else if (n - 1 - j != j)
            {
                int k;
                if (*max_element(countt, countt + 1005) < 2)
                {
                    flag = 0;
                    break;
                } else
                {
                    k = findx();
                    ans[i][j] = k;
                    ans[i][n - 1 - j] = k;
                }
                countt[k] -= 2;
            } else
            {
                int k;
                wfor(k, 0, 1005)
                {
                    if (countt[k] != 0)
                        break;
                }
                ans[i][j] = k;
                countt[k]--;
            }
        }
    }
    if (flag == 1)
    {
        cout << "YES" << endl;
        wfor(i, 0, n)
        {
            wfor(j, 0, n - 1)
            {
                cout << ans[i][j] << " ";
            }
            cout << ans[i][j] << endl;
        }
    } else
        cout << "NO" << endl;
    return 0;
}
