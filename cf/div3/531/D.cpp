#include <iostream>
#include <string>
#include <set>
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
set<int>pos[3];
int cnt[3];
void gao(int ma, int mi, string &s, int flag)
{
    set<int>::iterator it;
    if (flag == 1)
    {
        it = pos[ma].end();
        it--;
    }
    else
        it = pos[ma].begin();
    s[*it] = mi + '0';
    cnt[ma]--;
    cnt[mi]++;
    pos[ma].erase(it);
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i;
    wfor(i, 0, n)
    {
        pos[s[i] - '0'].insert(i);
        cnt[s[i] - '0']++;
    }
    int need = n / 3;
    while (cnt[0] != cnt[1] || cnt[1] != cnt[2] || cnt[0] != cnt[2])
    {
        while (cnt[2] < need)
        {
            while (cnt[0] > need && cnt[2] < need)
            {
                gao(0, 2, s, 1);
            }
            while (cnt[1] > need && cnt[2] < need)
            {
                gao(1, 2, s, 1);
            }
        }
        while (cnt[0] < need)
        {
            while (cnt[1] > need && cnt[0] < need)
            {
                gao(1, 0, s, 0);
            }
            while (cnt[2] > need && cnt[0] < need)
            {
                gao(2, 0, s, 0);
            }
        }
        while (cnt[1] < need)
        {
            while (cnt[0] > need && cnt[1] < need)
            {
                gao(0, 1, s, 1);
            }
            while (cnt[2] > need && cnt[1] < need)
            {
                gao(2, 1, s, 0);
            }
        }
    }
    cout << s << endl;
    return 0;
}
