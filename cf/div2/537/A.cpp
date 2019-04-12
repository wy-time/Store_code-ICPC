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
    string s, t;
    cin >> s >> t;
    int len = s.size();
    int cha[200] = {0};
    cha['a'] = 1;
    cha['e'] = 1;
    cha['i'] = 1;
    cha['o'] = 1;
    cha['u'] = 1;
    if (len == t.size())
    {
        int i;
        int flag = 1;
        wfor(i, 0, len)
        {
            if (cha[s[i]] != cha[t[i]])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    } else
        cout << "No" << endl;
    return 0;
}
