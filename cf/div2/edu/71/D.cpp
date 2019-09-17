#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
const int maxn = 3e5 + 5;
pair<int, int>num[maxn];
map<pair<int, int>, int >ma;
vector<pair<int, int>>v;
const ll mod = 998244353;
ll fac[maxn];
struct rule
{
    bool operator ()(const pair<int, int> &a, const pair<int, int>&b)
    {
        return a.second < b.second;
    }
};
void init()
{
    ll i;
    fac[0] = 1;
    wfor(i, 1, maxn)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
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
    int i;
    init();
    wfor(i, 0, n)
    {
        cin >> num[i].first >> num[i].second;
        ma[num[i]]++;
        v.push_back(num[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(num, num + n);
    int cnt = 1;
    ll ans1 = 1;
    ll ans2 = 1;
    int flag = 0;
    wfor(i, 1, n)
    {
        if (num[i].second < num[i - 1].second)
        {
            flag = 1;
            break;
        }
    }
    wfor(i, 1, n)
    {
        if (num[i].first == num[i - 1].first)
            cnt++;
        else
        {
            ans1 = ans1 * fac[cnt] % mod;
            cnt = 1;
        }
    }
    ans1 = ans1 * fac[cnt] % mod;
    sort(num, num + n, rule());
    cnt = 1;
    wfor(i, 1, n)
    {
        if (num[i].second == num[i - 1].second)
            cnt++;
        else
        {
            ans2 = ans2 * fac[cnt] % mod;
            cnt = 1;
        }
    }
    ans2 = ans2 * fac[cnt] % mod;
    if (flag == 0)
    {
        ll temp = 1;
        for (auto k : v)
            temp = temp * fac[ma[k]] % mod;
        ll ans = (ans1 + ans2 - temp + mod) % mod;
        cout << (fac[n] - ans + mod) % mod << endl;;
    } else
    {
        ll ans = (ans1 + ans2) % mod;
        cout << (fac[n] - ans + mod) % mod << endl;
    }
    return 0;
}
