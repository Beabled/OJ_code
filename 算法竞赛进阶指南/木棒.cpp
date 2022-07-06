#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, a[N], v[N], cnt, len;

bool dfs(int stick, int cab, int last)
{
    if (stick > cnt) return true;
    if (cab == len) return dfs(stick + 1, 0, 1);
    int fail = 0;
    for (int i = last; i <= n; i++) {
        if (!v[i] && a[i] + cab <= len && fail != a[i]) {
            v[i] = 1;
            if (dfs(stick, cab + a[i], i + 1)) return true;
            fail = a[i];
            v[i] = 0;
            if (!cab || cab + a[i] == len) return false;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n, n) {
        int ma = 0, sum = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], ma = max(ma, a[i]), sum += a[i];
        sort(a + 1, a + 1 + n);
        reverse(a + 1, a + 1 + n);
        for (len = ma; len <= sum; len++) {
            if (sum % len) continue;
            cnt = sum / len;
            memset(v, 0, sizeof v);
            if (dfs(1, 0, 0)) break;
        }
        cout << len << "\n";
    }
    return 0;
}