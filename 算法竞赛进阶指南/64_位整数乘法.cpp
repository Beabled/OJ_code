#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, p;

ll mul(ll a, ll b, ll p)
{
    ll res = 0;
    while (b)
    {
        if (b & 1) res = (res + a) % p;
        a = (a * 2) % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> p;
    cout << mul(a, b, p) << "\n";
    return 0;
}