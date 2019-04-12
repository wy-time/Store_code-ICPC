#include <iostream>
#include <set>
#include <vector>
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
int ma[505][505];
set<pair<int, int>>st;
int visx[505];
int visy[505];
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
    int i, j;
    wfor(i, 0, n)
    {
        wfor(j, 0, m)
        {
            cin >> ma[i][j];
        }
    }
    wfor(i, 0, n)
    {
        wfor(j, 0, m)
        {
            int t;
            cin >> t;
            if (ma[i][j] != t)
            {
                st.insert(make_pair(i, j));
            }
        }
    }
    int flag = 1;
    for (auto it : st)
    {
        int x, y;
        x = it.first;
        y = it.second;
        visx[x]++;
        visy[y]++;
    }
    wfor(i, 0, n)
    {
        if (visx[i] % 2 != 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        wfor(i, 0, m)
        {
            if (visy[i] % 2 != 0)
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag)
    {
        cout << "Yes" << endl;
    } else
        cout << "No" << endl;
    return 0;
}
