#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
struct g {
    ll v, id;
    bool operator < (const g &x) const {
        return v > x.v;
    }
};
ll n, k, d[N], l[N], r[N];
bool st[N];
priority_queue<g> q;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = n - 1; i >= 1; i--) d[i] -= d[i - 1];
    d[0] = d[n] = 1e18;
    for (int i = 0; i <= n; i++) q.push({d[i], i}), l[i] = i - 1, r[i] = i + 1;
    ll res = 0;
    int idx = 0;
    while (idx < k) {
        g now = q.top();
        q.pop();
        ll j = now.id, v = now.v;
        if (st[j]) continue;
        res += v;
        d[j] = d[l[j]] + d[r[j]] - v;
        q.push({d[l[j]] + d[r[j]] - v, j});
        int x = l[l[j]], y = r[r[j]];
        r[x] = j, l[y] = j;
        st[l[j]] = st[r[j]] = true;
        l[j] = l[l[j]], r[j] = r[r[j]];
        idx++;
    }
    cout << res << "\n";
    return 0;
}