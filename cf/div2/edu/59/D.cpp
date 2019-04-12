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
const int maxn = 5205;
string s[maxn];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
string _0xmap[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
int chamap[200];
void init()
{
    int i;
    wfor(i, 0, 9)
    {
        chamap[i + '0'] = i;
    }
    chamap['A'] = 10;
    chamap['B'] = 11;
    chamap['C'] = 12;
    chamap['D'] = 13;
    chamap['E'] = 14;
    chamap['F'] = 15;
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
    init();
    int n;
    cin >> n;
    int i;
    wfor(i, 0, n)
    {
        cin >> s[i];
    }
    string last = s[0];
    int maxline = 0;
    int temp = 1;
    wfor(i, 1, n)
    {
        if (last == s[i])
        {
            temp++;
        } else
        {
            last = s[i];
            maxline = gcd(temp, maxline);
            temp = 1;
        }
    }
    maxline = gcd(temp, maxline);
    int tt = maxline;
    if (maxline != 1)
    {
        last = s[0];
        for (i = 0; i < n; i += tt)
        {
            if (i != 0 && s[i] == last)
                continue;
            else
            {
                int sz = s[i].size();
                int j;
                string bin = "";
                wfor(j, 0, sz)
                {
                    bin += _0xmap[chamap[s[i][j]]];
                }
                sz = bin.size();
                char lastchar = bin[0];
                int charcnt = 1;
                wfor(j, 1, sz)
                {
                    if (bin[j] == lastchar)
                        charcnt++;
                    else
                    {
                        lastchar = bin[j];
                        maxline = gcd(maxline, charcnt);
                        charcnt = 1;
                    }
                }
                maxline = gcd(maxline, charcnt);
            }
            if (maxline == 1)
                break;
        }
    }
    cout << maxline << endl;
    return 0;
}
