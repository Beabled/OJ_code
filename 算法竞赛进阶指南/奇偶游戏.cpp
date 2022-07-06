#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e4 + 7;
int n, m, f[N], d[N], cnt;
vector<pii> eps;
unordered_map<int, int> s;

int mapping(int x)
{
    if (s.count(x)) return s[x];
    return s[x] = ++cnt;
}

int find(int x)
{
    if (x == f[x]) return x;
    int root = find(f[x]);
    d[x] ^= d[f[x]];
    return f[x] = root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int res = m;
    for (int i = 1; i <= 1e4; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y;
        string g;
        cin >> x >> y >> g;
        x = mapping(x - 1), y = mapping(y);
        int c = 0;
        if (g[0] == 'o') c = 1;
        else c = 0;
        int p = find(x), q = find(y);
        if (p == q) {
            if ((d[x] ^ d[y]) != c) {
                cout << i - 1;
                return 0;
            }
        } 
        else {
            f[p] = q;
            d[p] = d[x] ^ d[y] ^ c;
        }
    }
    cout << res << "\n";
    return 0;
}