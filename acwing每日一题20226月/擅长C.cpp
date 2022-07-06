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
char g[30][8][6], res[8][100100];
string s;

int main() 
{
	/*ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);*/
	for (int i = 1; i <= 26; i++)
		for (int x = 1; x <= 7; x++)
			cin >> g[i][x] + 1;
	getchar();
	getline(cin, s);
	int cnt = 0;
	bool f = true;
	for (auto e : s) {
		if (e >= 'A' && e <= 'Z') {
			cnt++;
			int k = e - 'A' + 1;
			for (int i = 1; i <= 7; i++)
			    for (int j = (cnt - 1) * 5 + 1, y = 1; j <= cnt * 5; j++, y++)
					res[i][j] = g[k][i][y];
		}
		else {
			if (!cnt) continue;
			if (f) f = false;
			else cout << "\n";
			for (int j = 1; j <= 7; j++) {
				for (int i = 1; i <= cnt * 5; i++) {
				    cout << res[j][i];
				    if (i % 5 == 0 && i != cnt * 5) cout << " ";
				}
				cout << "\n";
			}
			cnt = 0;
		}
	}
	if (cnt) {
	    if (!f) cout << "\n";
	    for (int j = 1; j <= 7; j++) {
			for (int i = 1; i <= cnt * 5; i++) {
			    cout << res[j][i];
			    if (i % 5 == 0 && i != cnt * 5) cout << " ";
			}
			cout << "\n";
		}
	}
    return 0;
}