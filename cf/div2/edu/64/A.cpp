#include <iostream>
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
    int num[205] = {0};
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    int last = num[0];
    int flag = 0;
    int ans = 0;
    wfor(i, 1, n)
    {
        if ((last == 2 && num[i] == 3) || (last == 3 && num[i] == 2))
        {
            flag = 1;
            break;
        }
        if ((last == 1 && num[i] == 2) || (last == 2 && num[i] == 1))
        {
            ans += 3;
            if (i - 2 >= 0 && num[i - 2] == 3 && last == 1)
                ans--;
        }
        if ((last == 1 && num[i] == 3) || (last == 3 && num[i] == 1))
            ans += 4;
        last = num[i];
    }
    if (flag == 1)
        cout << "Infinite" << endl;
    else
    {
        cout << "Finite" << endl;
        cout << ans << endl;
    }
    return 0;
}
