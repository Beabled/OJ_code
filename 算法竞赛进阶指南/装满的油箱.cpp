#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, p[N];
vector<pair<int, int>> g[N];
int Q, c, s, e;
int d[N][110];
bool st[N][110];
struct rec { 
    int x, f, v; 
    bool operator < (const rec &x) const {
        return v > x.v;
    }
};

int bfs()
{
    memset(d, 0x3f, sizeof d);
    memset(st, false, sizeof st);
    priority_queue<rec> q;
    q.push({s, 0, 0});
    d[s][0] = 0;
    while (q.size()) {
        rec now = q.top(); q.pop();
        if (now.x == e) {
            return now.v;
        }
        if (st[now.x][now.f]) continue;
        st[now.x][now.f] = true;
        if (now.f < c && d[now.x][now.f + 1] > now.v + p[now.x]) {
            d[now.x][now.f + 1] = now.v + p[now.x];
            q.push({now.x, now.f + 1, d[now.x][now.f + 1]});
        }
        for (auto e: g[now.x]) {
            if (e.second <= now.f && d[e.first][now.f - e.second] > now.v) {
                d[e.first][now.f - e.second] = now.v;
                q.push({e.first, now.f - e.second, now.v});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    while (m--) {
        int a, b, v;
        cin >> a >> b >> v;
        a++, b++;
        g[a].push_back({b, v}), g[b].push_back({a, v});
    }
    cin >> Q;
    while (Q--) {
        cin >> c >> s >> e;
        s++, e++;
        int res = bfs();
        if (res == -1) cout << "impossible\n"; else cout << res << "\n";
    }
    return 0;
}