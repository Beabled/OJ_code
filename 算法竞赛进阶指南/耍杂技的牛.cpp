#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
typedef long long ll;
const int N = 5e4 + 7;
int n;
pii a[N];

bool cmp(pii x, pii y)
{
    return x.x + x.y < y.x + y.y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    sort(a, a + n, cmp);
    ll res = -a[0].y, now = a[0].x;
    for (int i = 1; i < n; i++) res = max(res, now - a[i].y), now += a[i].x;
    cout << res << "\n";
    return 0;
}