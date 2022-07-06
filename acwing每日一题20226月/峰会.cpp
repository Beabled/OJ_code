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
const int N = 220;
int n, m, k;
int f[N][N], q[N];

int main() 
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		f[a][b] = 1, f[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) f[i][i] = 1;
	cin >> k;
	for (int p = 1; p <= k; p++) {
		int x, cnt = 0;
		cin >> x;
		map<int, int> s;
		for (int i = 1; i <= x; i++) cin >> q[++cnt], s[q[cnt]] = 1;
		bool check = true, check1 = false;
		int mi;
		for (int i = 1; i <= cnt; i++) {
			for (int j = 1; j <= cnt; j++)
				if (f[q[i]][q[j]] != 1 || f[q[j]][q[i]] != 1) {
				    check = false;
				}
		}
		for (int i = 1; i <= n; i++) {
			if (!s[i]) {
				int g = 0;
				for (int j = 1; j <= x; j++)
					if (f[i][q[j]] == 1 && f[q[j]][i] == 1) {
                        g++;
					}
				if (g == x) {
				    mi = i;
				    check1 = true;
				    break;
				}
			}
			if (check1) break;
		}
		if (!check) cout << "Area " << p << " needs help.\n";
		else {
			if (check1) printf("Area %d may invite more people, such as %d.\n", p, mi);
			else printf("Area %d is OK.\n", p);
		}
	}
    return 0;
}