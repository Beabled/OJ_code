#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
int t, n, res, ma;
ll b[N] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void dfs(int u, int last, int sum, int now)
{
    if (sum > ma || sum == ma && now < res) {
        ma = sum, res = now;
    }
    for (int i = 1; i <= last; i++) {
        if (now * b[u] > n) break;
        now *= b[u];
        dfs(u + 1, i, sum * (i + 1), now);
    }
}

int main()
{
    cin >> n;
    dfs(1, 30, 1, 1);
    cout << res << "\n";
    return 0;
}