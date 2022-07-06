#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +7;
int n;
int tr[N], a[N], b[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) add(i, 1);
    for (int i = n; i >= 1; i--) {
        int res = a[i] + 1;
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (sum(mid) >= res) r = mid;
            else l = mid + 1;
        }
        b[i] = r;
        add(r, -1);
    }
    for (int i = 1; i <= n; i++) cout << b[i] << "\n";
    return 0;
}