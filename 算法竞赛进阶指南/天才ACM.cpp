#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
int t, n, m;
ll T;
ll q[N], tmp[N];

ll get(int l, int r)
{
    int k = 0;
    for (int i = l; i < r; i++) tmp[k++] = q[i];
    sort(tmp, tmp + k);
    ll sum = 0;
    for (int i = 0; i < m && i < k; i++, k--) 
        sum += ((tmp[i] - tmp[k - 1]) * (tmp[i] - tmp[k - 1]));
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> T;
        for (int i = 1; i <= n; i++) cin >> q[i];
        int res = 0;
        int l = 1, r = 1;
        while (r <= n)
        {
            int p = 1;
            while (p)
            {
                if (r + p <= n + 1 && get(l, r + p) <= T) r += p, p *= 2;
                else p /= 2;
            }
            l = r;
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}