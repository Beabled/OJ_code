#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1010;
int n, m, a, b, Q;
ull f[N][N], p[N];
char g[N];
map<ull, ull> s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> a >> b;
    p[0] = 1;
    for (int i = 1; i <= n * m; i++) {
        p[i] = p[i - 1] * 131;
    }
    for (int i = 1; i <= n; i++) {
        cin >> g + 1;
        for (int j = 1; j <= m; j++) f[i][j] = f[i][j - 1] * 131 + g[j] - '0';
    }
    for (int i = b; i <= m; i++) {
        ull res = 0;
        int l = i - b + 1, r = i;
        for (int j = 1; j <= n; j++) {
            res = res * p[b] + f[j][r] - f[j][l - 1] * p[r - l + 1];
            if (j - a > 0) res -= (f[j - a][r] - f[j - a][l - 1] * p[r - l + 1]) * p[a * b];
            if (j >= a) s[res]++;
        }
    }
    cin >> Q;
    while (Q--) {
        //getchar();
        char x;
        ull res = 0;
        for (int i = 1; i <= a; i++)
        {
            cin >> g + 1;
            for (int j = 1; j <= b; j++) res = res * 131 + g[j] - '0';
        }
        if (s[res]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}