#include <iostream>
#include <cmath>
#include <bitset>
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
    unsigned long n;
    cin >> n;
    bitset<20> bs(n);
    int len = log2(n);
    int i;
    int ans[50] = {0};
    int cnt = 0;
    int num = 0;
    mfor(i, len, 0)
    {
        if (bs.count() == len + 1)
            break;
        if (bs[i] == 0)
        {
            ans[cnt++] = i + 1;
            bs ^= ((1 << (i + 1)) - 1);
            num++;
            if (bs.count() == len + 1)
                break;
            num++;
            n = bs.to_ulong();
            n++;
            bitset<20>temp(n);
            bs = temp;
        }
    }
    if (cnt == 0)
        cout << 0 << endl;
    else
    {
        cout << num << endl;
        wfor(i, 0, cnt)
        cout << ans[i] << " ";
    }
    return 0;
}
