#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;
int n, a[N];
ll res, s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    for (int i = 1; i <= n; i++) a[i] -= sum, a[i] += a[i - 1];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) res += abs(a[i] - a[(n + 1) / 2]);
    cout << res << "\n";
    return 0;
}