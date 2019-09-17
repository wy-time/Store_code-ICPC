#include<iostream>

typedef __int128 ll;
// typedef long long ll;

using namespace std;

void exgcd(ll a, ll b, ll &g, ll &x, ll &y) {
    if (b == 0) {
        g = a;
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, g, y, x);
    y -= (a / b) * x;
}

bool flag = false;

ll a1, a2, n1, n2;

ll abs(ll x) {
    return x > 0 ? x : -x;
}

void china() {
    ll d = a2 - a1;
    ll g, x, y;
    exgcd(n1, n2, g, x, y);
    if (d % g == 0) {
        x = ((x * d / g) % (n2 / g) + (n2 / g)) % (n2 / g);
        a1 = x * n1 + a1;
        n1 = (n1 * n2) / g;
    }
    else
        flag = true;
}

int n;

long long as[20];

long long ns[20];

ll realchina() {
    a1 = as[0];
    n1 = ns[0];
    for (ll i = 1; i < n; i++) {
        a2 = as[i];
        n2 = ns[i];
        china();
        if (flag)
            return -1;
    }
    return a1;
}
ll fib[90];
void init()
{
    fib[1] = fib[2] = 1;
    int i;
    for (i = 3; i < 90; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        // cout << fib[i] << endl;
    }
}
int main() {
    cin >> n;
    flag = false;
    init();
    for (ll i = 0; i < n; i++)
        cin >> ns[i] >> as[i];
    ll ans = realchina();
    if (ans == -1)
        cout << "Tankernb!" << endl;
    else
    {
        int i;
        int flag = 1;
        for (i = 1; i < 90; i++)
        {
            if (fib[i] == ans)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "Zgxnb!" << endl;
        else
            cout << "Lbnb!" << endl;
    }
}
