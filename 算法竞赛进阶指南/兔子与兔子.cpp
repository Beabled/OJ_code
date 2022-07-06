#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1e6 + 7;
int m;
char s[N];
ull f[N], p[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> s + 1 >> m;
    int n = strlen(s + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * 13331 + (s[i] - 'a' + 1);
        p[i] = p[i - 1] * 13331;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        ull res = f[r] - f[l - 1] * p[r - l + 1];
        cin >> l >> r;
        if (res == f[r] - f[l - 1] * p[r - l + 1]) {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }
    return 0;
}