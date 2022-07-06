#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, res;
int main()
{
    cin >> n >> k; res = n * k;
    for (int x = 1, gx; x <= n; x = gx + 1) {
        gx = k / x ? min(k / (k / x), n) : n;
        res -= (k / x) * (x + gx) * (gx - x + 1) / 2;
    }
    cout << res << "\n";
    return 0;
}