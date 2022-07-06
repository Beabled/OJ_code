#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7, mod = 1e9 + 7;
int h[N], e[N * 2], ne[N * 2], idx;
int s[N], f[N];
int n;
ll res = 0;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int find(int x)
{
	return f[x] == x ? x : find(f[x]);
}

int main()
{
	memset(h, -1, sizeof h);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);
		add(a, b);
	}
	for (int i = 1; i <= n; i++) f[i] = i, s[i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = h[i]; j != -1; j = ne[i]) {
			int fx = find(i), fy = find(e[i]);
			if (fx != fy) {
				res = (res + s[fx] * s[fy] * i) % mod;
				s[fx] += s[fy];
				f[fy] = fx;
			}
		}
	}
	cout << res << "\n";
	return 0;
}