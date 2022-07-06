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
const int N = 1e4 + 7;
int n, m, t, cnt;
int L[N], R[N], pre[N], in[N];
int d[N];
int f[N][50];
map<int, int> s, s2;

int mapping(int x)
{
	if (s.count(x)) return s[x];
	s2[++cnt] = x;
	return s[x] = cnt;
}

int build(int pl, int pr, int il, int ir)
{
	if (pl > pr) return 0;
	int root = pre[pl];
	int k = il;
	while (in[k] != root) k++;
	int lin = k - il;
	L[root] = build(pl + 1, pl + lin, il, k - 1);
	R[root] = build(pl + lin + 1, pr, k + 1, ir);
	return root;
}

void bfs(int x)
{
	queue<int> q;
	q.push(x); d[x] = 1;
	while (q.size()) {
		int now = q.front(); q.pop();
		if (L[now]) {
			int j = L[now];
			d[j] = d[now] + 1;
			f[j][0] = now;
			for (int i = 1; i <= t; i++) f[j][i] = f[f[j][i - 1]][i - 1];
			q.push(j);
		}
		if (R[now]) {
			int j = R[now];
			d[j] = d[now] + 1;
			f[j][0] = now;
			for (int i = 1; i <= t; i++) f[j][i] = f[f[j][i - 1]][i - 1];
			q.push(j);
		}
	}
}

int lca(int x, int y)
{
	if (d[x] > d[y]) swap(x, y);
	for (int i = t; i >= 0; i--) {
		if (d[f[y][i]] >= d[x]) y = f[y][i];
	}
	if (x == y) return x;
	for (int i = t; i >= 0; i--) {
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> in[i], in[i] = mapping(in[i]);
	for (int i = 1; i <= n; i++) cin >> pre[i], pre[i] = mapping(pre[i]);
	int root = build(1, n, 1, n);
	t = log(cnt) / log(2) + 1;
	bfs(root);
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (!s.count(a) && !s.count(b)) {
			cout << "ERROR: " << a << " and " << b << " are not found.\n";
		}
		else if (!s.count(a)) {
			cout << "ERROR: " << a << " is not found.\n";
		}
		else if (!s.count(b)) {
			cout << "ERROR: " << b << " is not found.\n";
		}
		else {
			int res = s2[lca(mapping(a), mapping(b))];
			if (res == a) cout << a << " is an ancestor of " << b << ".\n";
			else if (res == b) cout << b << " is an ancestor of " << a << ".\n";
			else {
				cout << "LCA of " << a << " and " << b << " is " << res << ".\n";
			}
		}
	}
    return 0;
}