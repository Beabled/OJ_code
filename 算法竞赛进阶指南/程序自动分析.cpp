#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n;
int t;
unordered_map<int, int> s;
int f[N * 2], cnt;
vector<pair<int, int>> eps, uneps;

int mapping(int x)
{
    if (s.count(x)) return s[x];
    return s[x] = ++cnt;
}

int find(int x)
{
    int a = x;
    while (x != f[x]) x = f[x];
    while (a != f[a]) {
        int z = a;
        a = f[a];
        f[z] = x;
    }
    return x;
}

void add(int x, int y) 
{
    f[find(x)] = find(y);
}

void solve()
{
    eps.clear();
    uneps.clear();
    cnt = 0;
    s.clear();
    cin >> n;
    while (n--) {
        int i, j, e;
        cin >> i >> j >> e;
        i = mapping(i), j = mapping(j);
        if (e) eps.push_back({i, j});
        else uneps.push_back({i, j});
    }
    for (int i = 1; i <= cnt; i++) f[i] = i;
    for (auto e: eps) add(e.first, e.second);
    for (auto e: uneps) 
        if (find(e.first) == find(e.second)) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) solve();
    return 0;
}