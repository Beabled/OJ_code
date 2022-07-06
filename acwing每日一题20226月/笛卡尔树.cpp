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
const int N = 50;
int a[N], n;
vector<int> res[N];

int get_min(int l, int r)
{
	int res = l;
	for (int i = l; i <= r; i++)
		if (a[i] < a[res]) res = i;
	return res;
}

void dfs(int l, int r, int d)
{
	if (l > r) return;
	int root = get_min(l, r);
	res[d].push_back(a[root]);
	dfs(l, root - 1, d + 1);
	dfs(root + 1, r, d + 1);
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(1, n, 1);
	for (int i = 1; i <= n; i++)
		for (auto e : res[i]) cout << e << " ";
    return 0;
}