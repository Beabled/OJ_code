#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, p;

ll power(ll a, ll b, ll p)
{
    ll res = 1 % p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> p;
    cout << power(a, b, p) << "\n";
    return 0;
}