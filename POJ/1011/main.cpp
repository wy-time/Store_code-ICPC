#include <iostream>
#include<algorithm>
using namespace std;
bool dfs (int *a, int minx, int n, bool *b, int sum, int times, int last);
bool cmp (int a, int b)
{
    return a > b;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n = 1;
    int a[70] = {0};
    bool b[70] = {true};
    while (cin >> n && n)
    {
        bool flag = false;
        int i;
        int maxx = 0;
        int minx = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (minx < a[i])
                minx = a[i];
            maxx += a[i];
            b[i] = true;
        }
        sort(a, a + n, cmp);
        for (i = minx; i <= maxx / 2; i++)
        {
            if (maxx % i != 0)
            {
                continue;
            }
            if (dfs(a, i, n, b, 0, 0, 0))
            {
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << maxx << endl;
    }
    return 0;
}
bool dfs (int *a, int minx, int n, bool *b, int sum, int times, int last)
{
    int i;
    times++;
    int s = 0;
    if (sum == minx)
    {
        sum = 0;
    }
    if (sum != 0)
    {
        s = last + 1;
    }
    if (times == n)
    {
        for (i = s; i < n; i++)
        {
            if (b[i])
            {
                sum += a[i];
                if (sum == minx)
                    return true;
            }
        }
    }
    else
    {
        for (i = s; i < n; i++)
        {
            if (i > 0 && b[i - 1] && a[i] == a[i - 1])
                continue;
            if (b[i])
            {
                sum += a[i];
                if (sum <= minx)
                {
                    b[i] = false;
                    last = i;
                    if (dfs(a, minx, n, b, sum, times, last))
                        return true;
                    else
                    {
                        b[i] = true;
                        sum -= a[i];
                        if (sum == 0 || a[i] == (minx - sum)) return false;
                        continue;
                    }
                }
                else if (sum > minx)
                {
                    sum -= a[i];
                    continue;
                }
            }
        }
    }
    return false;
}
