#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 7;
int n, m, q[N];
ll s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
    int h = 1, t = 1;
    q[1] = 0;
    ll res = -1e18;
    for (int i = 1; i <= n; i++)
    {
        while (h <= t && i - q[h] > m) h++;
        res = max(res, s[i] - s[q[h]]);
        while (h <= t && s[q[t]] > s[i]) t--;
        q[++t] = i;
    }
    cout << res << "\n";
    return 0;
}