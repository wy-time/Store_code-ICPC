#include <iostream>
#include <cstring>
#include <list>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch= getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 2e5 + 5;
int pre[maxn];
int findx(int x)
{
    int i = x;
    while (pre[i] != i)
    {
        i = pre[i];
    }
    int j;
    while (pre[x] != i)
    {
        j = pre[x];
        pre[x] = i;
        x = j;
    }
    return i;
}
void add(int a, int b)
{
    int a1 = findx(a);
    int b1 = findx(b);
    pre[b1] = a1;
}
list<int>L[maxn];
int pos[maxn];
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
        pre[i] = i;
    }
    memset(pos, -1, sizeof(pos));
    int ans = 0;
    wfor(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        if (findx(a) != findx(b))
        {
            if (pos[a] == -1 && pos[b] == -1)
            {
                pos[a] = pos[b] = findx(a);
                L[pos[a]].push_back(a);
                L[pos[a]].push_back(b);
                ans = pos[a];
            } else if (pos[a] != -1 && pos[b] != -1)
            {
                int p1 = findx(a);
                int p2 = findx(b);
                L[p1].splice(L[p1].end(), L[p2]);
                ans = p1;
            } else
            {
                if (pos[a] == -1)
                    swap(a, b);
                int p = findx(a);
                L[p].push_back(b);
                pos[a] = pos[b] = p;
            }
            add(a, b);
        }
    }
    while (!L[ans].empty())
    {
        cout << L[ans].front() << " ";
        L[ans].pop_front();
    }
    return 0;
}
