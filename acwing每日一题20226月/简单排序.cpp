#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define x first
#define y second
const int inf = 0x3f3f3f3f;
const int N = 1010;
int n;
vector<int> res;
int st[N];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		if (!st[x]) st[x]++, res.push_back(x);
	} 
	sort(res.begin(), res.end());
	for (auto e : res) cout << e << " ";
    return 0;
}