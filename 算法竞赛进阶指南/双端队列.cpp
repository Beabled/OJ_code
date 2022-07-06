#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 2e5 + 7;
map<ll, pii> s;
ll a[N];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (ll i = 1, x; i <= n; i++) {
        cin >> x, a[i] = x;
        if (!s[x].x) s[x].x = 1e18;
        if (!s[x].y) s[x].y = -1e18;
        s[x].x = min(s[x].x, i), s[x].y = max(s[x].y, i);
    }
    sort(a + 1, a + 1 + n);
    bool f = false;
    ll res = 1, now = 1e18, last = -1e18;
    for (int i = 1; i <= n; i++) { 
        ll e = a[i];
        if (e == last) continue;
        last = e;
        if (!f) {
            if (s[e].y <= now) now = s[e].x;
            else f = !f, now = s[e].y;
        }
        else {
            if (s[e].x >= now) now = s[e].y;
            else res++, f = !f, now = s[e].x;
        }
    }
    cout << res << "\n";
    return 0;
}