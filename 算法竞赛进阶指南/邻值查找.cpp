#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll n, a[N];
set<ll> s;
map<ll, ll> q;
vector<pair<ll, ll>> res;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], q[a[i]] = i, s.insert(a[i]);
    for (int i = n; i >= 2; i--) {
        ll x = a[i], x1 = -1e18, x2 = -1e18;
        auto t = s.find(x);
        if (t != s.begin()) {
            auto it = t;
            it--;
            x1 = *it;
        } 
        auto it = t;
        it++;
        if (it != s.end()) x2 = *it;
        if (abs(x - x1) <= abs(x2 - x)) res.push_back({abs(x - x1), q[x1]});
        else res.push_back({abs(x2 - x), q[x2]});
        s.erase(x);
    }
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i].first << " " << res[i].second << "\n";
    return 0;
}