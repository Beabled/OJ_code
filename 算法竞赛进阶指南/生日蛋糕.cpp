#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n, m, res = 0x3f3f3f3f;
int minv[N], mins[N];
int r[N], h[N];

void dfs(int u, int v, int s)
{
    if (v + minv[u] > n) return;
    if (s + mins[u] >= res) return;
    if (s + (n - v) / r[u + 1] >= res) return;

    if (!u) {
        if (v == n) res = s;
        return;
    }

    for (int i = min(r[u + 1] - 1, (int)sqrt(n - v)); i >= u; i--) 
        for (int j = min(h[u + 1] - 1, (n - v) / (i * i)); j >= u; j--) {
            int t = 0;
            if (u == m) t = i * i;
            r[u] = i, h[u] = j;
            dfs(u - 1, v + i * i * j, s + 2 * i * j + t);
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }
    r[m + 1] = h[m + 1] = res;
    dfs(m, 0, 0);
    if (res == 0x3f3f3f3f) cout << 0 << "\n";
    else cout << res << "\n";
    return 0;
}