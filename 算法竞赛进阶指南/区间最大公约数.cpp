#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
struct node {
    int l, r;
    ll dat;
}tr[N * 4];
int n, m;
ll a[N], b[N], tree[N];

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

void pushup(int u)
{
    tr[u].dat = gcd(tr[u << 1].dat, tr[u << 1 | 1].dat);
}   

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, b[r]};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, ll v)
{
    if (tr[u].l == tr[u].r) {
        tr[u].dat += v;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) modify(u << 1, x, v);
    else modify(u << 1 | 1, x, v);
    pushup(u);
}

ll query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].dat;
    ll val = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) val = gcd(val, query(u << 1, l, r));
    if (r > mid) val = gcd(val, query(u << 1 | 1, l, r));
    return val;
}

void add(ll x, ll v)
{
    for (ll i = x; i <= n; i += i&-i) tree[i] += v;
}

ll sum(ll x)
{
    ll res = 0;
    for (ll i = x; i; i -= i&-i) res += tree[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i] - a[i - 1];
    build(1, 1, n);
    while (m--) {
        string s;
        ll l, r, d;
        cin >> s;
        if (s == "Q") {
            cin >> l >> r;
            ll al = a[l] + sum(l);
            ll askl = l < r ? query(1, l + 1, r) : 0;
            cout << abs(gcd(al, askl)) << "\n";
        }
        else {
            cin >> l >> r >> d;
            modify(1, l, d);
            if (r + 1 <= n) modify(1, r + 1, -d);
            add(l, d), add(r + 1, -d);
        }
    }
    return 0;
}