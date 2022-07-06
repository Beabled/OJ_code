#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int n, k, x;
ll a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll res = 0, now = 2;
	a[0] = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (a[i] <= a[i + 1]) {
			if (now <= k) {
				ll x = min(res / a[i], k - now);
				res -= x * a[i], now += x; 
			}
		}
		else {
			res += a[i] * now;
			now = 0;
		}
	}
	if (now) res += a[n] * now;
	cout << res << "\n";
	return 0;
}