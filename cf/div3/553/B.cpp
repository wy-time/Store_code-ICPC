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
int ma[505][505];
int pos[505];
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
    int ans = 0;
    wfor(i, 0, n)
    {
        wfor(j, 0, m)
        {
            cin >> ma[i][j];
        }
        ans ^= ma[i][0];
        pos[i] = 1;
    }
    if (ans != 0)
    {
        int i;
        cout << "TAK" << endl;
        wfor(i, 0, n)
        {
            cout << pos[i] << " ";
        }
    } else
    {
        int flag = 0;
        wfor(i, 0, n)
        {
            wfor(j, 1, m)
            {
                if (ma[i][j] != ma[i][0])
                {
                    pos[i] = j + 1;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag)
        {
            cout << "TAK" << endl;
            int i;
            wfor(i, 0, n)
            {
                cout << pos[i] << " ";
            }
        } else
        {
            cout << "NIE" << endl;
        }
    }
    return 0;
}
