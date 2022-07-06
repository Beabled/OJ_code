#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;
int v[N], pri[N], idx;
bool s[N];

void primes(int n)
{
    memset(v, 0, sizeof v);
    idx = 0;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) pri[++idx] = i;
        for (int j = 1; pri[j] * i <= n; j++) {
            v[pri[j] * i] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}

int main()
{
    ll l, r;
    while (cin >> l >> r) {
        memset(s, false, sizeof s);
        primes(50000);
        for (int i = 1; i <= idx; i++) {
            ll p = pri[i];
            for (ll j = max((l + p - 1) / p * p, 2ll * p); j <= r; j += p) {
                s[j - l] = true;
            }
        }
        idx = 0;
        for (int i = 0; i <= r - l; i++) 
            if (!s[i] && i + l > 1) pri[++idx] = i + l;
        pair<int, int> res1, res2;
        int mi = 1e9, ma = -1;
        for (int i = 1, last = -1; i <= idx; i++) {
            if (last == -1) last = pri[i];
            else {
                int now = pri[i] - last;
                if (now < mi) mi = now, res1 = {last, pri[i]};
                if (now > ma) ma = now, res2 = {last, pri[i]};
                last = pri[i]; 
            }
        }
        if (ma == -1) cout << "There are no adjacent primes.\n";
        else printf("%d,%d are closest, %d,%d are most distant.\n", res1.first, res1.second, res2.first, res2.second);
    }
    return 0;
}