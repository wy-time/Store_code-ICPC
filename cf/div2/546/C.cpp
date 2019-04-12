#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 505;
int A[maxn][maxn];
int B[maxn][maxn];
int vis[maxn][maxn];
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
    wfor(i, 0, n)
    {
        wfor(j, 0, m)
        cin >> A[i][j];
    }
    wfor(i, 0, n)
    {
        wfor(j, 0, m)
        cin >> B[i][j];
    }
    map<int, int>st;
    int flag = 1;
    wfor(i, 0, n)
    {
        wfor(j, 0, m)
        {
            st.clear();
            int y = j;
            int x = i;
            if (vis[x][y] == 1)
                continue;
            while (x < n && y >= 0)
            {
                vis[x][y] = 1;
                if (st.count(A[x][y]) == 0)
                    st.insert(make_pair(A[x][y], 1));
                else
                    st[A[x][y]]++;
                x++;
                y--;
            }
            y = j;
            x = i;
            while (x < n && y >= 0)
            {
                int t = st.count(B[x][y]);
                if (t == 0 || st[B[x][y]] == 0)
                {
                    flag = 0;
                    break;
                } else
                    st[B[x][y]]--;
                x++;
                y--;
            }
            if (flag == 0)
                break;
        }

    }
    if (flag == 0)
        cout << "no" << endl;
    else
        cout << "yes" << endl;
    return 0;
}
