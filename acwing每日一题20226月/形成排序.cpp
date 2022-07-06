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
int t, n;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> t; for (int T = 1; T <= t; T++) {
		map<string, string> s;
		map<string, int> d;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			s[str1] = str2;
			d[str2]++;
		}
		string str = "";
		for (auto e : s) {
			if (d[e.x] == 0) {
				str = e.x;
				break;
			}
		}
		cout << "Case #" << T << ": ";
		while (s.count(str)) {
			cout << str << "-" << s[str] << " ";
			str = s[str];
		}
		cout << "\n";
	}
    return 0;
}