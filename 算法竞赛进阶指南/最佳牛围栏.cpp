#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, l;
double a[N], s[N];

bool check(double x)
{
    for (int i = 1; i <= n; i++) s[i] = a[i] - x + s[i - 1];
    double val = 1e9, res = -1e9;
    for (int i = l; i <= n; i++)
    {
        val = min(val, s[i - l]);
        res = max(res, s[i] - val);
    }
    if (res >= 0) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> l;
    for (int i = 1; i <= n; i++) cin >> a[i];
    double l = 1, r = 2000;
    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << int(r * 1000) << "\n";
    return 0;
}