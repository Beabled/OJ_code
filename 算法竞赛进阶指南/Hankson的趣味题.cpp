#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
const int N = 1e5 + 7;
int pri[N], diver[N];
int n, cnt, cntf, cntd;
pii factor[N];
bool v[N];

void primes(int n) 
{
    for (int i = 2; i <= n; i++) {
        if (!v[i]) pri[++cnt] = i;
        for (int j = 1; pri[j] * i <= n; j++) {
            v[pri[j] * i] = true;
            if (i % pri[j] == 0) break;
        }
    }
}

void dfs(int u, int v)
{
    if (u == cntf + 1) {
        diver[++cntd] = v;
        return;
    }
    for (int i = 0; i <= factor[u].y; i++) {
        dfs(u + 1, v);
        v *= factor[u].x;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    primes(N - 7);
    cin >> n;
    while (n--) {
        int a0, a1, b0, b1;
        cin >> a0 >> a1 >> b0 >> b1;
        cntf = 0;
        int d = b1;
        for (int i = 1; pri[i] <= d / pri[i]; i++) {
            if (d % pri[i] == 0) {
                int v = 0;
                while (d % pri[i] == 0) v++, d /= pri[i];
                factor[++cntf] = {pri[i], v};
            }
        }
        if (d > 1) factor[++cntf] = {d, 1};
        cntd = 0;
        dfs(1, 1);
        int res = 0;
        for (int i = 1; i <= cntd; i++) {
            int x = diver[i];
            if (__gcd(x, a0) == a1 && (long long)x * b0 / __gcd(x, b0) == b1) {
                res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}