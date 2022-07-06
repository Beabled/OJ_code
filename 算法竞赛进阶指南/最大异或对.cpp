#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll h[N], e[N], ne[N], w[N], idx, tt;
ll n, d[N], son[N][2];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, ll v)
{
    st[u] = true;
    d[u] = v;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) dfs(j, v ^ w[i]);
    }
}

void insert(ll x)
{
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        int t = x >> i & 1;
        if (!son[p][t]) son[p][t] = ++tt;
        p = son[p][t];
    }
}

ll query(ll x)
{
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        ll t = x >> i & 1;
        if (son[p][!t]) x |= (1 << i), p = son[p][!t];
        else {
            if (x >> i & 1) x -= (1 << i);
            p = son[p][t];
        }
    } 
    return x;
}

int main()
{
    memset(h, -1, sizeof h);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    dfs(0, 0);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        insert(d[i]);
        res = max(res, query(d[i]));
    }
    cout << res << "\n";
    return 0;
}