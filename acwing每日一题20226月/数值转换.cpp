#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define x first
#define y second
const int inf = 0x3f3f3f3f;
ll a, b;
string s;
int st[300];

int main() 
{
	for (char i = '0'; i <= '9'; i++) st[i] = i - '0';
	for (int i = 10; i <= 16; i++) st[i - 10 + 'a'] = i, st[i - 10 + 'A'] = i;
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> a >> s >> b;
	ll res = 0;
	for (int i = 0; i < s.size(); i++) {
		res = res * a + st[s[i]]; 
	}
	vector<int> r;
	while (res) {
		if (res % b >= 10) r.push_back(res % b - 10 + 'A');
		else r.push_back(res % b);
		res /= b;
	}
	reverse(r.begin(), r.end());
	for (auto e: r) {
		if (e >= 10) cout << char(e);
		else cout << e;
	}
    return 0;
}