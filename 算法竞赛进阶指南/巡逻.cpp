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
const int N = 1e5 + 7;
int h[N], e[N << 1], ne[N << 1], w[N << 1], idx;
int n, k, d[N];
pii res1, res2;
bool st[N], f[N];
vector<int> r;
int k1, k2 = -1e9;

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int dep)
{
	st[u] = true;
	if (dep > res1.x) res1 = {dep, u};
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!st[j]) {
			dfs1(j, dep + w[i]);
		}
	}
}

bool dfs2(int u, int end)
{
	st[u] = true;
	if (u == end) return true;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!st[j]) {
			w[i] = -1;
			if (dfs2(j, end)) return true;
			w[i] = 1;
		}
	}
	return false;
}

void dp(int x)
{
	st[x] = true;
	for (int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		if (st[j]) continue;
		dp(j);
		k2 = max(k2, d[x] + d[j] + w[i]);
		d[x] = max(d[x], d[j] + w[i]);
	}
}

int main() 
{
	memset(h, -1, sizeof h);
	/*ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);*/
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		cin >> a >> b;
		add(a, b, 1), add(b, a, 1);
	}
	int res = 2 * (n - 1);
	dfs1(1, 0);
	memset(st, false, sizeof st);
	res2 = res1;
	res1 = {0, 0};
	dfs1(res2.y, 0);
	res -= (res1.x - 1);
	k1 = res;
	memset(st, false, sizeof st);
	dfs2(res2.y, res1.y);
	memset(st, false, sizeof st);
	dfs2(res1.y, res2.y);
	memset(st, false, sizeof st);

	dp(1);
	if (k == 1) cout << k1 << "\n";
	else cout << k1 - k2 + 1 << "\n";
    return 0;
}