#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int c[N], r[N], n, m, t;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> t;
    if (t == 0)
    {
        cout << "both 0\n";
        return 0;
    }
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;
        c[a]++, r[b]++;
    }
    bool f1 = true, f2 = true;
    if (t % n != 0) f1 = false;
    if (t % m != 0) f2 = false;
    long long res = 0;
    if (f1)
    {
        int k = t / n;
        for (int i = 1; i <= n; i++) c[i] -= k, c[i] += c[i - 1];
        sort(c + 1, c + 1 + n);
        for (int i = 1; i <= n; i++) res += abs(c[i] - c[(n + 1) / 2]);
    }
    if (f2)
    {
        int k = t / m;
        for (int i = 1; i <= m; i++) r[i] -= k, r[i] += r[i - 1];
        sort(r + 1, r + 1 + m);
        for (int i = 1; i <= m; i++) res += abs(r[i] - r[(m + 1) / 2]);
    }
    if (f1 && f2) cout << "both " << res;
    else if (f1) cout << "row " << res;
    else if (f2) cout << "column " << res;
    else cout << "impossible";
    return 0;
}