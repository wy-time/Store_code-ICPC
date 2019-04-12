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
const int maxn = 3005;
map<string, string>ma;
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
    wfor(i, 0, m)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() <= s2.size())
        {
            ma.insert(make_pair(s1, s1));
            ma.insert(make_pair(s2, s1));
        } else
        {
            ma.insert(make_pair(s1, s2));
            ma.insert(make_pair(s2, s2));
        }
    }
    wfor(i, 0, n)
    {
        string t;
        cin >> t;
        cout << ma[t] << " ";
    }
    return 0;
}
