#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
struct node {
    int l, r;
    ll sum, tmax, lmax, rmax;
}tr[N * 4];
int n, m, a[N];

void pushup(node &root, node &l, node &r)
{
    root.sum = l.sum + r.sum;
    root.lmax = max(l.lmax, l.sum + r.lmax);
    root.rmax = max(r.rmax, r.sum + l.rmax);
    root.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, a[r], a[r], a[r], a[r]};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int v)
{
    if (tr[u].l == tr[u].r) {
        tr[u] = {x, x, v, v, v, v};
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) modify(u << 1, x, v);
    else modify(u << 1 | 1, x, v);
    pushup(u);
}

node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid) return query(u << 1, l, r);
    else if (l > mid) return query(u << 1 | 1, l, r);
    else {
        node left, right, res;
        left = query(u << 1, l, r);
        right = query(u << 1 | 1, l, r);
        pushup(res, left, right);
        return res;
    } 
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1) {
            if (x > y) swap(x, y);
            cout << query(1, x, y).tmax << "\n";
        }
        else {
            modify(1, x, y);
        }
    }
    return 0;
}