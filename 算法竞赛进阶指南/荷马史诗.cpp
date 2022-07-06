#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    cin >> n >> m;
    for (ll i = 1, x; i <= n; i++) cin >> x, q.push({x, 0});
    while ((n - 1) % (m - 1)) {
        q.push({(ll)0, (ll)0});
        n++;
    }
    ll res = 0;
    while (q.size() > 1) {
        ll sum = 0, deep = 0;
        for (int i = 0; i < m; i++) {
            pii now = q.top();
            q.pop();
            sum += now.x;
            deep = max(deep, now.y);
        }
        res += sum;
        q.push({sum, deep + 1});
    }
    cout << res << "\n" << q.top().y << "\n";
    return 0;
}