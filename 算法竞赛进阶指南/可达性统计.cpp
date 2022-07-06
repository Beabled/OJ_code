#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 7;
int n, m, d[N], seq[N];
int h[N], e[N], ne[N], idx = 1;
bitset<N> f[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!d[i]) q.push(i);
    int k = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        seq[++k] = t;
        for (int i = h[t]; i; i = ne[i]) {
            int j = e[i];
            d[j]--;
            if (!d[j]) q.push(j);
        }
    }
}

int main()
{
    memset(h, 0, sizeof h);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), d[b]++;
    }

    topsort();

    for (int i = n; i >= 1; i--) {
        int j = seq[i];
        f[j][j] = 1;
        for (int k = h[j]; k; k = ne[k]) f[j] |= f[e[k]];
    }

    for (int i = 1; i <= n; i++) cout << f[i].count() << "\n";
    return 0;
}