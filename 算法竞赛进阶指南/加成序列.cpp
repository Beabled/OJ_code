#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, a[N];

bool dfs(int u, int deep)
{
    if (u == deep) return a[u] == n;
    bool st[N] = {0};
    for (int i = u; i >= 1; i--)
        for (int j = i; j >= 1; j--) {
            int s = a[i] + a[j];
            if (s > n || s <= a[u] || st[s]) continue;
            st[s] = true;
            a[u + 1] = s;
            if (dfs(u + 1, deep)) return true;
        }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n, n) {
        a[1] = 1;
        int t = 1;
        while (!dfs(1, t)) t++;
        for (int i = 1; i <= t; i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}