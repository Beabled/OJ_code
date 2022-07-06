#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 7;
int t, f[N], d[N], s[N];

int find(int x)
{
    if (x == f[x]) return x;
    int root = find(f[x]);
    d[x] += d[f[x]];
    return f[x] = root;
}

void merge(int x, int y)
{
    x = find(x), y = find(y);
    f[x] = y, d[x] = s[y];
    s[y] += s[x];
}

int main()
{
    for (int i = 1; i <= 30000; i++) f[i] = i, s[i] = 1;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> t; while (t--) {
        string S;
        int i, j;
        cin >> S >> i >> j;
        if (S == "M") {
            if (find(i) != find(j)) merge(i, j);
        }
        else {
            if (find(i) == find(j)) cout << max(0, abs(d[i] - d[j]) - 1) << "\n";
            else cout << -1 << "\n";
        }
    }
    return 0;
}