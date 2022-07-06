#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int n, m;
ll tr[N];
int a[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, ll v)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

ll sum(int x)
{
    ll res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m--) {
        string s;
        int x, y, v;
        cin >> s;
        if (s == "Q") {
            cin >> x;
            cout << a[x] + sum(x) << "\n";
        }
        else {
            cin >> x >> y >> v;
            add(x, v), add(y + 1, -v);
        }
    }
    return 0;
}