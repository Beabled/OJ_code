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
const int N = 2e5 + 7;
int t, a[N], n;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> t; for (int T = 1; T <= t; T++) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int res = 1;
		for (int i = 1; i <= n - 1; i++) {
			int x = a[i] - a[i + 1];
			int j = i + 1, now = 2;
			while (j <= n - 1 && a[j] - a[j + 1] == x) {
				j++, now++;
			}
			i = j - 1;
			res = max(res, now);
		}
		cout << "Case #" << T << ": " << res << "\n";
	}
    return 0;
}