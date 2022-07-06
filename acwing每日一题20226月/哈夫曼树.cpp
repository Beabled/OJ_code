#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define x first
#define y second
const int inf = 0x3f3f3f3f;
int n;
priority_queue<int, vector<int>, greater<int>> q;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1, x; i <= n; i++) cin >> x, q.push(x);
	int res = 0;
	while (q.size() >= 2) {
		int x = q.top(); q.pop();
		int y = q.top(); q.pop();
		q.push(x + y);
		res += x + y;
	} 
	cout << res << "\n";
    return 0;
}