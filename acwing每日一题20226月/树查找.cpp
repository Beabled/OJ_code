#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define x first
#define y second
const int inf = 0x3f3f3f3f;
const int N = 1010;
int n, k, a[N];
vector<int> res[N];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	queue<pii> q;
	q.push({1, 1});
	while (q.size()) {
		auto now = q.front(); q.pop();
		res[now.y].push_back(a[now.x]);
		if ((now.x << 1) <= n) q.push({now.x << 1, now.y + 1});
		if ((now.x << 1 | 1) <= n) q.push({now.x << 1 | 1, now.y + 1});
	}
	cin >> k;
	if (!res[k].size()) cout << "EMPTY\n";
	for (auto e : res[k]) cout << e << " ";
    return 0;
}