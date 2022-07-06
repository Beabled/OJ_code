#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, T = 1000;
int n, m;
int g[T][N], d[T][T], pos[N], L[T], R[T];
int a[N], f[N], b[N], c[N];

void pre(int x)
{
    pair<int, int> res = {0, -1};
    int tt = 0;
    for (int i = L[x]; i <= n; i++) {
        g[x][a[i]]++;
        b[a[i]]++;
        if (b[a[i]] == 1) {
            c[++tt] = a[i];
        }
        if (b[a[i]] > res.first || (b[a[i]] == res.first && a[i] < res.second)) {
            res.first = b[a[i]];
            res.second = a[i];
        }
        d[x][pos[i]] = res.second;
    }
    while (tt) {
        b[c[tt]] = 0;
        tt--;
    }
}

int query(int l, int r)
{
    int p = pos[l], q = pos[r];
    if (q == p) {
        int tt = 0;
        int res = 0, ma = -1;
        for (int i = l; i <= r; i++) {
            b[a[i]]++;
            if (b[a[i]] == 1) {
                c[++tt] = a[i];
            }
            if (b[a[i]] > ma || (b[a[i]] == ma && a[i] < res)) {
                ma = b[a[i]];
                res = a[i];
            }
        }
        while (tt) {
            b[c[tt]] = 0;
            tt--;
        }
        return res;
    }
    else {
        int tt = 0;
        int res = d[p + 1][q - 1];
        int ma = g[p + 1][res] - g[q][res];
        for (int i = l; i <= R[p]; i++) {
            b[a[i]]++;
            if (b[a[i]] == 1) {
                c[++tt] = a[i];
            }
        } 
        for (int i = L[q]; i <= r; i++) {
            b[a[i]]++;
            if (b[a[i]] == 1) {
                c[++tt] = a[i];
            }
        }
        while (tt) {
            int x = c[tt--];
            b[x] += g[p + 1][x] - g[q][x];
            if (b[x] > ma || (b[x] == ma && x < res)) {
                res = x;
                ma = b[x];
            }
            b[x] = 0;
        }
        return res;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], f[i] = a[i];
    int t = sqrt(n);
    for (int i = 1; i <= t; i++) {
        L[i] = (i - 1) * sqrt(n) + 1;
        R[i] = i * sqrt(n);
    }
    if (R[t] < n) t++, L[t] = R[t - 1] + 1, R[t] = n;
    for (int i = 1; i <= t; i++)
        for (int j = L[i]; j <= R[i]; j++) {
            pos[j] = i; 
        }
    sort(f + 1, f + 1 + n);
    int cnt = unique(f + 1, f + 1 + n) - f - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(f + 1, f + 1 + cnt, a[i]) - f;
    }
    for (int i = 1; i <= t; i++) pre(i);
    int res = 0;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l = (l + res - 1) % n + 1, r = (r + res - 1) % n + 1;
        if (l > r) swap(l, r);
        res = f[query(l, r)];
        cout << res << "\n";
    }
    return 0;
}