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
int n, m, res;

void dfs(int u, int sum, int pan)
{
	if (!u) {
		if (!sum) res++;
		return;
	}
	for (int i = 0; i <= pan; i++) {
		if (u * i <= sum) {
			dfs(u - 1, sum - u * i, pan - i);
		}
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	while (cin >> m >> n) {
	    res = 0;
	    dfs(m, m, n);   
	    cout << res << "\n";
	}
	return 0;
}