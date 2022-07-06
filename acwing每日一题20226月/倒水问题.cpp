#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define x first
#define y second
const int inf = 0x3f3f3f3f;
int a, b, c;
set<pii> s;
set<int> res;

void dfs(int x, int y, int v)
{
    if (s.count({x, y})) return;
    s.insert({x, y});
    res.insert(v);
	if (x) {
	    dfs(x - min(x, b - y), y + min(x, b - y), v);
	    dfs(x - min(x, c - v), y, v + min(x, c - v));
	}
	if (y) {
	    dfs(x + min(y, a - x), y - min(y, a - x), v);
	    dfs(x, y - min(y, c - v), v + min(y, c - v));
	}
	if (v) {
	    dfs(x + min(v, a - x), y, v - min(v, a - x));
	    dfs(x, y + min(v, b - y), v - min(v, b - y));
	} 
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	while (cin >> a >> b >> c) {
		s.clear();res.clear();
		dfs(0, 0, c);
		cout << res.size() << "\n";
	}
    return 0;
}