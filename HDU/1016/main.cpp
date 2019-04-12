#include <iostream>
using namespace std;
void dfs (int *ans, int n, int times, bool*b);
bool isprime(int n);
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    int cnt = 1;
    while (cin >> n)
    {
        int ans[25] = {1};
        bool b[25];
        int i;
        for (i = 0; i <= n; i++)
        {
            b[i] = true;
        }
        b[1] = false;
        cout << "Case " << cnt << ":" << endl;
        if (n != 1)
            dfs(ans, n, 1, b);
        else
            cout << 1 << endl;
        cout << endl;
        cnt++;
    }
    return 0;
}
void dfs (int *ans, int n, int times, bool *b)
{
    times++;
    if (times == n)
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            if (b[i])
            {
                if (isprime(i + ans[times - 2]) && isprime(i + 1))
                {
                    ans[times - 1] = i;
                    int j;
                    for (j = 0; j < n - 1; j++)
                    {
                        cout << ans[j] << " ";
                    }
                    cout << ans[j] << endl;
                    return;
                }
            }
        }
    } else
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            if (b[i])
            {
                if (isprime(i + ans[times - 2]))
                {
                    b[i] = false;
                    ans[times - 1] = i;
                    dfs(ans, n, times, b);
                    b[i] = true;
                }
            }
        }
    }
}
bool isprime(int n)
{
    int i;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
