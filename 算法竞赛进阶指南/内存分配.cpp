#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
int n, t, m, p, res1, res2;
queue<pii> wait;
set<pii> endt;
priority_queue<pii, vector<pii>, greater<pii>> q;

bool give(int t, int m, int p)
{
    for (auto it = endt.begin(); it != endt.end(); it++) {
        auto tt = it;
        tt++;
        if (tt != endt.end()) {
            if (m <= tt->x - (it->x + it->y)) {
                int c = it->x + it->y;
                endt.insert({c, m});
                q.push({t + p, c});
                return true;
            }
        }
    }
    return false;
}

void finish(int t)
{
    while (!q.empty() && q.top().x <= t) {
        int c = q.top().x;
        while (!q.empty() && q.top().x == c) {
            pii d = q.top();
            q.pop();
            auto it = endt.lower_bound({d.y, 0});
            endt.erase(it);
        }
        res1 = c;
        while (wait.size()) {
            auto f = wait.front();
            if (give(c, f.x, f.y)) {
                wait.pop();
            }
            else break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    endt.insert({-1, 1}), endt.insert({n, 1});
    while (cin >> t >> m >> p, t || m || p) {
        finish(t);
        if (!give(t, m, p)) {
            wait.push({m, p});
            res2++;
        }
    }
    finish(2e9);
    cout << res1 << "\n" << res2 << "\n";
    return 0;
}