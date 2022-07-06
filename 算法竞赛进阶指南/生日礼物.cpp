#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct node {
    int v, id;
    bool operator< (const node &x) const {
        return v > x.v;
    }
};
int n, m, a[N], l[N], r[N];
bool st[N];
priority_queue<node> q;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if ((long long)a[k] * x < 0) a[++k] = x;
        else a[k] += x;
    }
    int res = 0, cnt = 0;
    for (int i = 1; i <= k; i++)
        if (a[i] > 0) cnt++, res += a[i];
    for (int i = 1; i <= k; i++) q.push({abs(a[i]), i}), l[i] = i - 1, r[i] = i + 1;
    while (cnt > m) {
        node t = q.top();
        q.pop();
        if (st[t.id]) continue;
        if (l[t.id] != 0 && r[t.id] != k + 1 || a[t.id] > 0) {
            res -= t.v;
            cnt--;
            int c = t.id;
            st[l[c]] = st[r[c]] = true;
            a[c] += a[l[c]] + a[r[c]];
            q.push({abs(a[c]), t.id});
            int x = l[c], y = r[c];
            l[r[x]] = l[x], r[l[x]] = r[x];
            l[r[y]] = l[y], r[l[y]] = r[y];
            
        }
    }
    cout << res << "\n";
    return 0;
}