#include <iostream>
#include <string>
#include <map>
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
    map<string, int>ma;
    int n, m;
    cin >> n >> m;
    string s;
    getline(cin, s);
    int i;
    wfor(i, 0, n)
    {
        getline(cin, s);
        if (ma.count(s) != 0)
        {
            ma[s]++;
        } else
            ma.insert(make_pair(s, 1));
    }
    map<string, int>::iterator it;
    ll ans = 0;
    for (it = ma.begin(); it != ma.end(); it++)
    {
        if (it->second != 0)
        {
            string tmp = it->first;
            int len = tmp.size();
            wfor(i, 0, len)
            {
                if (tmp[i] != ' ')
                {
                    tmp[i] = tmp[i] == '0' ? '1' : '0';
                }
            }
            if (ma.count(tmp) != 0)
            {
                ans += it->second * ma[tmp];
                it->second = 0;
                ma[tmp] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
