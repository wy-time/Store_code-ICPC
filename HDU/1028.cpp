// #include <iostream>
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// // void read(int &x) {
// //  char ch = getchar(); x = 0;
// //  for (; ch < '0' || ch > '9'; ch = getchar());
// //  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// // }
// int dp[121][121];
// int main()
// {
//     std::ios::sync_with_stdio(false);
// #ifdef test
//     freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
//     freopen("/home/time/debug/debug/in", "r", stdin);
//     freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
//     int n = 121;
//     int i, j;
//     wfor(i, 1, 121)
//     {
//         dp[1][i] = dp[i][1] = 1;
//     }
//     wfor(i, 2, 121)
//     {
//         wfor(j, 2, 121)
//         {
//             if (i == j)
//                 dp[i][j] = dp[i][j - 1] + 1;
//             else if (i < j)
//                 dp[i][j] = dp[i][i];
//             else
//                 dp[i][j] = dp[i][j - 1] + dp[i - j][j];
//         }
//     }
//     while (cin >> n)
//     {
//         cout << dp[n][n] << endl;
//     }
//     return 0;
// }
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//     char ch = getchar(); x = 0;
//     for (; ch < '0' || ch > '9'; ch = getchar());
//     for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int dp[121];
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
    int i, j;
    dp[0] = 1;
    wfor(i, 1, 121)
    {
        wfor(j, i, 121)
        {
            dp[j] = dp[j] + dp[j - i];
        }
    }
    int n;
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}