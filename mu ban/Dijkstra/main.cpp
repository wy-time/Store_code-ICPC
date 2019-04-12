#include <iostream>
//#define test
using namespace std;
typedef struct
{
    int the_end;//边的结尾
    int w;//边的权值
    int next;//下一条边在edge数组中的下标
} EDGE;
EDGE edge[500005];
int head[500005];
int cnt;//边的条数
void add(int beg, int the_end, int w);
void dijkstra(int s, int n);
const unsigned int INF = 2147483647;
unsigned int dis[10005];
bool vis[10005];
#ifdef test
void Print();
#endif // test
int main()
{
    std::ios::sync_with_stdio(false);
    int n, m, s;
    cin >> n >> m >> s;
    fill(dis + 1, dis + 1 + n, INF);
    dis[s] = 0; //自己到自己距离为0
    int i;
    for (i = 0; i < m; i++)
    {
        int f, g, w;
        cin >> f >> g >> w;
        add(f, g, w);
        add(g, f, w);
    }
    dijkstra(s, n);
    // #ifdef test
    // Print();
    // #endif // test
    for (i = 1; i <= n; i++)
        cout << dis[i] << " ";
    return 0;
}
void add(int beg, int the_end, int w)
{
    edge[++cnt].next = head[beg]; //将后加入的边放在前面一条边的前面，即让这条边的next=前一条边的下标
    edge[cnt].the_end = the_end;
    edge[cnt].w = w;
    head[beg] = cnt; //将后加入的边的位置放在head中
}
void dijkstra(int s, int n)
{
    int i, j;
    for (j = 1; j <= n; j++)
    {
        vis[s] = true;
        for (i = head[s]; i != 0; i = edge[i].next)
        {
            if (!vis[edge[i].the_end] && edge[i].w + dis[s] < dis[edge[i].the_end])
                dis[edge[i].the_end] = edge[i].w + dis[s];
        }
        unsigned int temp = INF;
        for (i = 1; i <= n; i++)
        {
            if (!vis[i] && temp > dis[i])
            {
                s = i;
                temp = dis[i];
            }
        }
    }
}
#ifdef test
void Print() {
    int s;
    cout << "—————————————————— \n";
    cin >> s;
    for (int i = head[s]; i != 0; i = edge[i].next) { //i开始为第一条边，每次指向下一条(以0为结束标志)若下标从0开始，next应初始化-1
        cout << "起点: " << s << endl;
        cout << "终点: " << edge[i].the_end << endl;
        cout << "权值: " << edge[i].w << endl << endl;
    }
}
#endif //test
