// #include <iostream>
// #include <cstdio>
// #include <queue>
// #include <cstring>
// #include <cmath>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// // void read(int &x) {
// //  char ch = getchar(); x = 0;
// //  for (; ch < '0' || ch > '9'; ch = getchar());
// //  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// // }
// struct PATH
// {
//     int path[1005];
//     int w;
// };
// PATH path[1000];
// int pathcnt;
// const int maxn = 5005;
// int p;
// int pre[1005];
// struct EDGE
// {
//     int first;
//     int _end;
//     int w;
//     int next;
// };
// struct node
// {
//     int w;
//     int input[10];
//     int output[10];
// };
// node info[1000];
// EDGE edge[maxn];
// int head[1005];
// int cnt = -1;
// int dft[1005];
// void add(int beg, int _end, int w)
// {
//     edge[++cnt].next = head[beg];
//     edge[cnt].w = w;
//     edge[cnt]._end = _end;
//     edge[cnt].first = beg;
//     head[beg] = cnt;
// }
// int check(int *a, int *b)
// {
//     int i;
//     wfor(i, 0, p)
//     {
//         if (a[i] != b[i] && b[i] != 2 && a[i] != 2)
//             return 0;
//     }
//     return 1;
// }
// int bfs(int beg, int _end)
// {
//     queue<int>qu;
//     memset(dft, 0, sizeof(dft));
//     qu.push(beg);
//     dft[beg] = 1;
//     while (!qu.empty())
//     {
//         int temp = qu.front();
//         qu.pop();
//         for (int i = head[temp]; i != -1; i = edge[i].next)
//         {
//             int v = edge[i]._end;
//             if (edge[i].w <= 0 || dft[v]) continue;
//             dft[v] = dft[temp] + 1;
//             qu.push(v);
//         }
//     }
//     return dft[_end];
// }
// int dfs(int beg, int _end, int flow)
// {
//     int ans = 0;
//     int i;
//     if (beg == _end)
//     {
//         if (flow != 0)
//         {
//             path[pathcnt].w = flow;
//             memmove(path[pathcnt++].path, pre, sizeof(pre));
//         }
//         return flow;
//     }
//     for (i = head[beg]; i != -1; i = edge[i].next)
//     {
//         int v = edge[i]._end;
//         if (edge[i].w <= 0 || dft[v] != dft[beg] + 1) continue;
//         pre[v] = beg;
//         int temp = dfs(v, _end, min(edge[i].w, flow - ans));
//         ans += temp;
//         edge[i].w -= temp;
//         edge[i ^ 1].w += temp;
//     }
//     return ans;
// }
// int dinic(int beg, int _end)
// {
//     int ans = 0;
//     while (bfs(beg, _end))
//     {
//         memset(pre, -1, sizeof(pre));
//         ans += dfs(beg, _end, 0x7f7f7f7f);
//     }
//     return ans;
// }
// int main ()
// {
//     int n;
//     while (cin >> p >> n)
//     {
//         int i;
//         int j;
//         memset(head, -1, sizeof(head));
//         memset(info, 0, sizeof(info));
//         cnt = -1;
//         pathcnt = 0;
//         wfor(i, 0, n)
//         {
//             cin >> info[i].w;
//             wfor(j, 0, p)
//             {
//                 cin >> info[i].input[j];
//             }
//             wfor(j, 0, p)
//             {
//                 cin >> info[i].output[j];
//             }
//             add(i + 1, i + 1 + n, info[i].w);
//         }
//         int beg[15] = {0};
//         int _end[15];
//         fill(_end, _end + 15, 1);
//         wfor(i, 0, n)
//         {
//             if (check(info[i].input, beg))
//             {
//                 add(0, i + 1, info[i].w);
//                 add(i + 1, 0, 0);
//             }
//             if (check(info[i].output, _end))
//             {
//                 add(i + 1 + n, 2 * n + 1, info[i].w);
//                 add(2 * n + 1, i + 1 + n, 0);
//             }
//             wfor(j, 0, n)
//             {
//                 if (j == i) continue;
//                 if (check(info[i].output, info[j].input))
//                 {
//                     add(i + 1 + n, j + 1, min(info[i].w, info[j].w));
//                     add(j + 1, i + 1 + n, 0);
//                 }
//             }
//         }
//         cout << dinic(0, 2 * n + 1) << " " ;
//         int shortpath = 0;
//         wfor(i, 0, pathcnt)
//         {
//             int tt = 2 * n + 1;
//             while (path[i].path[tt] != 0 && path[i].path[path[i].path[tt]] != 0)
//             {
//                 if (abs(path[i].path[tt] - path[i].path[path[i].path[tt]]) != n)
//                     shortpath++;
//                 tt = path[i].path[tt];
//             }
//         }
//         cout << shortpath << endl;
//         wfor(i, 0, pathcnt)
//         {
//             int tt = 2 * n + 1;
//             while (path[i].path[tt] != 0 && path[i].path[path[i].path[tt]] != 0)
//             {
//                 if (abs(path[i].path[tt] - path[i].path[path[i].path[tt]]) != n)
//                 {
//                     cout << (path[i].path[path[i].path[tt]] > n ? path[i].path[path[i].path[tt]] - n : path[i].path[path[i].path[tt]]) << " " << (path[i].path[tt] > n ? path[i].path[tt] - n : path[i].path[tt]) << " " << path[i].w << endl;
//                 }
//                 tt = path[i].path[tt];
//             }
//         }
//     }
//     return 0;
// }
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
struct PATH
{
    int path[1005];
    int w;
};
PATH path[1000];
int pathcnt;
const int maxn = 5005;
int p;
int pre[1005];
struct EDGE
{
    int first;
    int _end;
    int w;
    int next;
};
struct node
{
    int w;
    int input[10];
    int output[10];
};
node info[1000];
EDGE edge[maxn];
int head[1005];
int cnt = -1;
int dft[1005];
void add(int beg, int _end, int w)
{
    edge[++cnt].next = head[beg];
    edge[cnt].w = w;
    edge[cnt]._end = _end;
    edge[cnt].first = beg;
    head[beg] = cnt;
}
int check(int *a, int *b)
{
    int i;
    wfor(i, 0, p)
    {
        if (a[i] != b[i] && b[i] != 2 && a[i] != 2)
            return 0;
    }
    return 1;
}
int bfs(int beg, int _end)
{
    queue<int>qu;
    memset(dft, 0, sizeof(dft));
    qu.push(beg);
    dft[beg] = 1;
    while (!qu.empty())
    {
        int temp = qu.front();
        qu.pop();
        for (int i = head[temp]; i != -1; i = edge[i].next)
        {
            int v = edge[i]._end;
            if (edge[i].w <= 0 || dft[v]) continue;
            dft[v] = dft[temp] + 1;
            qu.push(v);
        }
    }
    return dft[_end];
}
int dfs(int beg, int _end, int flow)
{
    int ans = 0;
    int i;
    if (beg == _end)
    {
        if (flow != 0)
        {
            path[pathcnt].w = flow;
            memmove(path[pathcnt++].path, pre, sizeof(pre));
        }
        return flow;
    }
    for (i = head[beg]; i != -1; i = edge[i].next)
    {
        int v = edge[i]._end;
        if (edge[i].w <= 0 || dft[v] != dft[beg] + 1) continue;
        pre[v] = beg;
        int temp = dfs(v, _end, min(edge[i].w, flow - ans));
        ans += temp;
        edge[i].w -= temp;
        edge[i ^ 1].w += temp;
    }
    return ans;
}
int dinic(int beg, int _end)
{
    int ans = 0;
    while (bfs(beg, _end))
    {
        memset(pre, -1, sizeof(pre));
        ans += dfs(beg, _end, 0x7f7f7f7f);
    }
    return ans;
}
int main ()
{
    int n;
    while (cin >> p >> n)
    {
        int i;
        int j;
        memset(head, -1, sizeof(head));
        memset(info, 0, sizeof(info));
        cnt = -1;
        pathcnt = 0;
        wfor(i, 0, n)
        {
            cin >> info[i].w;
            wfor(j, 0, p)
            {
                cin >> info[i].input[j];
            }
            wfor(j, 0, p)
            {
                cin >> info[i].output[j];
            }
        }
        int beg[15] = {0};
        int _end[15];
        fill(_end, _end + 15, 1);
        wfor(i, 0, n)
        {
            if (check(info[i].input, beg))
            {
                add(0, i + 1, info[i].w);
                add(i + 1, 0, 0);
            }
            if (check(info[i].output, _end))
            {
                add(i + 1, n + 1, info[i].w);
                add(n + 1, i + 1, 0);
            }
            wfor(j, 0, n)
            {
                if (j == i) continue;
                if (check(info[i].output, info[j].input))
                {
                    add(i + 1, j + 1, min(info[i].w, info[j].w));
                    add(j + 1, i + 1, 0);
                }
            }
        }
        cout << dinic(0, n + 1) << " " ;
        int shortpath = 0;
        wfor(i, 0, pathcnt)
        {
            int tt = n + 1;
            while (path[i].path[tt] != 0 && path[i].path[path[i].path[tt]] != 0)
            {
                shortpath++;
                tt = path[i].path[tt];
            }
        }
        cout << shortpath << endl;
        wfor(i, 0, pathcnt)
        {
            int tt = n + 1;
            while (path[i].path[tt] != 0 && path[i].path[path[i].path[tt]] != 0)
            {
                if (abs(path[i].path[tt] - path[i].path[path[i].path[tt]]) != n)
                {
                    cout << (path[i].path[path[i].path[tt]] > n ? path[i].path[path[i].path[tt]] - n : path[i].path[path[i].path[tt]]) << " " << (path[i].path[tt] > n ? path[i].path[tt] - n : path[i].path[tt]) << " " << path[i].w << endl;
                }
                tt = path[i].path[tt];
            }
        }
    }
    return 0;
}