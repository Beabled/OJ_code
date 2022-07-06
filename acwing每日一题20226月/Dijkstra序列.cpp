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
const int N = 1e3 + 7, M = 2e5 + 7;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dis[N], a[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(int x)
{
	memset(dis, 0x3f, sizeof dis);
	memset(st, false, sizeof st);
	dis[x] = 0;
	st[x] = 0;
	for (int i = 1; i <= n; i++) {
		int t = a[i];
		st[t] = true;
		for (int j = 1; j <= n; j++) 
			if (!st[a[j]] && dis[a[j]] < dis[t])
				return false;
		for (int j = h[t]; j != -1; j = ne[j]) {
			int k = e[j];
			if (dis[k] > dis[t] + w[j]) dis[k] = dis[t] + w[j];
		}
	}
	return 1;
}

int main() 
{
	memset(h, -1, sizeof h);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	int k;
	cin >> k;
	while (k--) {
		for (int i = 1; i <= n; i++) cin >> a[i];
		cout << (dijkstra(a[1]) ? "Yes\n" : "No\n");
	}
    return 0;
}