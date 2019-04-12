#include <iostream>
//#define test
using namespace std;
typedef struct
{
    int the_end;//�ߵĽ�β
    int w;//�ߵ�Ȩֵ
    int next;//��һ������edge�����е��±�
} EDGE;
EDGE edge[500005];
int head[500005];
int cnt;//�ߵ�����
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
    dis[s] = 0; //�Լ����Լ�����Ϊ0
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
    edge[++cnt].next = head[beg]; //�������ı߷���ǰ��һ���ߵ�ǰ�棬���������ߵ�next=ǰһ���ߵ��±�
    edge[cnt].the_end = the_end;
    edge[cnt].w = w;
    head[beg] = cnt; //�������ıߵ�λ�÷���head��
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
    cout << "������������������������������������ \n";
    cin >> s;
    for (int i = head[s]; i != 0; i = edge[i].next) { //i��ʼΪ��һ���ߣ�ÿ��ָ����һ��(��0Ϊ������־)���±��0��ʼ��nextӦ��ʼ��-1
        cout << "���: " << s << endl;
        cout << "�յ�: " << edge[i].the_end << endl;
        cout << "Ȩֵ: " << edge[i].w << endl << endl;
    }
}
#endif //test
