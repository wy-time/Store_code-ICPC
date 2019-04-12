#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef struct
{
    ll a;
    ll b;
} st;
st info[20005];
bool cmp(st q, st w)
{
    long long a1, b1, a2, b2;
    a1 = q.a, b1 = q.b, a2 = w.a, b2 = w.b;
    if (a2 >= b1 && a1 > b2 && b2 < b1)
        return true;
    else if (a2 >= b1 && a1 < b2 && a1 < b1)
        return true;
    else if (a2 <= b1 && a1 > b2 && b2 < a2)
        return true;
    else if (a2 <= b1 && a1 < b2 && a1 < a2)
        return true;
    else
        return false;
    //return min(a.a, b.b) < min(a.b, b.a);
}
int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> info[i].a >> info[i].b;
        }
        sort(info, info + n, cmp);
        ll res = info[0].a + info[0].b;
        ll sum = info[0].a;
        for (i = 1; i < n; i++)
        {
            res = max(res, sum + info[i].a) + info[i].b;
            sum += info[i].a;
        }
        cout << res << endl;
    }
}
