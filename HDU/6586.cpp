#include <iostream>
#include <cstring>
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
const int maxn = 1e5 + 5;
int num[26][2];
int pos[maxn][26];
char ans[maxn];
int sum[maxn][26];
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
    string s;
    while (cin >> s >> n)
    {
        int i;
        wfor(i, 0, 26)
        {
            cin >> num[i][0] >> num[i][1];
        }
        int len = s.size();
        int now[26];
        memset(now, -1, sizeof(now));
        memset(sum[len], 0, sizeof(sum[len]));
        mfor(i, len - 1, 0)
        {
            int j;
            now[s[i] - 'a'] = i;
            wfor(j, 0, 26)
            {
                pos[i][j] = now[j];
                if (j == s[i] - 'a')
                    sum[i][j] = sum[i + 1][j] + 1;
                else
                    sum[i][j] = sum[i + 1][j];
            }
        }
        int use[26] = {0};
        int pnow = 0;
        int flag = 1;
        wfor(i, 0, n)
        {
            int j;
            int chose = 0;
            wfor(j, 0, 26)
            {
                if (pos[pnow][j] == -1)
                {
                    if (use[j] < num[j][0])
                    {
                        flag = 0;
                        break;
                    } else
                        continue;
                }
                if (use[j] == num[j][1])continue;
                int temp = pos[pnow][j];
                use[j]++;
                int k;
                int ok = 1;
                int need = 0;
                int have = 0;
                wfor(k, 0, 26)
                {
                    have += min(sum[temp + 1][k], num[k][1]);
                    if (num[k][0] > use[k])need += num[k][0] - use[k];
                    if (sum[temp + 1][k] + use[k] < num[k][0])
                    {
                        ok = 0;
                        use[j]--;
                        break;
                    }
                }
                if (!ok)continue;
                else
                {
                    if (need > n - i - 1 || need > len - temp || n - i - 1 > len - temp - 1 || have < n - i - 1)
                    {
                        use[j]--;
                        continue;
                    }
                    ans[i] = j + 'a';
                    chose = 1;
                    pnow = pos[pnow][j] + 1;
                    break;
                }
            }
            if (!chose)
                flag = 0;
            if (!flag)
                break;
        }
        if (!flag)
            cout << -1 << endl;
        else
        {
            wfor(i, 0, n)
            cout << ans[i];
            cout << endl;
        }
    }
    return 0;
}
