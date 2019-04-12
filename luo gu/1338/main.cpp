#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void slove (int head, int tail, ll m, int l);
int ans[500005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    slove(0, n - 1, m, 1);
    int i;
    wfor(i, 0, n - 1)
    {
        cout << ans[i] << " ";
    }
    cout << ans[i];
    return 0;
}
void slove (int head, int tail, ll m, int l)
{
    if (m == 0 || head > tail)
    {
        int i;
        wfor(i, head, tail + 1)
        {
            ans[i] = l;
            l++;
        }
        return ;
    }
    ll len = tail - head + 1;
    if (len * (len - 1) / 2 >= m)
    {
        if ((len - 1) * (len - 2) / 2 >= m)
        {
            ans[head] = l;
            slove(head + 1, tail, m, l + 1);
        }
        else
        {
            ans[tail] = l;
            slove(head, tail - 1, m - (len - 1), l + 1);
        }
    }
}
/**
1 2 3 4 5 0
1 2 3 5 4 1
1 2 4 5 3 2
1 2 5 4 3 3
1 3 5 4 2 4
*/
