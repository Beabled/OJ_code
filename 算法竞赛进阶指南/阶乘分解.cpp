#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int pri[N], n, t, res[N];
bool v[N];

void primes(int n)
{
    memset(v, false, sizeof v);
    t = 0;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) pri[++t] = i;
        for (int j = 1; pri[j] * i <= n; j++) {
            v[pri[j] * i] = true;
            if (i % pri[j] == 0) break;
        }
    }
}

int main()
{
    cin >> n;
    primes(n);
    for (int i = 1; i <= t; i++) {
        int p = pri[i];
        for (long long j = p; j <= n; j *= p) res[i] += n / j;
    }
    for (int i = 1; i <= t; i++) cout << pri[i] << " " << res[i] << "\n";
    return 0;
}