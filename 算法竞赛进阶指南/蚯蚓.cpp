#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7, M = 7e6 + 7;
int n, m, q, u, v, t;
int q1[M], q2[M], q3[M], t1, t2, t3, h1, h2, h3;
priority_queue<ll> qd;
int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--) q1[++t1] = a[i];
    ll detal = 0;
    for (int i = 1; i <= m; i++)
    {
        int c1 = -1e9, c2 = -1e9, c3 = -1e9;
        int x = detal;
        if (t1 > h1) c1 = q1[h1 + 1];
        if (t2 > h2) c2 = q2[h2 + 1];
        if (t3 > h3) c3 = q3[h3 + 1];
        if (c1 >= c2 && c1 >= c3) x += c1, h1++;
        else if (c2 >= c1 && c2 >= c3) x += c2, h2++;
        else x += c3, h3++;
        if (i % t == 0) cout << x << " ";
        detal += q;
        int y = (ll)x * u / v;
        x -= y;
        x -= detal, y -= detal;
        q2[++t2] = x, q3[++t3] = y;
    }
    cout << "\n";
    int k = 1;
    while (t1 > h1 || t2 > h2 || t3 > h3)
    {
        int c1 = -1e9, c2 = -1e9, c3 = -1e9;
        ll x = detal;
        if (t1 > h1) c1 = q1[h1 + 1];
        if (t2 > h2) c2 = q2[h2 + 1];
        if (t3 > h3) c3 = q3[h3 + 1];
        if (c1 >= c2 && c1 >= c3) x += c1, h1++;
        else if (c2 >= c1 && c2 >= c3) x += c2, h2++;
        else x += c3, h3++;
        if (k % t == 0) cout << x << " ";
        k++;
    }
    return 0;
}