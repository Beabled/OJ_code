#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e6 + 7;
int n, m, q, x;
char a[N], b[N];
ull fa[N], fb[N], p[N];
map<int, int> s;

bool check(int mid, int i) 
{
    return fa[i + mid - 1] - fa[i - 1] * p[mid] == fb[mid] - fb[0] * p[mid];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    cin >> a + 1 >> b + 1;
    p[0] = 1;
    for (int i = 1; i <= n + m; i++) p[i] = p[i - 1] * 131;
    for (int i = 1; i <= n; i++) fa[i] = fa[i - 1] * 131 + a[i] - 'a';
    for (int i = 1; i <= m; i++) fb[i] = fb[i - 1] * 131 + b[i] - 'a';
    for (int i = 1; i <= n; i++) {
        int l = 0, r = min(n - i + 1, m);
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid, i)) l = mid;
            else r = mid - 1;
        }
        s[r]++;
    }
    while (q--) {
        cin >> x;
        cout << s[x] << "\n";
    }
    return 0;
}