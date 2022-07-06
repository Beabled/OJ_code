#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int n, a[N];
ll great[N], low[N];
int tr[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int v)
{
    for (int i = x; i <= N - 7; i += lowbit(i)) tr[i] += v;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int j = a[i];
        great[i] = sum(n) - sum(j - 1);
        low[i] = sum(j - 1);
        add(j, 1);
    }
    memset(tr, 0, sizeof tr);
    ll res1 = 0, res2 = 0;
    for (int i = n; i; i--) {
        int j = a[i];
        res1 += (ll)great[i] * (sum(n) - sum(j - 1));
        res2 += (ll)low[i] * (sum(j - 1));
        add(j, 1);
    }
    cout << res1 << " " << res2 << "\n";
    return 0;
}