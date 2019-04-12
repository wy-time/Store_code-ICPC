#include <iostream>
#include <map>
#include <cmath>
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
const int maxn = 2e5 + 5;
int num[maxn];
int num2[maxn];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
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
    int i;
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    wfor(i, 0, n)
    {
        cin >> num2[i];
    }
    int res = 0;
    int fix = 0;
    map<pair<int, int>, int>ma;
    wfor(i, 0, n)
    {
        if (num[i] != 0)
        {
            if (num2[i] == 0)
            {
                if (ma.count(make_pair(0, 0)) == 0)
                {
                    ma.insert(make_pair(make_pair(0, 0), 1));
                } else
                    ma[make_pair(0, 0)]++;
                res = max(res, ma[make_pair(0, 0)]);
            } else
            {
                int temp = gcd(num[i], num2[i]);
                while (temp != 1)
                {
                    num[i] /= temp;
                    num2[i] /= temp;
                    temp = gcd(num[i], num2[i]);
                }
                if (ma.count(make_pair(num2[i], num[i])) == 0)
                {
                    ma.insert(make_pair(make_pair(num2[i], num[i]), 1));
                } else
                    ma[make_pair(num2[i], num[i])]++;
                res = max(res, ma[make_pair(num2[i], num[i])]);
            }
        } else if (num2[i] == 0)
        {
            fix++;
        }
    }
    cout << res + fix << endl;
    return 0;
}
