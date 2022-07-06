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
const int N = 1010;
int t, s, q;
int g[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int st[N][N];

int dfs(int x, int y)
{
	if (st[x][y]) return st[x][y];
	int &r = st[x][y];
	r++;
	for (int i = 0; i < 4; i++) {
		int a = x + dx[i], b = y + dy[i];
		if (a >= 1 && a <= s && b >= 1 && b <= s && g[a][b] - g[x][y] == 1) {
		    r += dfs(a, b);
		}
	}
	return r;
}

void solve()
{
	pii res;
	cin >> s;
	rep(i, 1, s) 
		rep(j, 1, s)
			cin >> g[i][j], st[i][j] = 0;
	rep(i, 1, s)
		rep(j, 1, s) {
			int x = dfs(i, j);
			if (x > res.x) res = {x, g[i][j]};
			else if (x == res.x && g[i][j] < res.y) res.y = g[i][j];
		}
	cout << "Case #" << ++q << ": " << res.y << " " << res.x << "\n";
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> t; while (t--) solve();
    return 0;
}