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
const int N = 1e5 + 7;
int n, k, h, t;
struct node { int id, v, ne; };
map<int, int> ne, pre;
node a[N], q[N];
vector<node> res;

int main() 
{
	cin >> h >> n >> k;
	for (int i = 1; i <= n; i++) {
		int id, v, ne;
		cin >> id >> v >> ne;
		a[id] = {id, v, ne};
	}
	while (h != -1) q[++t] = a[h], h = a[h].ne;
	n = t;
	int c = n % k;
	if (c) {
		for (int i = n - c + 1; i <= n; i++) {
			printf("%05d %d", q[i].id, q[i].v);
			if (i == n) {
				if (c == n) printf(" -1\n");
				else printf(" %05d\n", q[n - c + 1 - k].id);
			}
			else printf(" %05d\n", q[i + 1].id);
		}
		n -= c;
	}
	for (int i = n - k + 1; i >= 1; i -= k)
		for (int j = i; j <= i + k - 1; j++) {
			printf("%05d %d", q[j].id, q[j].v);
			if (j == i + k - 1) {
				if (i == 1) printf(" -1\n");
				else printf(" %05d\n", q[i - k].id);
			}
			else printf(" %05d\n", q[j + 1].id);
		}
    return 0;
}