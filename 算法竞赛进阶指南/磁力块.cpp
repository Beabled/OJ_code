#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define ms(s) memset(s, 0, sizeof(s))
#define x first
#define y second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define dep(i,a,b) for(int i=(a);i>=(b);i--)
const int inf = 0x3f3f3f3f;
const int N = 250006, T = 80;
struct node {
	ll x, y, m, p, r;
}a[N];
int n, L[N], R[N], M[N];
bool st[N];

bool cmp1(node x, node y)
{
	return x.m < y.m;
}

bool cmp2(node x, node y)
{
	return (x.x - a[0].x) * (x.x - a[0].x) + (x.y - a[0].y) * (x.y - a[0].y) < (y.x - a[0].x) * (y.x - a[0].x) + (y.y - a[0].y) * (y.y - a[0].y);
}

bool pd(node x, node y)
{
	return x.r * x.r >= (a[0].x - y.x) * (a[0].x - y.x) + (a[0].y - y.y) * (a[0].y - y.y);
}

int main() 
{
	int res = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> a[0].x >> a[0].y >> a[0].p >> a[0].r >> n;
	queue<int> q;
	q.push(0);
	for (int i = 1; i <= n; i++) {
		ll x, y;
		ll m, p, r;
		cin >> x >> y >> m >> p >> r;
		a[i] = {x, y, m, p, r};
	}
	sort(a + 1, a + 1 + n, cmp1);
	int t = sqrt(n);
	for (int i = 1; i <= t; i++) {
		L[i] = (i - 1) * t + 1;
		R[i] = i * t;
		M[i] = a[R[i]].m;
		sort(a + L[i], a + R[i] + 1, cmp2);
	}
	if (R[t] < n) {
		t++, L[t] = R[t - 1] + 1, R[t] = n;
		M[t] = a[R[t]].m;
		sort(a + L[t], a + R[t] + 1, cmp2);
	}
	while (q.size()) {
		int now = q.front();
		q.pop();
		int k = 0;
		for (int i = 1; i <= t; i++)
			if (M[i] <= a[now].p) k = i;
			else break;
		for (int i = 1; i <= k; i++) {
			while (L[i] <= R[i] && pd(a[now], a[L[i]])) {
				if (!st[L[i]]) {
					st[L[i]] = true;
					q.push(L[i]);
					res++;
				}
				L[i]++;
			}
		}
		if (t != k++) {
			for (int i = L[k]; i <= R[k]; i++) {
				if (!st[i] && a[now].p >= a[i].m && pd(a[now], a[i])) {
					st[i] = true;
					q.push(i);
					res++;
				}
			}
		}
	}
	cout << res << "\n";
    return 0;
}