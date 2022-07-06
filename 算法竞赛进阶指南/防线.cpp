#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
struct node {
    int s, e, d;
}q[N];

int t, n;

int get_sum(int x)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (q[i].s <= x) res += ((min(x, q[i].e) - q[i].s) / q[i].d + 1);
    return res;
}

bool check(int l, int r)
{
    return (get_sum(r) - get_sum(l - 1)) & 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int minl = 1e9, maxd = -1e9;
        cin >> n;
        for (int i = 1; i <= n; i++) 
        {
            cin >> q[i].s >> q[i].e >> q[i].d;
            minl = min(minl, q[i].s);
            maxd = max(maxd, q[i].e);
        }
        if (!(get_sum(maxd) & 1)) cout << "There's no weakness.\n";
        else 
        {
            int l = minl, r = maxd;
            while (l <= r)
            {
                int mid = l + r >> 1;
                if (check(l, mid)) r = mid - 1;
                else l = mid + 1;
            }
            cout << l << " " << get_sum(l) - get_sum(l - 1) << "\n";
        }
    }
    return 0;
}
