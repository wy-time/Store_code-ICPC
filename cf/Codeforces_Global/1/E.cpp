#include <iostream>
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
const int maxn = 1e5 + 5;
int num[maxn];
int aim[maxn];
int cha[maxn];
int cha2[maxn];
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
        cin >> aim[i];
    }
    wfor(i, 1, n)
    {
        cha[i - 1] = num[i] - num[i - 1];
        cha2[i - 1] = aim[i] - aim[i - 1];
    }
    if (num[0] != aim[0] || num[n - 1] != aim[n - 1])
    {
        cout << "No" << endl;
    } else
    {
        sort(cha, cha + n - 1);
        sort(cha2, cha2 + n - 1);
        int flag = 1;
        wfor(i, 0, n - 1)
        {
            if (cha[i] != cha2[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
