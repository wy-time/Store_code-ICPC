#include <iostream>
#include <queue>
#include <algorithm>
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
const int maxn = 2e5 + 5;
int ans[maxn];
struct st
{
    int num;
    int id;
};
struct rule
{
    bool operator()(const st &a, const st&b)
    {
        return a.num < b.num;
    }
};
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
    int n, k;
    cin >> n >> k;
    int i;
    priority_queue<st, vector<st>, rule>qu;
    st num;
    wfor(i, 0, n)
    {
        cin >> num.num;
        num.id = i;
        qu.push(num);
    }
    int flag = 1;
    wfor(i, 0, n)
    {
        if (qu.empty())
            break;
        num = qu.top();
        qu.pop();
        while (ans[num.id] != 0 && !qu.empty())
        {
            num = qu.top();
            qu.pop();
        }
        int cnt = 0;
        int pos = num.id;
        if (ans[pos] == 0)
            ans[pos] = flag;
        while (cnt < k)
        {
            if (ans[pos] == 0)
            {
                ans[pos] = flag;
                cnt++;
            }
            pos++;
            if (pos >= n)
                break;
        }
        cnt = 0;
        pos = num.id;
        while (cnt < k)
        {
            if (ans[pos] == 0)
            {
                ans[pos] = flag;
                cnt++;
            }
            pos--;
            if (pos < 0)
                break;
        }
        flag = flag == 1 ? 2 : 1;
    }
    wfor(i, 0, n)
    {
        cout << ans[i];
    }
    return 0;
}
