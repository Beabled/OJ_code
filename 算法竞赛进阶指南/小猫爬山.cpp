#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, w, c[N], cab[N], res = 18;

void dfs(int u, int cnt)
{
    if (cnt >= res) return;
    if (u == n + 1) {
        res = min(res, cnt);
        return;
    }
    for (int i = 1; i <= cnt; i++) {
        if (cab[i] + c[u] <= w) {
            cab[i] += c[u];
            dfs(u + 1, cnt);
            cab[i] -= c[u];
        }
    }
    cab[cnt + 1] = c[u];
    dfs(u + 1, cnt + 1);
    cab[cnt + 1] -= c[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> c[i];
    dfs(1, 0);
    cout << res << "\n";
    return 0;
}