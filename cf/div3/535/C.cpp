#include <iostream>
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
    string temp[6] = {"RGB", "RBG", "GBR", "GRB", "BRG", "BGR"};
    string s;
    int ans = 1e9;
    cin >> s;
    int sz = s.size();
    int pos = 0;
    wfor(i, 0, 6)
    {
        int j;
        int tans = 0;
        wfor(j, 0, sz)
        {
            if (s[j] != temp[i][j % 3])
                tans++;
        }
        if (ans > tans)
        {
            ans = tans;
            pos = i;
        }
    }
    cout << ans << endl;
    while (n - 3 >= 0)
    {
        cout << temp[pos];
        n -= 3;
    }
    wfor(i, 0, n)
    {
        cout << temp[pos][i];
    }
    return 0;
}
