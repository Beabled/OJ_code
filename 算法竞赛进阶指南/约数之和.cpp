#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, p = 9901;

ll power(ll a, ll b, ll p)
{
    ll res = 1 % p;
    while (b)
    {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

ll sum(ll p, ll c, ll mod)
{
    if (c == 0) return 1;
    if (c & 1) return (1 + power(p, (c + 1) / 2, mod)) * sum(p, (c - 1) / 2, mod) % mod;
    return (1 + power(p, c / 2, mod)) * sum(p, c / 2 - 1, mod) * power(p, c, mod) % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b;
    cout << sum(a, b, p) << "\n";
    return 0;
}