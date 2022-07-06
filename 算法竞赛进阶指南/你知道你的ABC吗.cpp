#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10;
ll a[N], b[N];
bool st[N], f;

void dfs(int u)
{
    if (u == 8) {
        if (b[4] == b[1] + b[2] && b[5] == b[2] + b[3] && b[6] == b[1] + b[3] && b[7] == b[1] + b[2] + b[3] && b[3] >= b[2] && b[2] >= b[1]) {
            cout << b[1] << " " << b[2] << " " << b[3] << "\n";
            f = true;
        }
        return;
    }
    for (int i = 1; i <= 7; i++) {
        if (f) return;
        if (!st[i]) {
            st[i] = true;
            b[u] = a[i];
            dfs(u + 1);
            st[i] = false;
        }
    }
}

int main()
{
    for (int i = 1; i <= 7; i++) cin >> a[i];
    dfs(1);
    return 0;
}