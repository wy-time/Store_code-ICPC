#include <iostream>
#include <queue>
#include <vector>
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
int toop(vector<int> G[2020], int n)
{
    int i;
    int deg[2020] = {0};
    queue<int>qu;
    wfor(i, 1, n + 1)
    {
        int len = G[i].size();
        int j;
        wfor(j, 0, len)
        {
            deg[G[i][j]]++;
        }
    }
    int cnt = 0;
    wfor(i, 1, n + 1)
    {
        if (deg[i] == 0)
        {
            cnt++;
            qu.push(i);
        }
    }
    while (!qu.empty())
    {
        int v = qu.front();
        qu.pop();
        int len = G[v].size();
        wfor(i, 0, len)
        {
            deg[G[v][i]]--;
            if (deg[G[v][i]] == 0)
            {
                qu.push(G[v][i]);
                cnt++;
            }
        }
    }
    if (cnt == n)
        return 1;
    else
        return 0;
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
    int t;
    cin >> t;
    while (t--)
    {
        vector<int>G1[2020];
        vector<int>G2[2020];
        vector<int>G3[2020];
        int n;
        cin >> n;
        int i, j;
        wfor(i, 1, n + 1)
        {
            wfor(j, 1, n + 1)
            {
                char c;
                cin >> c;
                switch (c)
                {
                case 'P':
                    G1[i].push_back(j);
                    G2[i].push_back(j);
                    G3[j].push_back(i);
                    break;
                case 'Q':
                    G1[i].push_back(j);
                    G2[j].push_back(i);
                    G3[i].push_back(j);
                }
            }
        }
        if (toop(G1, n) && toop(G2, n) && toop(G3, n))
        {
            cout << "T" << endl;
        } else
            cout << "N" << endl;
    }
    return 0;
}
