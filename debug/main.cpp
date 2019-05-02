#include <iostream>
#include <cstring> 
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
int ma[16][16];
int main()
{
//     std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    int t;
    // cin >> t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, k;
        // cin >> n >> m >> k;
        scanf("%d %d %d", &n, &m, &k);
        memset(ma,0,sizeof(ma));
        int i, j;
        int cnt = (n-2)*(m-2)-k;
        mfor(j,m-1,2)
        {
            wfor(i,1,n-1)
            {
                if(cnt>0)
                {
                    ma[i][j]=1;
                    cnt--;
                }
                if(cnt<=0)
                    break;
            }
            if(cnt<=0)
                break;
        }
        wfor(i, 0, n)
        {
            wfor(j, 0, m - 1)
            {
                // cout << ma[i][j] << " ";
                printf("%d ", ma[i][j]);
            }
            // cout << ma[i][j] << endl;
            printf("%d\n", ma[i][j]);
        }
    }
    return 0;
}
