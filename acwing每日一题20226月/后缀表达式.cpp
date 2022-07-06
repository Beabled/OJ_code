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
const int N = 25;
int n;
struct node {
	string s;
	int l, r;
}a[N];
vector<char> res;
bool st[N];
map<string, int> o;

void dfs(int u)
{
	res.push_back('(');
	if (o[a[u].s] == 1 && (a[u].l == -1 || a[u].r == -1)) {
		res.push_back(a[u].s[0]);
		if (a[u].l != -1) dfs(a[u].l);
		if (a[u].r != -1) dfs(a[u].r);
	}
	else {
		if (a[u].l != -1) dfs(a[u].l);
		if (a[u].r != -1) dfs(a[u].r);
		for (auto e : a[u].s) res.push_back(e);
	}
	res.push_back(')');
}

int main() 
{
	o["+"] = o["-"] = 1;
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1, l, r; i <= n; i++) {
		string s;
		cin >> s >> l >> r;
		a[i] = {s, l, r};
		if (l != -1) st[l] = 1;
		if (r != -1) st[r] = 1;
	}
	int root = 1;
	for (int i = 1; i <= n; i++)
		if (!st[i]) {
			root = i;
			break;
		}
	dfs(root);
	for (auto e : res) cout << e;
	cout << "\n";
    return 0;
}