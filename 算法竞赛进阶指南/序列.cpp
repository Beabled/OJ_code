#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
int t, n, m, a[N], b[N], ba[N];
struct node {
    int i, j;
    bool last;
    bool operator < (const node &x) const {
        return a[i] + b[j] > a[x.i] + b[x.j];
    }
};

void solve()
{
    priority_queue<node> q;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) cin >> b[j];
        sort(b + 1, b + n + 1);
        q.push({1, 1, false});
        for (int j = 1; j <= n; j++) {
            node now = q.top();
            q.pop();
            if (now.j + 1 <= n) q.push({now.i, now.j + 1, true});
            if (!now.last && now.i + 1 <= n) q.push({now.i + 1, now.j, false});
            ba[j] = a[now.i] + b[now.j];
        }
        while (!q.empty()) q.pop();
        memcpy(a, ba, sizeof ba);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t; while (t--) solve();
    return 0;
}