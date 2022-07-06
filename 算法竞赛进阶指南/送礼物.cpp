#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50, M = 1e7 + 1;
int w, n, a[N], v[M], idx;
ll res;

void dfs1(int u, ll now)
{
    if (now > w) return;
    if (u == n / 2 + 1) {
        v[idx++] = now;
        return;
    }
    dfs1(u + 1, now + a[u]), dfs1(u + 1, now);
}

void dfs2(int u, ll now)
{
    if (now > w) return;
    if (u == n + 1) {
        int l = 0, r = idx - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (v[mid] + now > w) r = mid - 1;
            else l = mid;
        }
        if (v[r] + now <= w) res = max(res, now + v[r]);
        return;
    }
    dfs2(u + 1, now + a[u]), dfs2(u + 1, now);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> w >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    dfs1(1, 0);
    sort(v, v + idx);
    int k = idx, last = -1;
    idx = 0;
    for (int i = 0; i < k; i++)
        if (v[i] != last) v[idx++] = v[i], last = v[i]; 
    dfs2(n / 2 + 1, 0);
    cout << res << "\n";
    return 0;
}