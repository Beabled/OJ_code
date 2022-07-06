#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 7;
int n, k, f[N], d[N];

int find(int x)
{
    if (x == f[x]) return x;
    int root = find(f[x]);
    d[x] += d[f[x]];
    return f[x] = root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) f[i] = i;
    int res = 0;
    for (int i = 1; i <= k; i++) {
        int x, y, t;
        cin >> t >> x >> y;
        if (x > n || y > n) res++;
        else {
            int fx = find(x), fy = find(y);
            if (t == 1) {
                if (fx == fy && (d[x] - d[y]) % 3) res++;
                else if (fx != fy) {
                    f[fx] = fy;
                    d[fx] = d[y] - d[x];
                }
            }
            else {
                if (fx == fy && (d[x] - d[y] - 1) % 3) res++;
                else if (fx != fy) {
                    f[fx] = fy;
                    d[fx] = d[y] - d[x] + 1;
                }
            }
        }
    }
    cout << res << "\n";
    return 0;
}