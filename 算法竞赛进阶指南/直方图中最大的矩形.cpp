#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll n, h[N], w[N], q[N];

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n, n)
    {
        ll res = 0, t = -1;
        h[n + 1] = 0;
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 1; i <= n + 1; i++)
        {
            int width = 0;
            while (t >= 0 && q[t] > h[i]) 
            {
                width += w[t];
                res = max(res, q[t] * width);
                t--;
            }
            q[++t] = h[i];
            w[t] = width + 1;
        }
        cout << res << "\n";
    }
    return 0;
}