#include <iostream>
#include<cstring>
using namespace std;
int ma[5005][5005];
int mindis[10005];
bool vis[10005];
const int INF = 0x3f3f3f;
int main()
{
    std::ios::sync_with_stdio(false);
    memset(ma, INF, sizeof(ma));
    int n, m;
    cin >> n >> m;
    int i;
    for (i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ma[a][b] = ma[b][a] = min(c, min(ma[a][b], ma[b][a])); //输入到各个点的最小值
    }
    for (i = 1; i <= n; i++)
    {
        mindis[i] = ma[1][i]; //初始化最短距离数组，目前为第一个点到各个能到的点的最短距离，INF表示到不了
    }
    vis[1] = true; //第一个点已经走过
    bool liantong = true;
    long long cost = 0;
    for (i = 1; i < n; i++) //n个点的循环
    {
        int tempdis = INF;
        int k = -1;
        for (int j = 1; j <= n; j++) //找目前的最短距离
        {
            if (!vis[j] && mindis[j] < tempdis)
            {
                tempdis = mindis[j];
                k = j;
            }
        }
        if (k == -1)
        {
            liantong = false; //看是否连通
            break;
        }
        cost += tempdis;
        vis[k] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && mindis[j] > ma[k][j]) //因为加了一个点进来所以更新最短距离数组，最短距离数组是目前到各个点的最短值
                mindis[j] = ma[k][j];
        }
    }
    if (!liantong)
        cout << "orz" << endl;
    else
        cout << cost << endl;
    return 0;
}
